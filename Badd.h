#pragma once
#include<string>
#include"book.h"
#include"afxwin.h"
using namespace std;
// Badd 对话框

class Badd : public CDialogEx
{

	DECLARE_DYNAMIC(Badd)
protected:
	book M_book;
public:
	Badd(book m_book,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Badd();
	book& getbook()
	{ 
		return M_book;
	}

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_add };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	
public:
//	string name;
//	string total;
//	string publish;
//	int writer;
	virtual BOOL OnInitDialog();//初始化界面	
	afx_msg void OnBnClickedOk();
	CString name;
	int num;
	CString publish;
	CString writer;
	afx_msg void OnBnClickedCancel();
};
