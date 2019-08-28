

//

#include "stdafx.h"
#include <iostream>
#include "SDKdemo.h"
#include "SDKdemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    


protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()






CSDKdemoDlg::CSDKdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SDKDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSDKdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_toyListInfo);
	DDX_Control(pDX, IDC_COMBO2, m_cmdList);
	DDX_Control(pDX, IDC_COMBO3, m_paramList);
	DDX_Control(pDX, IDC_COMBO4, m_combToyName);
	DDX_Control(pDX, IDC_BUTTON1, m_btnSearch);
	DDX_Control(pDX, IDC_BUTTON2, m_btnStop);
	DDX_Control(pDX, IDC_EDIT1, m_editToken);
	DDX_Control(pDX, IDC_TEXT_BETTARY, m_txBetarry);
}

BEGIN_MESSAGE_MAP(CSDKdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSDKdemoDlg::OnBnClickedsearchButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CSDKdemoDlg::OnBnClickedStopSearchButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CSDKdemoDlg::OnBnClickedSendButton)
	ON_BN_CLICKED(IDC_LIGHT_OPEN_BUTTON, &CSDKdemoDlg::OnBnClickedLightOpenButton)
	ON_BN_CLICKED(IDC_LIGHT_CLOSE_BUTTON, &CSDKdemoDlg::OnBnClickedLightCloseButton)
	ON_BN_CLICKED(IDC_LIGHT_FLASH_BUTTON, &CSDKdemoDlg::OnBnClickedLightFlashButton)
	ON_BN_CLICKED(IDC_BUTTON_CONNECTED, &CSDKdemoDlg::OnBnClickedButtonConnected)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECTED, &CSDKdemoDlg::OnBnClickedButtonDisconnected)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSDKdemoDlg::OnCbnSelchangeToyID)
	ON_EN_CHANGE(IDC_EDIT1, &CSDKdemoDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()




BOOL CSDKdemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		


	m_mapCmd[_T("Vibrate-(Suport All Toy)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE;
	m_mapCmd[_T("Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE;
	m_mapCmd[_T("Clockwise Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE_CLOCKWISE;
	m_mapCmd[_T("Anticlockwise Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE_ANTI_CLOCKWISE;
	m_mapCmd[_T("Change Rotate-(Suport Nora)-No Param")] = CLovenseToy::CmdType::COMMAND_ROTATE_CHANGE;

	m_mapCmd[_T("Vibrate-Activate the first one(Suport Edge)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE1;
	m_mapCmd[_T("Vibrate-Activate the second one(Suport Edge)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE2;

	m_mapCmd[_T("Flash Light-Flashing Light(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_FLASH;
	m_mapCmd[_T("Light On-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_LIGHT_ON;
	m_mapCmd[_T("Light Off-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_LIGHT_OFF;
	m_mapCmd[_T("Light Off-(Suport Domi)-No Param")] = CLovenseToy::CmdType::COMMAND_ALIGHT_OFF;
	m_mapCmd[_T("Light On-(Suport Domi)-No Param")] = CLovenseToy::CmdType::COMMAND_ALIGHT_ON;
    m_mapCmd[_T("Air In-(Suport Max)-Param(1~3)")] = CLovenseToy::CmdType::COMMAND_AIR_IN;
	m_mapCmd[_T("Air Out-(Suport Max)-Param(1~3)")] = CLovenseToy::CmdType::COMMAND_AIR_OUT;
	m_mapCmd[_T("Air Auto-(Suport Max)-Param(0~3)")] = CLovenseToy::CmdType::COMMAND_AIR_AUTO;
	m_mapCmd[_T("Power Off-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_POWER_OFF;
	m_mapCmd[_T("Start Move-(Suport Max,Nora)-10<=n<=99")] = CLovenseToy::CmdType::COMMAND_START_MOVE;
	m_mapCmd[_T("Stop Move-(Suport Max,Nora)-No Param")] = CLovenseToy::CmdType::COMMAND_STOP_MOVE;

	std::map<CString, int>::iterator iterMap = m_mapCmd.begin();
	while (iterMap != m_mapCmd.end())
	{
		m_cmdList.AddString(iterMap->first);
		++iterMap;
	}

	m_paramList.AddString(_T("0"));
	m_paramList.AddString(_T("1"));
	m_paramList.AddString(_T("2"));
	m_paramList.AddString(_T("3"));

	m_paramList.AddString(_T("4"));
	m_paramList.AddString(_T("5"));
	m_paramList.AddString(_T("6"));
	m_paramList.AddString(_T("7"));
	m_paramList.AddString(_T("8"));
	m_paramList.AddString(_T("9"));
	m_paramList.AddString(_T("10"));
	m_paramList.AddString(_T("11"));
	m_paramList.AddString(_T("12"));
	m_paramList.AddString(_T("13"));
	m_paramList.AddString(_T("14"));
	m_paramList.AddString(_T("15"));
	m_paramList.AddString(_T("16"));
	m_paramList.AddString(_T("17"));
	m_paramList.AddString(_T("18"));
	m_paramList.AddString(_T("19"));
	m_paramList.AddString(_T("20"));
	m_cmdList.SetCurSel(0);
	m_paramList.SetCurSel(4);
	return TRUE;  // 
}

void CSDKdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}



void CSDKdemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); //

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		//
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CSDKdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSDKdemoDlg::OnBnClickedsearchButton()
{

	TCHAR path[MAX_PATH];
	GetModuleFileName(NULL,path,MAX_PATH);
	m_toyListInfo.ResetContent();
	m_combToyName.ResetContent();
	m_mapToyInfo.clear();
	CLovenseToyManager *manager = GetLovenseToyManager();
	
	CString token;
	m_editToken.GetWindowText(token);
	token = token.TrimLeft();
	token = token.TrimRight();
	std::string strToken = CW2A(token.GetString());
	manager->SetDeveloperToken(strToken.c_str());
	if (manager)
	{
		manager->RegisterEventCallBack(this);
		manager->StartSearchToy();
	}
	m_btnSearch.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}


void CSDKdemoDlg::OnBnClickedStopSearchButton()
{

	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->StopSearchToy();
}

void CSDKdemoDlg::AddToyInfo(LPCTSTR toyID, LPCTSTR toyName)
{

	std::wstring info = toyID;
	//info += _T("(");
	//info += toyID;
	//info += _T(")");
	m_toyListInfo.AddString(info.c_str());
	m_toyListInfo.SetCurSel(0);
}

void CSDKdemoDlg::OnBnClickedSendButton()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);

	CString strCmd;
	m_cmdList.GetLBText(m_cmdList.GetCurSel(), strCmd);

	CString strParam;
	m_paramList.GetLBText(m_paramList.GetCurSel(), strParam);
	CLovenseToyManager *manager = GetLovenseToyManager();

	std::string toyID;
	toyID = CW2A(strID.GetString());
	std::string param = CW2A(strParam.GetString());
	
	CLovenseToy::CmdType cmdType = CLovenseToy::CmdType::COMMAND_VIBRATE;
	int curlCmd = m_cmdList.GetCurSel();
	m_cmdList.GetLBText(m_cmdList.GetCurSel(), strCmd);
	cmdType = (CLovenseToy::CmdType)m_mapCmd[strCmd];

	manager->SendCommand(toyID.c_str(), cmdType, atoi(param.c_str()));
}

void CSDKdemoDlg::LovenseErrorOutPut(int errorCode, const char *errorMsg)
{
	if (errorCode == CLovenseToy::Error::TOYERR_INVALIDTOKEN)
	{
		MessageBox(_T("Invalid token!"), _T("Error"), MB_OK);
	}
}


void CSDKdemoDlg::LovenseDidSearchStart()
{
	std::cout << "LovenseDidSearchStart"<< std::endl;
	m_btnSearch.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}

void CSDKdemoDlg::LovenseDidSearchEnd()
{
	std::cout << "LovenseDidSearchEnd" << std::endl;
	m_btnSearch.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
}

void CSDKdemoDlg::LovenseSearchingToys(CToyInfo info)
{
	if (1)
	{
		std::cout << info.GetToyName() << std::endl;
		CString toyID;
		toyID = info.GetToyID().c_str();
		m_toyListInfo.AddString(toyID);
		m_toyListInfo.SetCurSel(0);
		m_combToyName.AddString(CString(info.GetToyFullName().c_str()));
		m_combToyName.SetCurSel(0);

		if (m_toyListInfo.GetCurSel() == 0)
		{
			CString bettary;
			bettary.Format(_T("%d"), info.GetBettary());
			m_txBetarry.SetWindowText(bettary);
		}
		m_mapToyInfo.insert(std::make_pair(toyID,info));
	}
}

void CSDKdemoDlg::LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd, const char *result, CLovenseToy::Error errorCode)
{
	if (szToyID)
	{
		
	}
}

void CSDKdemoDlg::LovenseDidSendCmdStart()
{

}

void CSDKdemoDlg::LovenseDidSendCmdEnd()
{

}


void CSDKdemoDlg::LovenseToyConnectedStatus(const char *szToyID, bool isConnected)
{
	if(isConnected)
		std::cout << "Toy:" << szToyID << " is connected!"<<std::endl;
	else
		std::cout << "Toy:" << szToyID << " is disConnected!" << std::endl;
}

void CSDKdemoDlg::OnBnClickedLightOpenButton()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);

	CLovenseToyManager *manager = GetLovenseToyManager();
	std::string toyID;
	toyID = CW2A(strID.GetString());
	manager->SendCommand(toyID.c_str(), CLovenseToy::CmdType::COMMAND_LIGHT_ON, 0);
}


void CSDKdemoDlg::OnBnClickedLightCloseButton()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);

	CLovenseToyManager *manager = GetLovenseToyManager();
	std::string toyID;
	toyID = CW2A(strID.GetString());
	manager->SendCommand(toyID.c_str(), CLovenseToy::CmdType::COMMAND_LIGHT_OFF, 0);
}


void CSDKdemoDlg::OnBnClickedLightFlashButton()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	std::string toyID;
	toyID = CW2A(strID.GetString());

	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->SendCommand(toyID.c_str(), CLovenseToy::CmdType::COMMAND_FLASH, 0);
}


void CSDKdemoDlg::OnBnClickedButtonConnected()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	std::string toyID;
	toyID = CW2A(strID.GetString());
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->ConnectToToy(toyID.c_str());
}


void CSDKdemoDlg::OnBnClickedButtonDisconnected()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	std::string toyID;
	toyID = CW2A(strID.GetString());
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->DisConnectedToy(toyID.c_str());
}


void CSDKdemoDlg::OnCbnSelchangeToyID()
{

	m_combToyName.SetCurSel(m_toyListInfo.GetCurSel());
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(),strID);
	if (m_mapToyInfo.find(strID) != m_mapToyInfo.end())
	{
		CToyInfo info = m_mapToyInfo[strID];
		CString battery;
		battery.Format(_T("%d"), info.GetBettary());
		m_txBetarry.SetWindowTextW(battery);
	}

}


void CSDKdemoDlg::OnEnChangeEdit1()
{

}
