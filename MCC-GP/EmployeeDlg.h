#pragma once
#include <vector>
#include "EInputDlg.h"

// CEmployeeDlg ダイアログ

class CEmployeeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeDlg)

public:
	CEmployeeDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CEmployeeDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EmployeeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CFont *m_Font_context;

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEadd();
	afx_msg void OnBnClickedEdel();
	afx_msg void OnBnClickedEedit();
	afx_msg void OnBnClickedEsave();
	afx_msg void OnBnClickedElogout();
	virtual void OnCancel();

	struct FileData
	{
		TCHAR m_Code_buf[16];
		TCHAR m_Name_buf[32];
		TCHAR m_Sex_buf[4];
		TCHAR m_Position_buf[6];
		TCHAR m_Age_buf[4];
		TCHAR m_Birthday_buf[32];
		TCHAR m_Phone_buf[16];
		TCHAR m_Address_buf[64];
		TCHAR m_Others_buf[128];

	};
	FileData employee;
	std::vector<FileData> Employee_Data;

	static unsigned int m_nCount_EmployeeDlg;
	static unsigned int m_ElistFlag_EmployeeDlg;
	static std::vector<unsigned int>m_Code_Number;


	void Insert_Data(const CEInputDlg &);
	void FileData_Read();
	void List_Show();
	void CodeNumber_Check();
	void List_CodeNumber_Sort(std::vector<unsigned int> &);
	void Delete_nItem(CListCtrl *, POSITION);
	void Edit_nItem(CListCtrl *, POSITION );
	void List_Data_Sort();
};
