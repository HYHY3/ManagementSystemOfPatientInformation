// EEditDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "EEditDlg.h"
#include "afxdialogex.h"


// CEEditDlg ダイアログ

IMPLEMENT_DYNAMIC(CEEditDlg, CDialogEx)

CEEditDlg::CEEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EEditDataDlg, pParent)
	, m_Name_EEditDlg(_T(""))
	, m_Phone_EEditDlg(_T(""))
	, m_Address_EEditDlg(_T(""))
	, m_Position_EEditDlg(_T(""))
	, m_Others_EEditDlg(_T(""))
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(30, 10, 0, 0, 20,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CEEditDlg::~CEEditDlg()
{
	delete m_Font_context;
}

void CEEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EEDITNAME, m_Name_EEditDlg);
	DDX_Text(pDX, IDC_EEDITPHONE, m_Phone_EEditDlg);
	DDX_Text(pDX, IDC_EEDITADDRESS, m_Address_EEditDlg);
	DDX_CBString(pDX, IDC_EEDITPOSITION, m_Position_EEditDlg);
	DDX_Text(pDX, IDC_EEDITOTHERS, m_Others_EEditDlg);
}


BEGIN_MESSAGE_MAP(CEEditDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ESAVE, &CEEditDlg::OnBnClickedEsave)
END_MESSAGE_MAP()


// CEEditDlg メッセージ ハンドラー


BOOL CEEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください


	GetDlgItem(IDC_ENAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPOSITION)->SetFont(m_Font_context);
	GetDlgItem(IDC_EOTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_EPHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EADDRESS)->SetFont(m_Font_context);

	GetDlgItem(IDC_EEDITNAME)->SetFont(m_Font_context);
	GetDlgItem(IDC_EEDITPOSITION)->SetFont(m_Font_context);
	GetDlgItem(IDC_EEDITOTHERS)->SetFont(m_Font_context);
	GetDlgItem(IDC_EEDITPHONE)->SetFont(m_Font_context);
	GetDlgItem(IDC_EEDITADDRESS)->SetFont(m_Font_context);
	GetDlgItem(IDC_ESAVE)->SetFont(m_Font_context);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void CEEditDlg::OnBnClickedEsave()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (IDYES == MessageBox(_T("従業員情報の編集を実行しますか。"), _T("提示"), MB_ICONINFORMATION | MB_YESNO))
	{
		UpdateData(TRUE);
		EndDialog(IDC_ESAVE);
	}
	else
	{
		//EndDialog(IDCANCEL);
		UpdateData(FALSE);
	}

}


void CEEditDlg::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	NextDlgCtrl();
	CWnd *pWnd = GetFocus();
	if (pWnd->GetDlgCtrlID() == IDC_ESAVE)
	{
		OnBnClickedEsave();
	}
}
