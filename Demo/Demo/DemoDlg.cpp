
// DemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"
#include <afx.h>
#include "MainTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemoDlg 对话框



CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON1, &CDemoDlg::OnBnClickedButton1)
	
END_MESSAGE_MAP()


// CDemoDlg 消息处理程序

BOOL CDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemoDlg::OnPaint()
{
	if (IsIconic())
    {
        CPaintDC dc(this); // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        //
        // 给窗体添加背景
        //
        CPaintDC dc(this);
        CRect rc;
        GetClientRect(&rc);
        CDC dcMem;
        dcMem.CreateCompatibleDC(&dc);
        CBitmap bmpBackground;
        bmpBackground.LoadBitmap(IDB_BITMAP1);

        BITMAP bitmap;
        bmpBackground.GetBitmap(&bitmap);
        CBitmap* pbmpPri = dcMem.SelectObject(&bmpBackground);
        dc.StretchBlt(0,0,rc.Width(), rc.Height(), &dcMem,0,0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDemoDlg::OnBnClickedButton1()
{
	// 点击确定按钮后验证用户身份，如果正确进入主界面，否则弹出警告
	int state=0;//用来指示验证状态
	CString user,pwd;   //定义一个CString对象，用于保存文本框控件内的文本
    
	((CEdit*)this->GetDlgItem(IDC_USERNAME))->GetWindowText(user);
	((CEdit*)this->GetDlgItem(IDC_PASSWORD))->GetWindowText(pwd);
	if(user==""||pwd=="")
	{
		::MessageBox(NULL,TEXT("用户名或密码不能为空"),NULL,MB_OK);
		state=1;
		
	}
	//读取文件操作：看对应用户和密码是否匹配，匹配则进入主界面，否则弹出警告
	
	CFileFind fileFind;//查找文件是否存在
	CString strFileName1,strFileName2;
	strFileName1 = _T("../Demo/res/file/Admin.txt");
	strFileName2 = _T("../Demo/res/file/info.txt");
	if(!fileFind.FindFile(strFileName1)||!fileFind.FindFile(strFileName2))
	{
		::MessageBox(NULL,TEXT("读取用户信息文件失败"),NULL,MB_OK);
	}

	CStdioFile file;
	if(user=="Admin")
		file.Open(strFileName1,CFile::modeRead);
	else
		file.Open(strFileName2,CFile::modeRead);
	CString strText;
	CString strTemp;
	CString user_temp,pwd_temp;//存储从文件中读取到的用户信息
	while(file.ReadString(strTemp))
	{
		strText += strTemp;
		//整行读取后用函数处理字符串，空格隔开分别为用户名和密码
		if(AfxExtractSubString ( user_temp, strTemp, 0, ' ')&&AfxExtractSubString ( pwd_temp, strTemp, 2, ' '))
		{

			if(user==user_temp)
			{
				state=2;
				if(pwd==pwd_temp)
				{
					file.Close();
					//关闭登录对话框
					CDialog::OnOK();
					//权限设置
					
					//打开工资管理系统主窗体
					
					MainTest mdlg;
					if(user=="Admin")
					{
						mdlg.power=1;
					}
					else
					{
						mdlg.power=0;
					}
					mdlg.number=user;
					mdlg.DoModal();
				}
				else
				{
					::MessageBox(NULL,TEXT("密码错误，请重新输入！"),NULL,MB_OK);

				}
			}
		}
		
	}
	if(state==0)
	{
		::MessageBox(NULL,TEXT("此用户不存在！"),NULL,MB_OK);
	}
	file.Close();
}

