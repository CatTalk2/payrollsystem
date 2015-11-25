#pragma once


// geRen 对话框

class geRen : public CDialog
{
	DECLARE_DYNAMIC(geRen)

public:
	geRen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~geRen();

// 对话框数据
	enum { IDD = IDD_GEREN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString NUM;
	int ReplaceText(CString ,CString,CString);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
