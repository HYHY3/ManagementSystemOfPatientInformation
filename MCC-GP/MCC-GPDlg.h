
// MCC-GPDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once


// CMCCGPDlg �_�C�A���O
class CMCCGPDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CMCCGPDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[
	~CMCCGPDlg();


// �_�C�A���O �f�[�^
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MCCGP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedPatientsys();
	afx_msg void OnBnClickedEmployeesys();
	afx_msg void OnBnClickedShutdown();

private:
	CFont *m_Font_context;

	virtual void OnCancel();
};
