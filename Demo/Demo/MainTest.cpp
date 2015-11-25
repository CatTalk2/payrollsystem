// MainTest.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "MainTest.h"
#include "afxdialogex.h"
#include "Info.h"
#include "Insert.h"
#include "Search.h"
#include "geRen.h"

// MainTest 对话框

IMPLEMENT_DYNAMIC(MainTest, CDialogEx)

MainTest::MainTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainTest::IDD, pParent)
{

}

MainTest::~MainTest()
{
}

void MainTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONTROL, m_tab);
}


BEGIN_MESSAGE_MAP(MainTest, CDialogEx)
	
	
	ON_COMMAND(IDR_MENU1, &MainTest::OnIdrMenu1)
	ON_COMMAND(ID_yuangon, &MainTest::Onyuangon)
	ON_COMMAND(ID_Chaxun, &MainTest::OnChaxun)
	ON_COMMAND(ID_HELP, &MainTest::OnHelp)
	ON_COMMAND(ID_Exit, &MainTest::OnExit)
	ON_COMMAND(ID_aboutme, &MainTest::Onaboutme)
	ON_COMMAND(ID_GER, &MainTest::OnGer)
END_MESSAGE_MAP()


// MainTest 消息处理程序


BOOL MainTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	 m_hMenu1=LoadMenu(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MENU1));
 ::SetMenu(this->GetSafeHwnd(),m_hMenu1);//添加到对话框



return TRUE; // return TRUE unless you set the focus to a control
// 异常: OCX 属性页应返回 FALSE
	
	
}






void MainTest::OnIdrMenu1()
{
	//点击菜单后的处理代码，调出相对应窗体
	//主菜单
  CMenu   *pMenu;  
  pMenu=CMenu::FromHandle(m_hMenu1);//获得菜单栏的指针
  
  //权限设置
  //pMenu->EnableMenuItem(1,MF_BYPOSITION |MF_GRAYED);//禁用
  ////MF_BYPOSITION表示按序列查，从0开始,因为主菜单为popup类型，没有ID编号，只能用这中方式
  //MF_DISABLED
  pMenu->EnableMenuItem(0,MF_ENABLED);
  pMenu->EnableMenuItem(1,MF_ENABLED);
  pMenu->EnableMenuItem(2,MF_ENABLED);
  pMenu->EnableMenuItem(3,MF_ENABLED);
  pMenu->EnableMenuItem(4,MF_ENABLED);
 

}

void MainTest::Onyuangon()
{
	// 点击员工资料菜单
	if(number=="Admin")
	{
		Info info;
		info.DoModal();;
	}else
	{
		MessageBox(TEXT("对不起，您无权限使用此项功能，点击查看个人信息或修改密码"),NULL,MB_OK);
	}
	
	
}


void MainTest::OnChaxun()
{
	
	if(number=="Admin")
	{
		Insert insert;
		insert.DoModal();
	}else
	{
		MessageBox(TEXT("对不起，您无权限使用此项功能"),NULL,MB_OK);
	}
	

}


void MainTest::OnHelp()
{
	// 
	if(number=="Admin")
	{
		Search search;
		search.DoModal();
	}
	else
	{
		MessageBox(TEXT("对不起，您无权限使用此项功能"),NULL,MB_OK);
	}

}


void MainTest::OnExit()
{
	MainTest::OnOK();
}


void MainTest::Onaboutme()
{
	MessageBox(TEXT("我的大作业！"),NULL,MB_OK);
}


void MainTest::OnGer()
{
	//显示个人信息
	geRen dlg;
	dlg.NUM=number;
	
	dlg.DoModal();
}
