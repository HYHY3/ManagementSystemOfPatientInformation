#pragma once
#include "ATLComTime.h"


// CInputDlg �_�C�A���O

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // �W���R���X�g���N�^�[
	virtual ~CInputDlg();

// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUTDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()

private:
	CFont *m_Font_context;


public:
	afx_msg void OnBnClickedClear();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSave();
	virtual void OnOK();
	
	CString m_Code_InputDlg;
	CString m_Name_InputDlg;
	CString m_Sex_InputDlg;
	CString m_Age_InputDlg;
	COleDateTime m_Birthday_InputDlg;
	CString m_Phone_InputDlg;
	CString m_Address_InputDlg;
	CString m_Others_InputDlg;

	void CodeNumber_Show();
	static unsigned int m_CodeNumber_Index;
	static unsigned int m_CodeNumber;
	static unsigned int m_Flag;
};
