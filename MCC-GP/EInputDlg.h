#pragma once
#include "ATLComTime.h"


// CEInputDlg ダイアログ

class CEInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEInputDlg)

public:
	CEInputDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CEInputDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EInputDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
private:
	CFont *m_Font_context;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEclear();

	CString m_Code_EInputDlg;
	CString m_Name_EInputDlg;
	CString m_Sex_EInputDlg;
	CString m_Position_EInputDlg;
	CString m_Age_EInputDlg;
	COleDateTime m_Birthday_EInputDlg;
	CString m_Phone_EInputDlg;
	CString m_Address_EInputDlg;
	CString m_Others_EInputDlg;

	virtual void OnOK();
	afx_msg void OnBnClickedEsave();

	static unsigned int m_CodeNumber_Index;
	static unsigned int m_CodeNumber;
	static unsigned int m_Flag;
	void CodeNumber_Show();
};
