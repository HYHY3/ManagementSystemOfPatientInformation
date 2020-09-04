
// MCC-GPDlg.cpp : 実装ファイル
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


// CMCCGPDlg ダイアログ



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


// CMCCGPDlg メッセージ ハンドラー

BOOL CMCCGPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//AnimateWindow(1000, AW_CENTER);
	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	

	// 文字設定
	GetDlgItem(IDC_PatientSYS)->SetFont(m_Font_context);

	GetDlgItem(IDC_EmployeeSYS)->SetFont(m_Font_context);

	GetDlgItem(IDC_Shutdown)->SetFont(m_Font_context);
	

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMCCGPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMCCGPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


unsigned int m_LoginFlag = 1;

void CMCCGPDlg::OnBnClickedPatientsys()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
 
    m_LoginFlag = 1;
	
    EndDialog(IDC_PatientSYS);
}


void CMCCGPDlg::OnBnClickedEmployeesys()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	m_LoginFlag = 2;

	EndDialog(IDC_EmployeeSYS);
}


void CMCCGPDlg::OnBnClickedShutdown()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	MessageBox( _T("ありがとうございました。"), _T("提示"), MB_ICONINFORMATION);

	EndDialog(IDC_Shutdown);
}



void CMCCGPDlg::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。
	OnBnClickedShutdown();
}
