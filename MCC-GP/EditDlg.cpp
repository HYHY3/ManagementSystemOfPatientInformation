// EditDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "EditDlg.h"
#include "afxdialogex.h"
#include "TipDlg.h"


// CEditDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CEditDlg, CDialogEx)

CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EditDataDlg, pParent)
	, m_Address_EditDlg(_T(""))
	, m_Phone_EditDlg(_T(""))
	, m_Others_EditDlg(_T(""))
	, m_Name_EditDlg(_T(""))
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(30, 10, 0, 0, 20,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CEditDlg::~CEditDlg()
{
	delete m_Font_context;
}

void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITADDRESS, m_Address_EditDlg);
	DDX_Text(pDX, IDC_EDITPHONE, m_Phone_EditDlg);
	DDX_Text(pDX, IDC_EDITOTHERS, m_Others_EditDlg);
	DDX_Text(pDX, IDC_EDITNAME, m_Name_EditDlg);
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SAVE, &CEditDlg::OnBnClickedSave)
	ON_COMMAND(IDOK, &CEditDlg::OnIdok)
	ON_BN_CLICKED(IDC_DETAIL, &CEditDlg::OnBnClickedDetail)
END_MESSAGE_MAP()


// CEditDlg ���b�Z�[�W �n���h���[


BOOL CEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: �����ɏ�������ǉ����Ă�������

	GetDlgItem(IDC_NAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_CONANDMED)->SetFont(m_Font_context);
	GetDlgItem(IDC_OTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_PHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_ADDRESS)->SetFont(m_Font_context);
	
	GetDlgItem(IDC_EDITNAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_DETAIL)->SetFont(m_Font_context);
	GetDlgItem(IDC_EDITOTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_EDITPHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EDITADDRESS)->SetFont(m_Font_context);
	GetDlgItem(IDC_SAVE)->SetFont(m_Font_context);


	//CTime time = CTime::GetCurrentTime();
	//m_Condition_EditDlg += time.Format(_T("(\n����%Y-%m-%d)"));
	//UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}




void CEditDlg::OnBnClickedSave()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	if (IDYES == MessageBox(_T("���ҏ��̕ҏW�����s���܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
	{
		UpdateData(TRUE);
		EndDialog(IDC_SAVE);
	}
	else
	{
		//EndDialog(IDCANCEL);
		UpdateData(FALSE);
	}
	
}


void CEditDlg::OnIdok()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	NextDlgCtrl();
	CWnd *pWnd = GetFocus();
	if (pWnd->GetDlgCtrlID() == IDC_SAVE)
	{
		OnBnClickedSave();
	}
}


void CEditDlg::OnBnClickedDetail()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	UpdateData(TRUE);

	CTipDlg dlg;
	dlg.m_CodeNumber_Tipdlg= _ttoi(m_CodeNumber_Editdlg.Right(m_CodeNumber_Editdlg.GetLength()-6))-101;
	dlg.m_Name_Tipdlg = m_Name_EditDlg;

	switch (dlg.DoModal())
	{
	case IDCANCEL:break;
	default:break;
	}
	
}
