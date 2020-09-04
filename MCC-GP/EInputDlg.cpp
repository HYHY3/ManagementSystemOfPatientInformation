// EInputDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "EInputDlg.h"
#include "afxdialogex.h"
#include "EmployeeDlg.h"

// CEInputDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CEInputDlg, CDialogEx)

CEInputDlg::CEInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EInputDlg, pParent)
	, m_Code_EInputDlg(_T(""))
	, m_Name_EInputDlg(_T(""))
	, m_Sex_EInputDlg(_T(""))
	, m_Position_EInputDlg(_T(""))
	, m_Age_EInputDlg(_T(""))
	, m_Birthday_EInputDlg(COleDateTime::GetCurrentTime())
	, m_Phone_EInputDlg(_T(""))
	, m_Address_EInputDlg(_T(""))
	, m_Others_EInputDlg(_T(""))
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(24, 8, 0, 0, 15,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CEInputDlg::~CEInputDlg()
{
	delete m_Font_context;
}

void CEInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ECODESHOW, m_Code_EInputDlg);
	DDX_Text(pDX, IDC_ENAMESHOW, m_Name_EInputDlg);
	DDX_CBString(pDX, IDC_ESEXSHOW, m_Sex_EInputDlg);
	DDX_CBString(pDX, IDC_EPOSITIONSHOW, m_Position_EInputDlg);
	DDX_Text(pDX, IDC_EAGESHOW, m_Age_EInputDlg);
	DDX_DateTimeCtrl(pDX, IDC_EBIRTHDAYSHOW, m_Birthday_EInputDlg);
	DDX_Text(pDX, IDC_EPHONESHOW, m_Phone_EInputDlg);
	DDX_Text(pDX, IDC_EADDRESSSHOW, m_Address_EInputDlg);
	DDX_Text(pDX, IDC_EOTHERSSHOW, m_Others_EInputDlg);
}


BEGIN_MESSAGE_MAP(CEInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EClear, &CEInputDlg::OnBnClickedEclear)
	ON_BN_CLICKED(IDC_ESAVE, &CEInputDlg::OnBnClickedEsave)
END_MESSAGE_MAP()


// CEInputDlg ���b�Z�[�W �n���h���[


BOOL CEInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: �����ɏ�������ǉ����Ă�������

	GetDlgItem(IDC_ECODE)->SetFont(m_Font_context);
	GetDlgItem(IDC_ENAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_ESEX)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPOSITION)->SetFont(m_Font_context);
	GetDlgItem(IDC_EAGE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EBIRTHDAY)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EADDRESS)->SetFont(m_Font_context);
	GetDlgItem(IDC_EOTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_ESAVE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EClear)->SetFont(m_Font_context);
	GetDlgItem(IDC_ECODESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_ENAMESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_ESEXSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPOSITIONSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EAGESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EBIRTHDAYSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPHONESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EADDRESSSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_EOTHERSSHOW)->SetFont(m_Font_context);


	if (m_Flag)
	{
		m_Flag = 0;
		m_CodeNumber = CEmployeeDlg::m_Code_Number.back() + 1;
	}

	CodeNumber_Show();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


unsigned int CEInputDlg::m_CodeNumber_Index = 0;
unsigned int CEInputDlg::m_CodeNumber = 0;
unsigned int CEInputDlg::m_Flag = 1;


void CEInputDlg::OnBnClickedEclear()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	m_Name_EInputDlg = "";
	m_Sex_EInputDlg = "";
	m_Age_EInputDlg = "";
	m_Phone_EInputDlg = "";
	m_Address_EInputDlg = "";
	m_Others_EInputDlg = "";

	UpdateData(FALSE);

}


void CEInputDlg::OnBnClickedEsave()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	UpdateData(TRUE);

	if (m_CodeNumber_Index != CEmployeeDlg::m_Code_Number.size())
	{
		++m_CodeNumber_Index;
	}
	else
	{
		++m_CodeNumber;
	}
	
	EndDialog(IDC_ESAVE);

}



void CEInputDlg::OnOK()
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊��N���X���Ăяo���Ă��������B

	NextDlgCtrl();
	CWnd *pWnd = GetFocus();
	if (pWnd->GetDlgCtrlID() == IDC_ESAVE)
	{
		OnBnClickedEsave();
	}
}

void CEInputDlg::CodeNumber_Show()
{
	if (m_CodeNumber_Index != CEmployeeDlg::m_Code_Number.size())
	{
		m_Code_EInputDlg.Format(_T("k016c-%d"), CEmployeeDlg::m_Code_Number.at(m_CodeNumber_Index));
	}
	else
	{
		m_Code_EInputDlg.Format(_T("k016c-%d"), m_CodeNumber);
	}

	UpdateData(FALSE);
}
