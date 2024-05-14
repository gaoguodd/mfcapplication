// Badd.cpp: 实现文件
//
#include<string>
#include"book.h"
#include "pch.h"
#include "MFCApplication1.h"
#include "Badd.h"
#include "afxdialogex.h"


// Badd 对话框

IMPLEMENT_DYNAMIC(Badd, CDialogEx)

Badd::Badd(book m_book,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_add, pParent)
	,name(m_book.Getname()),publish(m_book.Getpub()),writer(m_book.Getwriter()),num(0)
{
	M_book = m_book;
}

Badd::~Badd()
{
}

void Badd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_name, name);
	//  DDX_Control(pDX, IDC_EDIT_num, total);
	//  DDX_Control(pDX, IDC_EDIT_publish, publish);
	//  DDX_Control(pDX, IDC_EDIT_writer, writer);
	DDX_Text(pDX, IDC_EDIT_name, name);
	DDX_Text(pDX, IDC_EDIT_num, num);
	DDX_Text(pDX, IDC_EDIT_publish, publish);
	DDX_Text(pDX, IDC_EDIT_writer, writer);
}


BEGIN_MESSAGE_MAP(Badd, CDialogEx)
	ON_BN_CLICKED(IDOK, &Badd::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Badd::OnBnClickedCancel)
END_MESSAGE_MAP()


// Badd 消息处理程序


BOOL Badd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Badd::OnBnClickedOk()
{
	UpdateData(TRUE);
	M_book = book(name, publish, writer, num);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Badd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	return;
}
