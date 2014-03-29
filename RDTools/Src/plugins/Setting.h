#pragma once

//////////////////////////////////////////////////////////////////////////
// CSetting
class CSetting : public CBaseTool
{
public:
	CSetting();
	virtual ~CSetting() { };
public:
	BOOL IsCanQuit(HWND /*hWnd*/, CPaintManagerUI* /*pManager*/);
	void OnQuit();
	BOOL OnInit(WPARAM /*wParam*/, LPARAM /*lParam*/);
	BOOL SetLang(CPaintManagerUI* /*pManager*/, LPCWSTR /*lpszLang*/, LPCWSTR /*lpszLangSection*/);
	
	void OnClick(HWND /*hWnd*/, CPaintManagerUI* /*pManager*/, TNotifyUI& /*msg*/, BOOL& /*bHandled*/);
	BOOL Apply(HWND hWnd);
	BOOL InitLangs();
	BOOL InitCheckVersion();
public:
	CComboUI * m_pLangsCombo;
	CCheckBoxUI * m_pCheckVersionCheckbox;
	CLabelUI * m_pCheckVersionLabel;
};
// CSetting
//////////////////////////////////////////////////////////////////////////