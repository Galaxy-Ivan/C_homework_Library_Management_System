﻿
// P5Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "P5.h"
#include "P5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CP5Dlg 对话框



CP5Dlg::CP5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str1);
}

BEGIN_MESSAGE_MAP(CP5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CP5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CP5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CP5Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CP5Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CP5Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CP5Dlg 消息处理程序

BOOL CP5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	str1 = "未登录";
	UpdateData(false);
	VIPWin1.Create(IDD_VIPWin);
	LibWin1.Create(IDD_Library);
	GetDlgItem(IDC_EDIT2)->SetWindowText(L"Designed by Galaxy_Ivan 231226");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CP5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CP5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CP5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CP5Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (LoginWin1.Logined) {
		str1 = "未登录";
		GetDlgItem(IDC_BUTTON1)->SetWindowText(L"登录");
		LoginWin1.Logined = false;
	}
	else {
		LoginWin1.DoModal();
		if (LoginWin1.Logined) {
			str1 = "已登录";
			GetDlgItem(IDC_BUTTON1)->SetWindowText(L"退出登录");
		}
		else
			str1 = "未登录";
	}
	UpdateData(false);
}


void CP5Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CP5Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (LoginWin1.Logined) {
		VIPWin1.ShowWindow(SW_NORMAL);
	}
	else {
		str1 = "您尚未登录！";
		MessageBox(L"您尚未登录！",L"好像哪里不对qwq");
		UpdateData(false);
	}
}


void CP5Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (LoginWin1.Logined) {
		LibWin1.ShowWindow(SW_NORMAL);
	}
	else {
		str1 = "您尚未登录！";
		MessageBox(L"您尚未登录！", L"好像哪里不对qwq");
		UpdateData(false);
	}
}


void CP5Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (LoginWin1.Logined) {
		ShopWin1.DoModal();
	}
	else {
		str1 = "您尚未登录！";
		MessageBox(L"您尚未登录！", L"好像哪里不对qwq");
		UpdateData(false);
	}
}
