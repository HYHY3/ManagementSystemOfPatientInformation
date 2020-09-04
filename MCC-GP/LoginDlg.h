#pragma once


// CLoginDlg ダイアログ

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CLoginDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoginDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual BOOL OnInitDialog();


	DECLARE_MESSAGE_MAP()
private:
	CFont *m_Font_context, *m_Font_title;

public:
	CString m_UserName;
	CString m_UserPassword;
	afx_msg void OnBnClickedLogin();
	afx_msg void OnBnClickedClear();
	virtual void OnOK();
	
};

