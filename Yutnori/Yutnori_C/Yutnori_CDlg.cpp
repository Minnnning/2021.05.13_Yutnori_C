
// Yutnori_CDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Yutnori_C.h"
#include "Yutnori_CDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CYutnoriCDlg 대화 상자



CYutnoriCDlg::CYutnoriCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YUTNORI_C_DIALOG, pParent)
	, m_strAddress(_T("127.0.0.1"))
	, m_nPort(7000)
	, m_strMessage(_T("안녕하세요?"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYutnoriCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strAddress);
	DDX_Text(pDX, IDC_EDIT2, m_nPort);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlEdit);
	DDX_Text(pDX, IDC_EDIT4, m_strMessage);
}

BEGIN_MESSAGE_MAP(CYutnoriCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CYutnoriCDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CYutnoriCDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CYutnoriCDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CYutnoriCDlg::OnBnClickedConnect)
END_MESSAGE_MAP()


// CYutnoriCDlg 메시지 처리기

BOOL CYutnoriCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CYutnoriCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CYutnoriCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CYutnoriCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYutnoriCDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CYutnoriCDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CYutnoriCDlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CYutnoriCDlg::OnBnClickedConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pClientSocket = new CClientSocket;
	m_pClientSocket->Create();
	CString str; str.Format(_T("[나] 서버(%s:%d)와 연결합니다.....\r\n"), m_strAddress, m_nPort);
	m_ctrlEdit.ReplaceSel(str);
	this->UpdateData(TRUE); //컨트롤에 입력된 내용을 멤버변수에 넣는다.
	bool success = m_pClientSocket->Connect(m_strAddress, m_nPort);
	if (!success) m_ctrlEdit.ReplaceSel(_T("[error] 서버와 연결하지 못했습니다.\r\n"));

}


BOOL CYutnoriCDlg::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pClientSocket->ShutDown();
	m_pClientSocket->Close();
	delete m_pClientSocket;
	return CDialogEx::DestroyWindow();
}


void CYutnoriCDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	this->UpdateData(TRUE);; //데이터를 갱신한다.
	m_strMessage.Append(_T("\r\n")); //줄 바꿈 코드를 추가한다.
	m_pClientSocket->Send(m_strMessage, m_strMessage.GetLength());
	m_strMessage = _T(""); //내용을 삭제한다.
	this->UpdateData(FALSE); //화면을 갱신한다.

	//CDialogEx::OnOK(); //프로그램이 종료되는 것을 방지한다.
}
