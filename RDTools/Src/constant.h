#pragma once

// Mail
const wchar_t* const kAuthorMail					= L"multiarrow@qq.com";
// Url
const wchar_t* const kAuthorUrl						= L"http://www.rongdian.net";
// CopyRight
const wchar_t* const kCopyRight						= L"CopyRight 2014 RongDian.net";
// Update Url
const char*	   const kCheckVersionUrl				= "http://www.rongdian.net/rdol.php?type=3";

//table column constance
const wchar_t* const tConfigLang 					= L"Lang";
const wchar_t* const tConfigCheckVersion 			= L"CheckVersion";
const wchar_t* const tConfigLastVisitTab 			= L"LastVisitTab";

// language files
#ifdef _DEBUG
const wchar_t* const kLangFile						= L"..\\RongDian\\lang\\lang_*.ini";
#else
const wchar_t* const kLangFile						= L"lang\\lang_*.ini";
#endif

// SnapShot.exe
#ifdef _DEBUG
const wchar_t* const kSnapShotExec					= L"SnapShotd.exe";
#else
const wchar_t* const kSnapShotExec					= L"SnapShot.exe";
#endif

// RDZoomIn.exe
#ifdef _DEBUG
const wchar_t* const kZoomInExec					= L"RDZoomInd.exe";
#else
const wchar_t* const kZoomInExec					= L"RDZoomIn.exe";
#endif

// Config.db
const wchar_t* const kConfigDB						= L"Config.db";

// Config.ini
const wchar_t* const kConfigIni						= L"config.ini";
const wchar_t* const kDefaultLangIni				= L"lang_en.ini"; // 语言文件
const wchar_t* const kDefaultTab					= L"plugin_picker"; // 默认显示的tab

// XML文件
const wchar_t* const kMainFrameXml					= L"MainFrame.xml"; // 主窗体
const wchar_t* const kUpdateFrameXml				= L"UpdateFrame.xml"; // 更新窗体
const wchar_t* const kPanelsXml						= L"Panels.xml";
const wchar_t* const kSysMenuXml					= L"SysMenu.xml"; // 

// ICON Name
const wchar_t* const kMsgIconName					= L"RongDian.png";
const wchar_t* const kImageArrow					= L"ZoomIn.png";
const wchar_t* const kImageCross					= L"Cross.png";

// System Menu ID
#define SYS_MENU_ABOUT								10000
#define SYS_MENU_CHECKVERSION						10001
#define SYS_MENU_SHOW								10002
#define SYS_MENU_QUIT								10003

// Lang Section
const wchar_t* const LS_SETTINGS					= L"plugin_settings";
const wchar_t* const LS_LANG						= L"Lang";
const wchar_t* const LS_SKIN						= L"Skin";
const wchar_t* const LS_IPSETS						= L"IPSets";
const wchar_t* const LS_MAINFRAME					= L"MainFrame";
const wchar_t* const LS_UPDATEFRAME					= L"UpdateFrame";
const wchar_t* const LS_SYSTRAY						= L"SysTray";
const wchar_t* const LS_ABOUTPANEL					= L"plugin_about";
const wchar_t* const LS_MSG							= L"Msg";
const wchar_t* const LS_DUIMSG						= L"DuiMsg";

// About Panel(default's Panel)
const wchar_t* const kLayoutAbout					= L"plugin_about_layout";
const wchar_t* const kXmlAbout						= L"About.xml";
const wchar_t* const kTabAbout						= L"plugin_about";
const wchar_t* const kPanelAbout					= L"plugin_about";
const wchar_t* const kNameAbout						= L"plugin_about_name";
const wchar_t* const kDescAbout						= L"plugin_about_desc";

// MSG
const wchar_t* const kMsgErr						= L"msg_err";
const wchar_t* const kMsgSuccess					= L"msg_success";
const wchar_t* const kMsgFailed						= L"msg_failed";
const wchar_t* const kMsgWarning					= L"msg_warning";
const wchar_t* const kLoading						= L"msg_loading";
const wchar_t* const kBusy							= L"msg_busy";
const wchar_t* const kPluginErr						= L"plugin_err";
const wchar_t* const kNoFoundErr					= L"nofound_err";
const wchar_t* const kFolderTitle					= L"folder_title";
const wchar_t* const kStillWorkingErr				= L"still_working";
const wchar_t* const kHandleText					= L"handle_text";
const wchar_t* const kHandleErrText					= L"handle_err_text";
const wchar_t* const kNoHandleText					= L"nohandle_text";
const wchar_t* const kCharSetErr					= L"charset_err";
const wchar_t* const kInvalidPathErr				= L"invalid_path_err";
const wchar_t* const kInvalidFinderErr				= L"invalid_finder_err";
const wchar_t* const kInvalidFormatterErr			= L"invalid_formatter_err";
const wchar_t* const kInvalidIPErr					= L"invalid_ipv4_err";
const wchar_t* const kInvalidDomainErr				= L"invalid_domain_err";
const wchar_t* const kInvalidMaskErr				= L"invalid_subnet_mask_err";
const wchar_t* const kInvalidGatewayErr				= L"invalid_gateway_err";
const wchar_t* const kInvalidDnsErr					= L"invalid_dns_err";
const wchar_t* const kInvalidBackgroundErr			= L"invalid_background_err";
const wchar_t* const kDeleteSolution				= L"delete_solution";
const wchar_t* const kInvalidName					= L"invalid_name";
const wchar_t* const kDebugText						= L"debug_text";
const wchar_t* const kDone							= L"done";
const wchar_t* const kCreateHostGroupErr			= L"create_host_group_err";
const wchar_t* const kLoadHostErr					= L"load_host_err";
const wchar_t* const kHostSaveMsg					= L"host_save_msg";
const wchar_t* const kNewVersionMsg					= L"new_version_msg";
const wchar_t* const kReplaceFiles					= L"replace_files";
const wchar_t* const kBackedupTo					= L"backedup_to";

