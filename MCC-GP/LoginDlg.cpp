// LoginDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LoginDlg, pParent)
	, m_UserName(_T(""))
	, m_UserPassword(_T(""))
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(35, 15, 0, 0, 20,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));

	m_Font_title = new CFont();
	m_Font_title->CreateFont(40, 20, 0, 0, 18,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CLoginDlg::~CLoginDlg()
{
	delete m_Font_context;
	delete m_Font_title;
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_UserName, m_UserName);
	DDX_Text(pDX, IDC_PassWord, m_UserPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &CLoginDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_Clear, &CLoginDlg::OnBnClickedClear)
END_MESSAGE_MAP()



//���[�g����
const CString USER_ROOT = _T("K016C0000");
const CString PASSWORD_ROOT = _T("123450");


//��ʌ���
const CString USER_PATIENT = _T("K016C1111");
const CString PASSWORD_PATIENT = _T("123455");

const CString USER_EMPLOYEE = _T("K016C2222");
const CString PASSWORD_EMPLOYEE = _T("123445");


unsigned int m_LoginAdmin = 1;


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: �������������ɒǉ����܂��B

	// �����ݒ�
	GetDlgItem(IDC_STATIC)->SetFont(m_Font_context);
	GetDlgItem(IDC_STATIC1)->SetFont(m_Font_context);

	GetDlgItem(IDC_UserName)->SetFont(m_Font_context);
	GetDlgItem(IDC_PassWord)->SetFont(m_Font_context);

	GetDlgItem(IDC_Login)->SetFont(m_Font_context);
	GetDlgItem(IDC_Clear)->SetFont(m_Font_context);

	GetDlgItem(IDC_Title)->SetFont(m_Font_title);

	m_UserName = "";
    m_UserPassword="";
	UpdateData(FALSE);

	if (m_LoginFlag == 1)
	{
		GetDlgItem(IDC_Title)->SetWindowText(_T("���ҏ��V�X�e��"));
	}
	else 
	{
		GetDlgItem(IDC_Title)->SetWindowText(_T("�]�ƈ����V�X�e��"));
	}


	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// CLoginDlg ���b�Z�[�W �n���h���[


void CLoginDlg::OnBnClickedLogin()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	UpdateData(TRUE);

	if (m_LoginFlag == 1)
	{
		if (m_UserName == USER_PATIENT && m_UserPassword == PASSWORD_PATIENT)
		{
			m_LoginAdmin = 0;
			MessageBox(_T("���҃V�X�e���Ƀ��O�C������!"), _T("��(����)"), MB_ICONINFORMATION);
			EndDialog(IDC_Login);
		}
		else if (m_UserName == USER_ROOT && m_UserPassword == PASSWORD_ROOT)
		{
			m_LoginAdmin = 1;
			MessageBox(_T("���҃V�X�e���Ƀ��O�C������!"), _T("��(���[�g)"), MB_ICONINFORMATION);
			EndDialog(IDC_Login);
		}
		else
		{
			MessageBox(_T("���[�U�[���ƃp�X���[�h�͈�v�ł͂���܂���!"), _T("��"), MB_ICONEXCLAMATION);
		}
	}
	else
	{
		if (m_UserName == USER_EMPLOYEE && m_UserPassword == PASSWORD_EMPLOYEE)
		{
			m_LoginAdmin = 0;
			MessageBox(_T("�]�ƈ��V�X�e���Ƀ��O�C������!"), _T("��(����)"), MB_ICONINFORMATION);
			EndDialog(IDC_Login);
		}
		else if (m_UserName == USER_ROOT && m_UserPassword == PASSWORD_ROOT)
		{
			m_LoginAdmin = 1;
			MessageBox(_T("�]�ƈ��V�X�e���Ƀ��O�C������!"), _T("��(���[�g)"), MB_ICONINFORMATION);
			EndDialog(IDC_Login);
		}
		else
		{
			MessageBox(_T("���[�U�[���ƃp�X���[�h�͈�v�ł͂���܂���!"), _T("��"), MB_ICONEXCLAMATION);
		}
	}
}


void CLoginDlg::OnBnClickedClear()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	m_UserName = "";
	m_UserPassword = "";

	UpdateData(FALSE);

}



void CLoginDlg::OnOK()
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊��N���X���Ăяo���Ă��������B

	NextDlgCtrl();
	CWnd *pWnd = GetFocus();
	if (pWnd->GetDlgCtrlID() == IDC_Login)
	{
		OnBnClickedLogin();
	}
}
