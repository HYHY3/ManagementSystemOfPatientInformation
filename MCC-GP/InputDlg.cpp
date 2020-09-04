// InputDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "InputDlg.h"
#include "afxdialogex.h"
#include "PatientDlg.h"

// CInputDlg ダイアログ

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUTDlg, pParent)
	, m_Name_InputDlg(_T(""))
	, m_Sex_InputDlg(_T(""))
	, m_Age_InputDlg(_T(""))
	, m_Phone_InputDlg(_T(""))
	, m_Address_InputDlg(_T(""))
	, m_Others_InputDlg(_T(""))
	, m_Code_InputDlg(_T(""))
	, m_Birthday_InputDlg(COleDateTime::GetCurrentTime())
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(25, 10, 0, 0, 15,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));

}

CInputDlg::~CInputDlg()
{
	delete m_Font_context;
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAMESHOW, m_Name_InputDlg);
	DDX_CBString(pDX, IDC_SEXSHOW, m_Sex_InputDlg);
	DDX_Text(pDX, IDC_AGESHOW, m_Age_InputDlg);
	DDX_Text(pDX, IDC_PHONESHOW, m_Phone_InputDlg);
	DDX_Text(pDX, IDC_ADDRESSSHOW, m_Address_InputDlg);
	DDX_Text(pDX, IDC_OTHERSSHOW, m_Others_InputDlg);
	DDX_Text(pDX, IDC_CODESHOW, m_Code_InputDlg);
	DDX_Text(pDX, IDC_CODESHOW, m_Code_InputDlg);
	DDX_DateTimeCtrl(pDX, IDC_BIRTHDAYSHOW, m_Birthday_InputDlg);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Clear, &CInputDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_SAVE, &CInputDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// CInputDlg メッセージ ハンドラー

BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	GetDlgItem(IDC_CODE)->SetFont(m_Font_context);
	GetDlgItem(IDC_NAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_SEX)->SetFont(m_Font_context);
	GetDlgItem(IDC_AGE)->SetFont(m_Font_context);
	GetDlgItem(IDC_BIRTHDAY)->SetFont(m_Font_context);
	GetDlgItem(IDC_PHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_ADDRESS)->SetFont(m_Font_context);
	GetDlgItem(IDC_OTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_SAVE)->SetFont(m_Font_context);
	GetDlgItem(IDC_Clear)->SetFont(m_Font_context);
	GetDlgItem(IDC_CODESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_NAMESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_SEXSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_AGESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_BIRTHDAYSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_PHONESHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_ADDRESSSHOW)->SetFont(m_Font_context);
	GetDlgItem(IDC_OTHERSSHOW)->SetFont(m_Font_context);
	
	if (m_Flag)
	{
		m_Flag = 0;
		m_CodeNumber = CPatientDlg::m_Code_Number.back()+1;
	}
	
	CodeNumber_Show();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


unsigned int CInputDlg::m_CodeNumber_Index = 0;
unsigned int CInputDlg::m_CodeNumber = 0;
unsigned int CInputDlg::m_Flag = 1;


void CInputDlg::OnBnClickedClear()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	m_Name_InputDlg = "";
	m_Sex_InputDlg = "";
	m_Age_InputDlg = "";
	m_Phone_InputDlg = "";
	m_Address_InputDlg = "";
	m_Others_InputDlg = "";

	UpdateData(FALSE);
}



void CInputDlg::OnBnClickedSave()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	UpdateData(TRUE);

	if (m_CodeNumber_Index != CPatientDlg::m_Code_Number.size())
	{
		++m_CodeNumber_Index;
	}
	else
	{
		++m_CodeNumber;
	}
	
	EndDialog(IDC_SAVE);
}


void CInputDlg::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	NextDlgCtrl();
	CWnd *pWnd = GetFocus();
	if (pWnd->GetDlgCtrlID() == IDC_SAVE)
	{
		OnBnClickedSave();
	}
}


void CInputDlg::CodeNumber_Show()
{
	if (m_CodeNumber_Index != CPatientDlg::m_Code_Number.size())
	{
		m_Code_InputDlg.Format(_T("K016C-%d"), CPatientDlg::m_Code_Number.at(m_CodeNumber_Index));	
	}
	else
	{
		m_Code_InputDlg.Format(_T("K016C-%d"), m_CodeNumber);
	}

	UpdateData(FALSE);
}
