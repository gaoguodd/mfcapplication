
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include"Badd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_strFind(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lsycbooklist);
	//DDX_Control(pDX, IDC_LIST1, m_lsycbooklist);
	DDX_Text(pDX, IDC_EDIT1, m_strFind);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_add, &CMFCApplication1Dlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTON_del, &CMFCApplication1Dlg::OnBnClickedButtondel)
	ON_BN_CLICKED(IDC_BUTTON_edi, &CMFCApplication1Dlg::OnBnClickedButtonedi)
	ON_WM_DESTROY()
	ON_WM_DESTROY()
	//ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT_find, &CMFCApplication1Dlg::OnChangeEditFind)
	ON_BN_CLICKED(IDC_BUTTON_exit, &CMFCApplication1Dlg::OnBnClickedButtonexit)
	ON_COMMAND(ID_save, &CMFCApplication1Dlg::Onsave)
	ON_BN_CLICKED(IDC_BUTTON_Save, &CMFCApplication1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_Load, &CMFCApplication1Dlg::OnBnClickedButtonLoad)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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


	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设计界面
	IninBookListCtrl();

	//自动保存数据————————————————————开始
	
		DoLoadFile(m_strDerGCLFileName);
		RefreshBookListCtrl(m_lstbook);

	
	//自动保存数据————————————————————结束


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCApplication1Dlg::IninBookListCtrl(void)
{
	//界面设计
	m_lsycbooklist.SetExtendedStyle(m_lsycbooklist.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	//设计列
	m_lsycbooklist.InsertColumn(0, _T("书名"), LVCFMT_CENTER, 150);
	m_lsycbooklist.InsertColumn(1, _T("出版社"), LVCFMT_CENTER, 150);
	m_lsycbooklist.InsertColumn(2, _T("作者"), LVCFMT_CENTER, 120);
	m_lsycbooklist.InsertColumn(3, _T("库存"), LVCFMT_CENTER, 100);
	m_lsycbooklist.InsertColumn(4, _T("备注"), LVCFMT_CENTER, 220);
}
int CMFCApplication1Dlg::GetCurSel()
{
	POSITION pos = m_lsycbooklist.GetFirstSelectedItemPosition();
	return m_lsycbooklist.GetNextSelectedItem(pos);
}
void CMFCApplication1Dlg::RefreshBookListCtrl(Booklist& booklist, int iCuiSel)
{
	int iLastSel = GetCurSel();
	m_lsycbooklist.DeleteAllItems();


	for (int i = 0; i < booklist.GetSize(); i++)
	{
		m_lsycbooklist.InsertItem(i, booklist[i].Getname());
		m_lsycbooklist.SetItemText(i, 1, booklist[i].Getpub());
		m_lsycbooklist.SetItemText(i, 2, booklist[i].Getwriter());
		m_lsycbooklist.SetItemText(i, 3,booklist[i].Gettotal());
	}
	if (iCuiSel < 0)
	{
		if (iLastSel < 0)
			iCuiSel = booklist.GetSize() > 0 ? 0 : -1;
		else
			iCuiSel = min(booklist.GetSize() - 1, iLastSel);
	}
	else
	{
		m_lsycbooklist.SetFocus();
		m_lsycbooklist.SetItemState(iCuiSel, LVIS_SELECTED, LVIS_SELECTED);
	}
}



void CMFCApplication1Dlg::OnBnClickedButtonadd()
{
	// TODO: 在此添加控件通知处理程序代码
	book bookDef;
	Badd  digEdit(bookDef, this);
	int iRet = digEdit.DoModal();
	if (iRet == IDOK)
	{
		m_lstbook.Add(digEdit.getbook());
		RefreshBookListCtrl(m_lstbook,m_lstbook.GetSize() - 1);
	}
}


void CMFCApplication1Dlg::OnBnClickedButtondel()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCurSel = GetCurSel();
	if(iCurSel < 0)return;
	CString strHint=_T("确认删除《");
	strHint += m_lstbook[iCurSel].Getname();
	strHint += _T("》吗？");
	if (MessageBox(strHint, _T("确认删除"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		m_lstbook.RemoveAt(iCurSel);
	RefreshBookListCtrl(m_lstbook, iCurSel);
}


void CMFCApplication1Dlg::OnBnClickedButtonedi()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCurSel = GetCurSel();
	if (iCurSel < 0)return;
	Badd digEdit(m_lstbook[iCurSel], this);
	int iRet = digEdit.DoModal();
	if (iRet == IDOK)
	{
		m_lstbook[iCurSel] = digEdit.getbook();
		RefreshBookListCtrl(m_lstbook, iCurSel);
	}
}

BOOL CMFCApplication1Dlg::DoSaveFile(CString strFileName)
{
	CFile fileGCL(strFileName, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&fileGCL, CArchive::store);
	m_lstbook.Serialize(ar);
	return TRUE;
}
BOOL CMFCApplication1Dlg::DoLoadFile(CString strFileName)
{
	CFile fileGCL(strFileName, CFile::modeRead);
	CArchive ar(&fileGCL, CArchive::load);
	m_lstbook.Serialize(ar);
	return TRUE;
}

void CMFCApplication1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	DoSaveFile(m_strDerGCLFileName);
	// TODO: 在此处添加消息处理程序代码

}





void CMFCApplication1Dlg::OnChangeEditFind()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_lstFindBook.RemoveAll();
	for (int i = 0; i < m_lstbook.GetSize(); i++)
	{
		if (m_lstbook[i].Getname().Find(m_strFind) != -1||m_lstbook[i].Getwriter().Find(m_strFind)!=-1)
		{
			m_lstFindBook.Add(m_lstbook[i]);
		}
		//if (m_lstFindBook.GetSize() > 0)
		//{
		//	RefreshBookListCtrl(m_lstFindBook);
		//}
	}
	RefreshBookListCtrl(m_lstFindBook);
}


void CMFCApplication1Dlg::OnBnClickedButtonexit()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CMFCApplication1Dlg::Onsave()
{
	// TODO: 在此添加命令处理程序代码
	//OnBnClickedButton1();
}



void CMFCApplication1Dlg::OnBnClickedButtonSave()
{
	CFileDialog dlgFile(FALSE, _T(".gcl"), NULL, OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY, _T("书籍信息(*.gcl)|*.gcl||"), NULL);
	if (dlgFile.DoModal() != IDOK)
	{
		m_lsycbooklist.SetFocus();
		return;
	}
	DoSaveFile(dlgFile.GetPathName());
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedButtonLoad()
{
	CFileDialog dlgFile(TRUE, _T(".gcl"), NULL, OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY, _T("书籍信息(*.gcl)|*.gcl||"), NULL);
	if (dlgFile.DoModal() != IDOK)
	{
		m_lsycbooklist.SetFocus();
		return;
	}
	if (DoLoadFile(dlgFile.GetPathName()))
		RefreshBookListCtrl(m_lstbook, 0);
}