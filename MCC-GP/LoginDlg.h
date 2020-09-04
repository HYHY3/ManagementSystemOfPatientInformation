#pragma once


// CLoginDlg �_�C�A���O

class CLoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CLoginDlg();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoginDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
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

