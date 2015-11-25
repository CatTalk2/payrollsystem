#pragma once
#include "afxcmn.h"


// MainTest 对话框

class MainTest : public CDialogEx
{
	DECLARE_DYNAMIC(MainTest)

public:
	MainTest(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainTest();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_tab;
	HMENU m_hMenu1;
	int power;
	CString number;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnIdrMenu2();
	afx_msg void OnIdrMenu1();
	afx_msg void Onyuangon();
	afx_msg void OnChaxun();
	afx_msg void OnHelp();
	afx_msg void OnExit();
	afx_msg void Onaboutme();
	afx_msg void OnGer();
};
