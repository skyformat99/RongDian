#include "stdafx.h"
#include "UIChildLayout.h"

namespace DuiLib
{
	CChildLayoutUI::CChildLayoutUI()
	{
		m_pCallback = NULL;
	}

	void CChildLayoutUI::Init()
	{
		if (!m_pstrXMLFile.IsEmpty())
		{
			CDialogBuilder builder;
			CContainerUI* pChildWindow = static_cast<CContainerUI*>(builder.Create(m_pstrXMLFile.GetData(), (UINT)0, m_pCallback, m_pManager));
			if (pChildWindow)
			{
				this->Add(pChildWindow);
			}
			else
			{
				this->RemoveAll();
			}
		}
	}

	void CChildLayoutUI::SetAttribute( LPCTSTR pstrName, LPCTSTR pstrValue )
	{
		if( _tcscmp(pstrName, _T("xmlfile")) == 0 )
			SetChildLayoutXML(pstrValue);
		else
			CContainerUI::SetAttribute(pstrName,pstrValue);
	}

	void CChildLayoutUI::SetChildLayoutXML( DuiLib::CDuiString pXML, IDialogBuilderCallback* m_pCallback /*= NULL*/)
	{
		m_pstrXMLFile = pXML;
		m_pCallback = m_pCallback;
	}

	DuiLib::CDuiString CChildLayoutUI::GetChildLayoutXML()
	{
		return m_pstrXMLFile;
	}

	LPVOID CChildLayoutUI::GetInterface( LPCTSTR pstrName )
	{
		if( _tcscmp(pstrName, DUI_CTR_CHILDLAYOUT) == 0 ) return static_cast<CChildLayoutUI*>(this);
		return CControlUI::GetInterface(pstrName);
	}

	LPCTSTR CChildLayoutUI::GetClass() const
	{
		return _T("ChildLayoutUI");
	}
} // namespace DuiLib
