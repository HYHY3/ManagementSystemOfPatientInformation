#pragma once


// CEEditDlg �_�C�A���O

class CEEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEEditDlg)

public:
	CEEditDlg(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CEEditDlg();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EEditDataDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

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
