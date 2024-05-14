
// MFCApplication1Dlg.h: 头文件
//

#pragma once
#include"Booklist.h"
#include<string>
using namespace std;

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	void IninBookListCtrl();//ListCtrl样式/界面的设置
	void RefreshBookListCtrl(Booklist& booklist, int iCurSel = -1);
	int GetCurSel();
	BOOL DoSaveFile(CString strFileName);
	BOOL DoLoadFile(CString strFileName);
protected:
	Booklist m_lstbook;
	CString m_strDerGCLFileName=_T("wtf.txt");//默认存储路径；
	Booklist m_lstFindBook;
public:
	CListCtrl m_lsycbooklist;
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtondel();
	afx_msg void OnBnClickedButtonedi();
	afx_msg void OnDestroy();
	CString m_strFind;
	afx_msg void OnChangeEditFind();
	afx_msg void OnBnClickedButtonexit();
	afx_msg void Onsave();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();
};
