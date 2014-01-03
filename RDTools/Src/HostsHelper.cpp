//#include "stadfx.h"
#include "HostsHelper.h"

#include <Windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

#include "..\thirdparty\StringTokenizer\StringTokenizer.h"

#pragma warning(push)
#pragma warning(disable:4996)

const char * const kSectionTag = "#Section";
const char * const kCommentTag = "#Comment";
const char * const kDefaultName = "Hosts's Item";
const char * const kDefaultDesc = "Add by HostParser";

CHostsHelper::CHostsHelper()
{
	pHosts = NULL;
	nCount = 0;
}

CHostsHelper::~CHostsHelper()
{
	if(pHosts)
	{
		LPHOSTS_INFO pHeader = pHosts;
		LPHOSTS_ITEM pItem = NULL;
		while(pHosts)
		{
			pHeader = pHosts;
			pHosts = pHosts->pNext;
			while(pHeader->pItem)
			{
				pItem = pHeader->pItem;
				pHeader->pItem = pHeader->pItem->pNext;
				free(pItem);
			}
			free(pHeader);
		}
	}
}

bool CHostsHelper::Load(const char* pszHosts /*= NULL*/)
{
	bool bRet = false;
	char szSystem[1024] = {0};
	if(pszHosts)
	{
		strcpy(szSystem, pszHosts);
	}
	else
	{
		GetSystemDirectoryA(szSystem, _countof(szSystem));
		strcat(szSystem, "\\drivers\\etc\\hosts");
	}
	FILE *pFile = fopen(szSystem, "r");
	if(!pFile)
		return bRet;
	fseek(pFile, 0, SEEK_END);
	DWORD dwSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char *pData = (char *)malloc(dwSize+1);
	if(!pData)
	{
		fclose(pFile);
		return bRet;
	}
	memset(pData, 0, dwSize);
	fread(pData, 1, dwSize, pFile);
	pData[dwSize] = '\0';

	Parse(pData, "\n");

	free(pData);
	fclose(pFile);
	return true;
}

bool CHostsHelper::Parse(const char* pszStr, const char* pszDelim)
{
	StringTokenizer strData = StringTokenizer(pszStr, pszDelim);
	std::string strTemp = "";
	std::string strSection, strComment;
	std::string strSectionTag, strCommentTag;
	pHosts = (LPHOSTS_INFO)malloc(sizeof(HOSTS_INFO));
	if(!pHosts)
		return false;
	LPHOSTS_INFO pTail = pHosts;
	LPHOSTS_ITEM pItem = NULL;
	memset(pTail, 0, sizeof(HOSTS_INFO));
	bool bHeaderEnd = false;
	int nTokensCount = strData.countTokens();
	for(int i = 0; i < nTokensCount; i++)
	{
		strTemp = strData.nextToken();
		strSectionTag.assign(strTemp.c_str(), strlen(kSectionTag));
		strCommentTag.assign(strTemp.c_str(), strlen(kCommentTag));
		if(strTemp[0] == '#' && !bHeaderEnd)
		{
			if(strSectionTag!=kSectionTag) // hosts's Coment
			{
				strHeader += strTemp;
				strHeader += "\n";
				strSectionTag = "";
				strCommentTag = "";
				continue;
			}
		}

		bHeaderEnd = true;
		if(strSectionTag==kSectionTag || (strTemp[0] == '#' && bHeaderEnd)) // hosts item section's name
		{
			if(strstr(strTemp.c_str(), kSectionTag))
				strSection.assign(strTemp.c_str(), strlen(kSectionTag)+1, strTemp.length());
			else
				strSection.assign(strTemp.c_str(), 1, strTemp.length());
			if(pTail->pItem)
			{
				pTail->pNext = (LPHOSTS_INFO)malloc(sizeof(HOSTS_INFO));
				pTail = pTail->pNext;
				memset(pTail, 0, sizeof(HOSTS_INFO));
			}
			nCount++;
			strcpy(pTail->szSection, strSection.c_str());
		}
		else if(strCommentTag==kCommentTag) // host item's comment
		{
			strComment.assign(strTemp.c_str(), strlen(kCommentTag)+1, strTemp.length());
			if(strlen(pTail->szSection)==0)
				nCount++;
			strcpy(pTail->szDesc, strComment.c_str());
		}
		else // hosts item
		{
			if(strlen(pTail->szSection)==0 && strlen(pTail->szDesc)==0)
			{
				nCount++;
				strcpy(pTail->szSection, kDefaultName);
				strcpy(pTail->szDesc, kDefaultDesc);
			}
			if(!pTail->pItem)
			{
				pTail->pItem = (LPHOSTS_ITEM)malloc(sizeof(HOSTS_ITEM));
				memset(pTail->pItem, 0, sizeof(HOSTS_ITEM));
				pItem = pTail->pItem;
			}
			else if(strlen(pItem->szAddr))
			{
				LPHOSTS_ITEM pNewItem = (LPHOSTS_ITEM)malloc(sizeof(HOSTS_ITEM));
				memset(pNewItem, 0, sizeof(HOSTS_ITEM));
				pItem->pNext = pNewItem;
				pItem = pNewItem;
			}
			pTail->nCount++;
			StringTokenizer strItem = StringTokenizer(strTemp, " ");
			std::string strAddr = strItem.nextToken();
			std::string strDomain = strItem.nextToken();
			std::string strDesc = strItem.nextToken();
			strcpy(pItem->szAddr, strAddr.c_str());
			strcpy(pItem->szDomain, strDomain.c_str());
			strcpy(pItem->szDesc, strDesc.c_str());
		}

		strSection = "";
		strComment = "";
		strSectionTag = "";
		strCommentTag = "";
	}
	return true;
}