// SysTray
const wchar_t* const kTrayTip						= L"tray_tip";

// 
const wchar_t* const kBackGround					= L"Background";
const wchar_t* const kLang							= L"Lang";
const wchar_t* const kSolution						= L"Solution";
const wchar_t* const kSelected						= L"Selected";
const wchar_t* const kValid							= L"Valid";
const wchar_t* const kName							= L"Name";
const wchar_t* const kAddrType						= L"AddrType";
const wchar_t* const kAddr							= L"Addr";
const wchar_t* const kMask							= L"Mask";
const wchar_t* const kGateway						= L"Gateway";
const wchar_t* const kDnsType						= L"DnsType";
const wchar_t* const kDns1							= L"Dns1";
const wchar_t* const kDns2							= L"Dns2";

#ifndef STRING_LENGTH
#define 			 STRING_LENGTH					260
#endif

typedef enum _tagMSG_ID {
	// DuiMsg
	MSG_YES = 0,
	MSG_NO,
	MSG_OK,
	MSG_RETRY,
	MSG_CANCEL,
	// Msg Section
	MSG_ERR = 30,
	MSG_WARNING,
	MSG_SUCCESS,
	MSG_FAILED,
	MSG_LOADING,
	MSG_BUSY,
	MSG_PLUGIN_ERR,
	MSG_NOFOUND_ERR,
	MSG_FOLDER_TITLE,
	MSG_STILL_WORKING,
	MSG_HANDLE_TEXT,
	MSG_HANDLE_ERR_TEXT,
	MSG_NOHANDLE_TEXT,
	MSG_CHARSET_ERR,
	MSG_INVALID_PATH,
	MSG_FINDER_ERR,
	MSG_FORMATTER_ERR,
	MSG_IPV4_ERR,
	MSG_DOMAIN_ERR,
	MSG_MASK_ERR,
	MSG_GATEWAY_ERR,
	MSG_DNS_ERR,
	MSG_BACKGROUND_ERR,
	MSG_DELETE_SOLUTION,
	MSG_INVALID_NAME,
	MSG_DEBUG_TEXT,
	MSG_DONE,
	MSG_CREATE_HOST_GROUP_ERR,
	MSG_LOAD_HOST_ERR,
	MSG_HOST_SAVE_MSG,
	MSG_NEW_VERSION_MSG,
	MSG_REPLACE_FILES,
	MSG_BACKEDUP_TO,
	// End
	MSG_END = 200
} MSG_ID;

const UINT MAX_MSG_ID = MSG_END + 1;

typedef struct _tagMSG_INFO
{
	int nId;
	LPCWSTR pId;
	LPCWSTR pSection;
} MSG_INFO, *PMSG_INFO, *LPMSG_INFO;

typedef struct _tagMAIN_PANEL
{
	wchar_t szLayout[STRING_LENGTH];
	wchar_t szXml[STRING_LENGTH];
	wchar_t szTab[STRING_LENGTH];
	wchar_t szPanel[STRING_LENGTH];
	wchar_t szName[STRING_LENGTH];
	wchar_t szDesc[STRING_LENGTH];
	wchar_t szDll[STRING_LENGTH*2];
	list<_tagMAIN_PANEL*> childs;
	_tagMAIN_PANEL()
	{
		memset(szLayout,0,sizeof(szLayout));
		memset(szXml,0,sizeof(szXml));
		memset(szTab,0,sizeof(szTab));
		memset(szPanel,0,sizeof(szPanel));
		memset(szName,0,sizeof(szName));
		memset(szDesc,0,sizeof(szDesc));
		memset(szDll,0,sizeof(szDll));
	}
} MAIN_PANEL, *PMAIN_PANEL, *LPMAIN_PANEL;

typedef struct _tagSKIN_INFO
{
	wchar_t szImage[1024];
	DWORD dwBKColor;
	BOOL bImage;
} SKIN_INFO, *LSKIN_INFO, *LPSKIN_INFO;

