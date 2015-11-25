// geRen.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "geRen.h"
#include "afxdialogex.h"
#include "Search.h"

// geRen 对话框

IMPLEMENT_DYNAMIC(geRen, CDialog)

geRen::geRen(CWnd* pParent /*=NULL*/)
	: CDialog(geRen::IDD, pParent)
{

}

geRen::~geRen()
{
}

void geRen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(geRen, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &geRen::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &geRen::OnBnClickedButton2)
END_MESSAGE_MAP()


// geRen 消息处理程序


BOOL geRen::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString number,name,age,work,salary,pass;   //定义一个CString对象，用于保存文本框控件内的文本
    
	//读取文件操作：看对应用户和密码是否匹配，匹配则进入主界面，否则弹出警告
	
	CFileFind fileFind;//查找文件是否存在
	CString strFileName;
	if(NUM=="Admin")
	{
		strFileName = _T("res/file/Admin.txt");
	}
	else
	{
		strFileName = _T("res/file/info.txt");
	}

	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("读取用户信息文件失败"),NULL,MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName,CFile::modeRead);
	CString strText;
	CString strTemp;
	int k=0;
	while(file.ReadString(strTemp))
	{
		//整行读取后用函数处理字符串
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( pass, strTemp, 2, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(NUM==number)
		{
			GetDlgItem(IDC_EDIT1)->SetWindowText(number);
			GetDlgItem(IDC_EDIT2)->SetWindowText(name);
			GetDlgItem(IDC_EDIT3)->SetWindowText(age);
			GetDlgItem(IDC_EDIT4)->SetWindowText(work);
			GetDlgItem(IDC_EDIT5)->SetWindowText(salary);
			GetDlgItem(IDC_EDIT6)->SetWindowText(pass);
			
		}
		
	}
	file.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
}

void geRen::OnBnClickedButton1()
{
	//读取文件
	CString number,name,age,work,salary,pass,newpass;   //定义一个CString对象，用于保存文本框控件内的文本
    
	//读取文件操作：看对应用户和密码是否匹配，匹配则进入主界面，否则弹出警告
	
	CFileFind fileFind;//查找文件是否存在
	CString strFileName;
	strFileName = _T("res/file/info.txt");
	if(!fileFind.FindFile(strFileName) )
	{
		::MessageBox(NULL,TEXT("读取用户信息文件失败"),NULL,MB_OK);
	}
	((CEdit*)this->GetDlgItem(IDC_EDIT7))->GetWindowText(newpass);
	CStdioFile file;
	file.Open(strFileName,CFile::modeReadWrite);
	CString strText;
	CString strTemp;
	

     while(file.ReadString(strTemp))
	{
		//整行读取后用函数处理字符串
		strText += strTemp;
		AfxExtractSubString ( number, strTemp, 0, ' ');
		AfxExtractSubString ( name, strTemp, 1, ' ');
		AfxExtractSubString ( age, strTemp, 3, ' ');
		AfxExtractSubString ( work, strTemp, 4, ' ');
		AfxExtractSubString ( salary, strTemp, 5, ' ');
		if(NUM==number)
		{
			file.SeekToEnd();
			file.WriteString(number+" "+name+" "+newpass+" "+age+" "+work+" "+salary+"\n");

			MessageBox(TEXT("修改成功！"),NULL,MB_OK);
			break;
			
		}
		
	}
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT7)->SetWindowText(_T(""));
		
        file.Close();
  
	


	
}


void geRen::OnBnClickedButton2()
{
	geRen:OnOK();
}
