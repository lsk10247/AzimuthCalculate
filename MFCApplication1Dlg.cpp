﻿
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "Tools.h"
#include "afxmsg_.h"

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
public:
	
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, degree(0)
	, radian(0)
	, radian2(0)
	, angle(0)
	, degree2(0)
	, angle2(0)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
	, result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, degree);
	DDX_Text(pDX, IDC_EDIT2, radian);
	DDX_Text(pDX, IDC_EDIT3, radian2);
	DDX_Text(pDX, IDC_EDIT4, degree);
	DDX_Text(pDX, IDC_EDIT1, angle);
	DDX_Text(pDX, IDC_EDIT5, degree2);
	DDX_Text(pDX, IDC_EDIT6, angle2);
	DDX_Text(pDX, IDC_EDIT7, x1);
	DDX_Text(pDX, IDC_EDIT9, y1);
	DDX_Text(pDX, IDC_EDIT8, x2);
	DDX_Text(pDX, IDC_EDIT10, y2);
	DDX_Text(pDX, IDC_EDIT11, result);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONatr, &CMFCApplication1Dlg::OnBnClickedButtonatr)
	ON_BN_CLICKED(IDC_BUTTONrtd, &CMFCApplication1Dlg::OnBnClickedButtonrtd)
	ON_BN_CLICKED(IDC_BUTTONdta, &CMFCApplication1Dlg::OnBnClickedButtondta)
	ON_BN_CLICKED(IDC_BUTTONCALCULATE, &CMFCApplication1Dlg::OnBnClickedButtoncalculate)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnBnClickedButtonatr()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	radian = AngleToRadian(angle);
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtonrtd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	degree = RadianToDegree(radian2);
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtondta()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	angle2 = DegreeToAngle(degree2);
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnBnClickedButtoncalculate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	result = RadianToDegree(CalculateAzimuth(x1, y1, x2, y2));
	UpdateData(FALSE);
}
