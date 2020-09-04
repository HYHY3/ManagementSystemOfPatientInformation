#pragma once

#include <vector>
#include "InputDlg.h"

// CPatientDlg ダイアログ

class CPatientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPatientDlg)

public:
	CPatientDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CPatientDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PatientDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CFont *m_Font_context;
	//unsigned int m_nCount_Load;
	
	struct FileData
	{
		TCHAR m_Code_buf[16];
		//unsigned int m_Code_buf;
		TCHAR m_Name_buf[32];
		TCHAR m_Sex_buf[4];
		TCHAR m_Age_buf[4];
		TCHAR m_Birthday_buf[32];
		TCHAR m_Phone_buf[16];
		TCHAR m_Address_buf[64];
		TCHAR m_Others_buf[128];
	};
	FileData patient;
	std::vector<FileData> Patient_Data;


public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPedit();
	afx_msg void OnBnClickedPadd();
	afx_msg void OnBnClickedPdel();
	afx_msg void OnBnClickedPlogout();
	virtual void OnCancel();
	afx_msg void OnBnClickedPsave();

	static unsigned int m_nCount_PatientDlg;
	static unsigned int m_PlistFlag_PatientDlg;
	static std::vector<unsigned int>m_Code_Number;

	void FileData_Read();
	void List_Show();
	void Delete_nItem(CListCtrl *, POSITION);
	void Edit_nItem(CListCtrl *, POSITION);
	void Insert_Data(const CInputDlg &);
    void CodeNumber_Check();
	void List_CodeNumber_Sort(std::vector<unsigned int>&);

	void List_Data_Sort();
	
};