typedef struct _tagCHARSET_INFO
{
	int nType;
	wchar_t szName[STRING_LENGTH];
	wchar_t szValue[STRING_LENGTH];
	wchar_t szDesc[STRING_LENGTH];
} CHARSET_INFO, *PCHARSET_INFO, *LPCHARSET_INFO;

typedef struct _tagCODER_INFO
{
	wchar_t szPath[1024];
	char szFrom[64];
	char szTo[64];
	BOOL bHandle;
	BOOL bValid;
} CODER_INFO, *LCODER_INFO, *LPCODER_INFO;

typedef struct _tagTIDY_PANEL
{
	wchar_t szName[STRING_LENGTH];
	wchar_t szPath[STRING_LENGTH*4];
	wchar_t szPanel[STRING_LENGTH];
	wchar_t szDesc[STRING_LENGTH];
} TIDY_PANEL, *PTIDY_PANEL, *LPTIDY_PANEL;

typedef enum _tagADDR_MODE
{
	ADDR_AUTO_SET = 0,
	ADDR_MANUAL_SET = 1
} ADDR_MODE;

typedef enum _tagDNS_MODE
{
	DNS_AUTO_SET = 0,
	DNS_MANUAL_SET = 1
} DNS_MODE;

typedef struct _tagIPCONFIG_INFO
{
	int nValid;
	int nAddrType;
	int nDnsType;
	wchar_t szSolution[STRING_LENGTH];
	wchar_t szAddr[STRING_LENGTH];
	wchar_t szMask[STRING_LENGTH];
	wchar_t szGateway[STRING_LENGTH];
	wchar_t szDns1[STRING_LENGTH];
	wchar_t szDns2[STRING_LENGTH];
} IPCONFIG_INFO, *PIPCONFIG_INFO, *LPIPCONFIG_INFO;

typedef struct _tagADAPTER_INFO
{
	int nIndex;
	BOOL bEnableDHCP;
	wchar_t szName[STRING_LENGTH];
	wchar_t szType[STRING_LENGTH];
	wchar_t szDesc[STRING_LENGTH];
	wchar_t szAdapter[STRING_LENGTH];
	wchar_t szAddr[4][STRING_LENGTH];
	wchar_t szMask[STRING_LENGTH];
	wchar_t szGateway[STRING_LENGTH];
	wchar_t szDns[2][STRING_LENGTH];
	wchar_t szMac[STRING_LENGTH];
} ADAPTER_INFO, *PADAPTER_INFO, *LPADAPTER_INFO;

typedef enum _tagIMG_TYPE
{
	IMG_JPEG = 0,
	IMG_JPG,
	IMG_PNG,
	IMG_BMP,
	IMG_GIF,
	IMG_PSD,
	IMG_UNDEFINE
} IMG_TYPE;

const UINT MAX_IMG_TYPE = IMG_UNDEFINE + 1;

typedef struct _tagIMG_INFO
{
	wchar_t szName[STRING_LENGTH];
	int nType;
	int bSupport;
} IMG_INFO, *PIMG_INFO, *LPIMG_INFO;

typedef enum _tagTIDY_TYPE {
	TIDY_ACTIONSCRIPT = 0,
	TIDY_ADA,	
	TIDY_ASM,	
	TIDY_ASP,
	TIDY_AUTOHOTKEY,
	TIDY_AUTOIT,
	TIDY_BATCH,
	TIDY_COBOL,
	TIDY_CPP,
	TIDY_CS,
	TIDY_CSS,
	TIDY_D,
	TIDY_FORTRAN,
	TIDY_HASKELL,
	TIDY_HTML,
	TIDY_HTML_AT,
	TIDY_HTML_CP,
	TIDY_HTML_NBT,
	TIDY_HTML_NET,
	TIDY_HTML_NIT,
	TIDY_HTML_NPT,
	TIDY_INI,
	TIDY_JAVA,
	TIDY_JAVASCRIPT,
	TIDY_JSON,
	TIDY_JSP,
	TIDY_LISP,
	TIDY_LUA,
	TIDY_NORMALTEXT,
	TIDY_OBJECTIVEC,
	TIDY_PASCAL,
	TIDY_PERL,
	TIDY_PHP,
	TIDY_PYTHON,
	TIDY_RUBY,
	TIDY_SQL,
	TIDY_VB,
	TIDY_VERILOG,
	TIDY_VHDL,
	TIDY_XML,
	TIDY_END
} TIDY_TYPE;

const UINT MAX_TIDY_LANG = TIDY_END + 1;

typedef struct _tagTIDY_INFO
{
	wchar_t szName[STRING_LENGTH];
	char szOption[STRING_LENGTH];
	UINT uID;
} TIDY_INFO, *PTIDY_INFO, *LPTIDY_INFO;

typedef struct _tagCMD_EXE_INFO
{
	HWND	hWnd;
	LPWSTR	lpszCommand;
	LPVOID	lpLoader;
} CMD_EXE_INFO, *PCMD_EXE_INFO, *LPCMD_EXE_INFO;

