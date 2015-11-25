#pragma once


// Insert 对话框

class Insert : public CDialogEx
{
	DECLARE_DYNAMIC(Insert)

public:
	Insert(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Insert();

// 对话框数据
	enum { IDD = IDD_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
};