LPHOSTS_INFO CHostsHelper::FindSection(const char* pszSection)
{
	if(!pHosts)
		return NULL;
	LPHOSTS_INFO pSection =  pHosts;
	while(pSection)
	{
		if(stricmp(pSection->szSection, pszSection)==0)
			return pSection;
		pSection = pSection->pNext;
	}
	return NULL;
}

LPHOSTS_ITEM CHostsHelper::FindItem(const char* pszSection, const char* pszAddr)
{
	LPHOSTS_INFO pSection = NULL;
	LPHOSTS_ITEM pItem = NULL;
	if(pszSection)
	{
		pSection = FindSection(pszSection);
		if(!pSection)
			return NULL;
		pItem = pSection->pItem;
		while(pItem)
		{
			if(stricmp(pItem->szAddr, pszAddr)==0)
				return pItem;
			pItem = pItem->pNext;
		}
	}
	else
	{
		pSection = pHosts;
		while(pSection)
		{
			pItem = FindItem(pSection->szSection, pszAddr);
			if(pItem)
				return pItem;
			pSection = pSection->pNext;
		}
	}
	return NULL;
}

bool CHostsHelper::AddItem(const char* pszSection, const char* pszAddr, const char* pszDomain)
{
	LPHOSTS_INFO pSection = NULL;
	if(pszSection)
	{
		pSection = FindSection(pszSection);
		if(!pSection)
		{
			if(!AddSection(pszSection))
				return false;
		}
		LPHOSTS_ITEM pItem = pSection->pItem;
		while(pItem)
		{
			if(pItem->pNext)
				pItem = pItem->pNext;
		}
		LPHOSTS_ITEM pNewItem = (LPHOSTS_ITEM)malloc(sizeof(HOSTS_ITEM));
		if(!pNewItem)
			return false;
		memset(pNewItem, 0, sizeof(HOSTS_ITEM));
		strcpy(pNewItem->szAddr, pszAddr);
		strcpy(pNewItem->szDomain, pszDomain);
		pItem->pNext = pNewItem;
		return true;
	}
	else
	{
		if(AddItem(kDefaultName, pszAddr, pszDomain))
			return true;
	}

	return false;
}

bool CHostsHelper::AddSection(const char* pszSection)
{
	LPHOSTS_INFO pSection = NULL;
	pSection = (LPHOSTS_INFO)malloc(sizeof(HOSTS_INFO));
	memset(pSection, 0, sizeof(HOSTS_INFO));
	if(!pHosts)
	{
		pHosts = pSection;
	}
	else
	{
		LPHOSTS_INFO pTail = pHosts;
		while(pTail)
		{
			if(pTail->pNext)
				pTail = pTail->pNext;
		}
		pTail->pNext = pSection;
	}
	return true;
}

