#pragma once
#include "afxcmn.h"


// Search 对话框

class Search : public CDialogEx
{
	DECLARE_DYNAMIC(Search)

public:
	Search(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Search();

// 对话框数据
	enum { IDD = IDD_SEARCH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list1;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
