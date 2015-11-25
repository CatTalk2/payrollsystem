#pragma once
#include "afxcmn.h"


// Info 对话框

class Info : public CDialog
{
	DECLARE_DYNAMIC(Info)

public:
	Info(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Info();

// 对话框数据
	enum { IDD = IDD_INFOMATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
};
