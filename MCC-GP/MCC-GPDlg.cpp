
// MCC-GPDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "MCC-GPDlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"
#include "TipDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMCCGPDlg �_�C�A���O



CMCCGPDlg::CMCCGPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MCCGP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_Font_context = new CFont();
	m_Font_context->CreateFont(33, 13, 0, 0, 50,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));

}

CMCCGPDlg::~CMCCGPDlg()
{
	delete m_Font_context;
}



void CMCCGPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMCCGPDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PatientSYS, &CMCCGPDlg::OnBnClickedPatientsys)
	ON_BN_CLICKED(IDC_EmployeeSYS, &CMCCGPDlg::OnBnClickedEmployeesys)
	ON_BN_CLICKED(IDC_Shutdown, &CMCCGPDlg::OnBnClickedShutdown)	
END_MESSAGE_MAP()


// CMCCGPDlg ���b�Z�[�W �n���h���[

BOOL CMCCGPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//AnimateWindow(1000, AW_CENTER);
	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	

	// �����ݒ�
	GetDlgItem(IDC_PatientSYS)->SetFont(m_Font_context);

	GetDlgItem(IDC_EmployeeSYS)->SetFont(m_Font_context);

	GetDlgItem(IDC_Shutdown)->SetFont(m_Font_context);
	

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CMCCGPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CMCCGPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


unsigned int m_LoginFlag = 1;

void CMCCGPDlg::OnBnClickedPatientsys()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
 
    m_LoginFlag = 1;
	
    EndDialog(IDC_PatientSYS);
}


void CMCCGPDlg::OnBnClickedEmployeesys()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	m_LoginFlag = 2;

	EndDialog(IDC_EmployeeSYS);
}


void CMCCGPDlg::OnBnClickedShutdown()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	MessageBox( _T("���肪�Ƃ��������܂����B"), _T("��"), MB_ICONINFORMATION);

	EndDialog(IDC_Shutdown);
}



void CMCCGPDlg::OnCancel()
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊��N���X���Ăяo���Ă��������B
	OnBnClickedShutdown();
}
