
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double degree;
	double radian;
	double radian2;
	double angle;
	double degree2;
	double angle2;
	afx_msg void OnBnClickedButtonatr();
	afx_msg void OnBnClickedButtonrtd();
	afx_msg void OnBnClickedButtondta();
	// 点1的x坐标
	double x1;
	// 点1的y坐标
	double y1;
	// 点2的x坐标
	double x2;
	// 点2的y坐标
	double y2;
	// 方位角计算结果
	double result;
	afx_msg void OnBnClickedButtoncalculate();
};
