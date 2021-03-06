// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <Shlwapi.h>
#include <shlobj.h>
#include <Commdlg.h>
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "Comdlg32.lib")

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <process.h>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

using namespace std;

//////////////////////////////////////////////////////////////////////////
// 以下是第三方库类文件的引用
//////////////////////////////////////////////////////////////////////////

#include <OptParse/optparse.h>
#include <md5/md5.h>

#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>

#include <UCD/ucdetector.h>
#include <libiconv/Src/include/iconv.h>
#include <SlimXml/Src/SlimXml.h>
#include <StringTokenizer/StringTokenizer.h>
#include <GifLib/lib/gif_lib_private.h>
#include <DuiLib/UIlib.h>
#include <Tidy/include/tidy.h>
#include <Tidy/include/buffio.h>
#include <AsTidyLib/astyle.h>
#include <CssTidyLib/formatter.h>
#include <JsonTidyLib/json.h>
#include <JsonTidyLib/jsontidy.h>
#include <JsTidyLib/jstidy.h>
#include <PhpTidyLib/phptidy.h>
#include <SqlTidyLib/sqltidy.h>

#include <DuiMsg.h>
#include <FileFinder.h>
#include <RDNet.h>

using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace slim;
using namespace DuiLib;

// Link Lib
#ifdef _DEBUG
#pragma comment(lib, "../RongDian/log4cplusd.lib")
#pragma comment(lib, "../RongDian/pcred.lib")
#pragma comment(lib, "../RongDian/UCDd.lib")
#pragma comment(lib, "../RongDian/libiconvd.lib")
#pragma comment(lib, "../RongDian/SQLite.lib")
#pragma comment(lib, "../RongDian/SlimXmld.lib")
#pragma comment(lib, "../RongDian/Tidy.lib")
#pragma comment(lib, "../RongDian/AsTidyLibd.lib")
#pragma comment(lib, "../RongDian/CssTidyLibd.lib")
#pragma comment(lib, "../RongDian/JsonTidyLibd.lib")
#pragma comment(lib, "../RongDian/JsTidyLibd.lib")
#pragma comment(lib, "../RongDian/PhpTidyLibd.lib")
#pragma comment(lib, "../RongDian/SqlTidyLibd.lib")
#pragma comment(lib, "../RongDian/DuiLibd.lib")
#pragma comment(lib, "../RongDian/DuiMsgd.lib")
#pragma comment(lib, "../RongDian/RDFinderd.lib")
#pragma comment(lib, "../RongDian/RDNetd.lib")
#else
#pragma comment(lib, "../RongDian/log4cplus.lib")
#pragma comment(lib, "../RongDian/pcre.lib")
#pragma comment(lib, "../RongDian/UCD.lib")
#pragma comment(lib, "../RongDian/libiconv.lib")
#pragma comment(lib, "../RongDian/SQLite.lib")
#pragma comment(lib, "../RongDian/SlimXml.lib")
#pragma comment(lib, "../RongDian/Tidy.lib")
#pragma comment(lib, "../RongDian/AsTidyLib.lib")
#pragma comment(lib, "../RongDian/CssTidyLib.lib")
#pragma comment(lib, "../RongDian/JsonTidyLib.lib")
#pragma comment(lib, "../RongDian/JsTidyLib.lib")
#pragma comment(lib, "../RongDian/PhpTidyLib.lib")
#pragma comment(lib, "../RongDian/SqlTidyLib.lib")
#pragma comment(lib, "../RongDian/DuiLib.lib")
#pragma comment(lib, "../RongDian/DuiMsg.lib")
#pragma comment(lib, "../RongDian/RDFinder.lib")
#pragma comment(lib, "../RongDian/RDNet.lib")
#endif 

BOOL				IsImageFile(LPCWSTR lpszFileName);
BOOL				IsCanTidy(LPCWSTR lpszLang);
int					EscapeSQLite(CDuiString strKeyWord);
int					RDMsgBox(HWND hWnd, int nTextId, int nCaptionId, UINT uType);
int					RDMsgBox(HWND hWnd, int nTextId,LPCWSTR lpszDynamicStr, int nCaptionId, UINT uType);
int					RDMsgBox(HWND hWnd, LPCWSTR lpszContent,int nCaptionId, UINT uType);
int					RDPopupBox(HWND hWnd, int nTextId, int nCaptionId);

BOOL				ShowLoading();
void				CancelLoading();

//////////////////////////////////////////////////////////////////////////
// 以下是工具类文件的引用
//////////////////////////////////////////////////////////////////////////
#include <Macros.h>
#include <StrUtil.h>
#include <Util.h>
#include <ColorUtil.h>
#include <SHHelper.h>
#include <ILangUI.h>
#include <ISkinUI.h>
#include <AdapterUtil.h>
#include <SQLiteUtil.h>
#include <PCREUtil.h>
#include <ConfigTable.h>
#include <CharSetTable.h>
#include <AddrTable.h>
#include <UrlEncode.h>

//////////////////////////////////////////////////////////////////////////
// 以下是自定义文件的引用
//////////////////////////////////////////////////////////////////////////
#include "resource.h"
#include "constant.h"
#include "RongDian.h"
#include "ITools.h"
#include "SystemTraySDK.h"
#include "TidyHelper.h"
#include "UpdateFrame.h"
#include "PanelRegister.h"
#include "MainFrame.h"

extern HANDLE					g_hUserSignature;
extern HANDLE					g_hAdminSignature;
extern BOOL						g_bActiveRunAsAdminThread;
extern HINSTANCE				g_hInstance;
extern wchar_t					g_szModule[1024];
extern wchar_t					g_szAppName[1024];
extern wchar_t					g_szAppVer[1024];
//extern wchar_t					g_szAppConfig[1024];
extern wchar_t					g_szAppConfigDB[1024];
extern wchar_t					g_szPanelsXml[1024];
extern wchar_t					g_szResPath[1024];
extern wchar_t					g_szLangPath[1024];
extern wchar_t					g_szLogPath[1024];
extern wchar_t					g_szSnapShot[1024];
extern wchar_t					g_szCoderPath[1024];
extern wchar_t					g_szCoderBackupPath[1024];
extern wchar_t					g_szHostsPath[1024];
extern wchar_t					g_szDefaultBackground[9];
extern wchar_t					g_szBackground[1024];
extern wchar_t					g_szLangFile[1024];
extern wchar_t					g_szAddrSolution[1024];
extern Logger					g_Logger;
extern Options					g_OptOptions;
extern CLangManager				*g_pLangManager;
extern CSkinManager				*g_pSkinManager;
extern CSystemTray				*g_pSystemTray;
extern CMainFrame				*g_pMainFrame;
extern list<LPMAIN_PANEL>		g_lstPanelInfo;
extern CSQLite					g_SQLite;
extern IMG_INFO					g_ImgInfo[MAX_IMG_TYPE];
extern TIDY_INFO				g_TidyInfo[MAX_TIDY_LANG];
extern MSG_INFO					g_LangIDs[MAX_MSG_ID];

