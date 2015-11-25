// Search.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "Search.h"
#include "afxdialogex.h"
#include "MainTest.h"

// Search 对话框

IMPLEMENT_DYNAMIC(Search, CDialogEx)

Search::Search(CWnd* pParent /*=NULL*/)
	: CDialogEx(Search::IDD, pParent)
{

}

Search::~Search()
{
}

void Search::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(Search, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Search::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &Search::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Search::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// Search 消息处理程序


BOOL Search::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DWORD style = m_list1.GetExtendedStyle();
	m_list1.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	
	m_list1.InsertColumn(0,_T("工号"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(1,_T("姓名"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(2,_T("年龄"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(3,_T("职务"),LVCFMT_LEFT,100,-1);
	m_list1.InsertColumn(4,_T("工资"),LVCFMT_LEFT,100,-1);
	
	
	
	return TRUE;
	// 异常: OCX 属性页应返回 FALSE
}


void Search::OnBnClickedButton5()
{
Search:OnOK();

}


void Search::OnBnClickedButton1()
{
	
	//读取文件
	CString number,name,age,work,salary,number1;   //定义一个CString对象，用于保存文本框控件内的文本
    
	//读取文件操作：看对应用户和密码是否匹配，匹配则进入主界面，否则弹出警告
	
	CFileFind fileFind;//查找文件是否存在
	CString strFileName;
	strFileName = _T("res/file/info.txt");
	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("读取用户信息文件失败"),NULL,MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName,CFile::modeRead);
	CString strText,shuijin;
	CString strTemp;
	int state=0,k=0;
	m_list1.DeleteAllItems();
	((CEdit*)this->GetDlgItem(IDC_SNU))->GetWindowText(number1);
	while(file.ReadString(strTemp))
	{
		//整行读取后用函数处理字符串
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(number1==number)
		{
			m_list1.InsertItem(k,number);
			m_list1.SetItemText(k,1,name);
			m_list1.SetItemText(k,2,age);
			m_list1.SetItemText(k,3,work);
			m_list1.SetItemText(k,4,salary);
			state=1;
		}
		
	}
	GetDlgItem(IDC_SNU)->SetWindowText(_T(""));
	if(state==0)
	{
		MessageBox(TEXT("此用户不存在！"),NULL,MB_OK);
	}
	file.Close();


}


void Search::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
}
