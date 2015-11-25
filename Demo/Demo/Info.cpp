// Info.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "Info.h"
#include "afxdialogex.h"
#include "MainTest.h"

// Info 对话框

IMPLEMENT_DYNAMIC(Info, CDialog)

Info::Info(CWnd* pParent /*=NULL*/)
	: CDialog(Info::IDD, pParent)
{

}

Info::~Info()
{
}

void Info::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Info, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Info::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &Info::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Info::OnBnClickedButton1)
END_MESSAGE_MAP()


// Info 消息处理程序


BOOL Info::OnInitDialog()
{
	CDialog::OnInitDialog();
	DWORD style = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(style | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	
	m_list.InsertColumn(0,_T("工号"),LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(1,_T("姓名"),LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(2,_T("年龄"),LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(3,_T("职务"),LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(4,_T("工资"),LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(5,_T("计算所得税金"),LVCFMT_LEFT,100,-1);
	
	//读取文件
	CString number,name,age,work,salary,result;   //定义一个CString对象，用于保存文本框控件内的文本
    
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
	int k=0,p=0,s=0,j=0,shui=0;
	m_list.DeleteAllItems();
	while(file.ReadString(strTemp))
	{
		//整行读取后用函数处理字符串
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		k=0;
		m_list.InsertItem(k,number);
		m_list.SetItemText(k,1,name);
		m_list.SetItemText(k,2,age);
		m_list.SetItemText(k,3,work);
		m_list.SetItemText(k,4,salary);
		p++;	
		shui=_ttof(salary);
		s+=shui;
		//税金计算代码
		if(shui<1500)
		{
			shui=0;
		}
		if(shui<=2500&&shui>=1500)
		{
			shui=(shui-1500)*0.1;
		}
		if(shui<=3500&&shui>2500)
		{
			shui=(shui-2500)*0.15;
		}
		if(shui<=5000&&shui>3500)
		{
			shui=(shui-3500)*0.2;
		}
		if(shui<=10000&&shui>5000)
		{
			shui=(shui-5000)*0.3;
		}
		if(shui>10000)
		{
			shui=(shui-10000)*0.4;
		}
		shuijin.Format(_T("%d"), shui);
		m_list.SetItemText(k,5,shuijin);
		j+=shui;
		
	}
	CString peo,sum,jok;
	peo.Format(_T("%d"), p);
	sum.Format(_T("%d"), s);
	jok.Format(_T("%d"), j);
	GetDlgItem(IDC_PEOPLE)->SetWindowText(peo);
	GetDlgItem(IDC_SUM)->SetWindowText(sum);
	GetDlgItem(IDC_SHUI)->SetWindowText(jok);
	
	
	file.Close();
	return TRUE;  // return TRUE unless you set the focus to a control

}


void Info::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	
	
}


void Info::OnBnClickedButton2()
{
	Info:OnOK();
}


void Info::OnBnClickedButton1()
{
	POSITION p=m_list.GetFirstSelectedItemPosition();    //获取首选中行位置
	while (p) 
     {
       int  nSelected=m_list.GetNextSelectedItem(p); //获取选中行的索引
       m_list.DeleteItem(nSelected); //根据索引删除
       p  = m_list.GetFirstSelectedItemPosition();  
     }
}
