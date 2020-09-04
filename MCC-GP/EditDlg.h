#pragma once


// CEditDlg ダイアログ

class CEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditDlg)

public:
	CEditDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CEditDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EditDataDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
private:
	CFont *m_Font_context;
public:

	virtual BOOL OnInitDialog();

	CString m_Address_EditDlg;
	CString m_Phone_EditDlg;
	CString m_Others_EditDlg;
	CString m_Name_EditDlg;

	CString m_CodeNumber_Editdlg;

	afx_msg void OnBnClickedSave();
	afx_msg void OnIdok();
	afx_msg void OnBnClickedDetail();

};