bool CHostsHelper::DelItem(const char* pszSection, const char* pszAddr)
{
	LPHOSTS_INFO pSection = NULL;
	LPHOSTS_ITEM pItem = NULL, pPrev = NULL;
	bool bRet = false;
	if(pszSection)
	{
		pSection = FindSection(pszSection);
		if(!pSection)
			return false;
		pItem = pSection->pItem;
		while(pItem)
		{
			if(stricmp(pItem->szAddr, pszAddr)==0)
			{
				bRet = true;
				break;
			}
			pPrev = pItem;
			pItem = pItem->pNext;
		}
		if(!bRet)
			return false;
		if(pItem)
		{
			if(!pPrev)
				pSection->pItem = pSection->pItem->pNext;
			else
				pPrev->pNext = pItem->pNext;
			pSection->nCount --;
			free(pItem);
		}
	}
	else
	{
		pSection = pHosts;
		while(pSection)
		{
			bRet = DelItem(pSection->szSection, pszAddr);
			if(bRet)
				return true;
			pSection = pSection->pNext;
		}
	}
	return false;
}

bool CHostsHelper::DelSection(const char* pszSection)
{
	if(!pHosts)
		return false;
	bool bRet = false;
	LPHOSTS_INFO pPrev = NULL;
	LPHOSTS_INFO pSection =  pHosts;
	while(pSection)
	{
		if(stricmp(pSection->szSection, pszSection)==0)
		{
			bRet = true;
			break;
		}
		pPrev = pSection;
		pSection = pSection->pNext;
	}
	if(!bRet)
		return false;
	if(pSection)
	{
		if(!pPrev)
			pHosts = pHosts->pNext;
		else
			pPrev->pNext = pSection->pNext;
		LPHOSTS_ITEM pItem = pSection->pItem;
		LPHOSTS_ITEM pTemp = NULL;
		while(pItem)
		{
			pTemp = pItem;
			pItem = pItem->pNext;
			free(pTemp);
		}
		free(pSection);
		return true;
	}
	return false;
}

bool CHostsHelper::ModifyItem(const char* pszSection, const char* pszAddr, const char* pszDomain)
{
	LPHOSTS_INFO pSection = NULL;
	LPHOSTS_ITEM pItem = NULL;
	if(pszSection)
	{
		pSection = FindSection(pszSection);
		if(!pSection)
			return false;
		pItem = pSection->pItem;
		while(pItem)
		{
			if(stricmp(pItem->szAddr, pszAddr)==0)
			{
				memset(pItem->szDomain, 0, sizeof(pItem->szDomain));
				strcpy(pItem->szDomain, pszDomain);
				return true;
			}
			pItem = pItem->pNext;
		}
	}
	else
	{
		pSection = pHosts;
		while(pSection)
		{
			if(ModifyItem(pSection->szSection, pszAddr, pszDomain))
				return true;
			pSection = pSection->pNext;
		}
	}
	return false;
}

bool CHostsHelper::Build(std::string &strContent)
{
	LPHOSTS_INFO pSection = pHosts;
	LPHOSTS_ITEM pItem = NULL;
	strContent = strHeader;
	strContent += "\n";
	while(pSection)
	{
		if(strlen(pSection->szSection))
		{
			strContent += kSectionTag;
			strContent += ":";
			strContent += pSection->szSection;
			strContent += "\n";
		}
		if(strlen(pSection->szDesc))
		{
			strContent += kCommentTag;
			strContent += ":";
			strContent += pSection->szDesc;
			strContent += "\n";
		}
		pItem = pSection->pItem;
		while(pItem)
		{
			strContent += pItem->szAddr;
			strContent += " ";
			strContent += pItem->szDomain;
			strContent += "\n";
			pItem = pItem->pNext;
		}
		strContent += "\n";
		pSection = pSection->pNext;
	}
	return true;
}

bool CHostsHelper::Save()
{
	if(!pHosts)
		return false;
	std::string strContent;
	Build(strContent);
	char szModule[1024] = {0};
	GetModuleFileNameA(NULL, szModule, _countof(szModule));
	PathRemoveFileSpecA(szModule);
	if(PathIsRootA(szModule))
		szModule[strlen(szModule)-1] = '\0';
	PathAppendA(szModule, "hosts");
	FILE *pFile = fopen(szModule, "w");
	if(!pFile)
		return false;
	fwrite(strContent.c_str(), 1, strContent.length(), pFile);
	fclose(pFile);
	return true;
}

bool CHostsHelper::SaveAs(const char* lpszPath)
{
	std::string strContent;
	Build(strContent);
	FILE *pFile = fopen(lpszPath, "w");
	if(!pFile)
		return false;
	fwrite(strContent.c_str(), 1, strContent.length(), pFile);
	fclose(pFile);
	return true;
}
#pragma warning(pop)