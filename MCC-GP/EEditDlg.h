#pragma once


// CEEditDlg ダイアログ

class CEEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEEditDlg)

public:
	CEEditDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CEEditDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EEditDataDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

private:
	CFont *m_Font_context;
public:
	virtual BOOL OnInitDialog();

	CString m_Name_EEditDlg;
	CString m_Phone_EEditDlg;
	CString m_Address_EEditDlg;
	CString m_Position_EEditDlg;
	CString m_Others_EEditDlg;

	//CString m_CodeNumber_Editdlg;
	
	afx_msg void OnBnClickedEsave();
	virtual void OnOK();
};
