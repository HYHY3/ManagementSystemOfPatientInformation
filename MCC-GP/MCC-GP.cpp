
// MCC-GP.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "MCC-GPDlg.h"
#include "LoginDlg.h"
#include "PatientDlg.h"
#include "EmployeeDlg.h"
#include "EditDlg.h"
#include "EInputDlg.h"
#include "EEditDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMCCGPApp

BEGIN_MESSAGE_MAP(CMCCGPApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMCCGPApp コンストラクション

CMCCGPApp::CMCCGPApp()
{
	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CMCCGPApp オブジェクトです。

CMCCGPApp theApp;


// CMCCGPApp 初期化

BOOL CMCCGPApp::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ダイアログにシェル ツリー ビューまたはシェル リスト ビュー コントロールが
	// 含まれている場合にシェル マネージャーを作成します。
	CShellManager *pShellManager = new CShellManager;

	// MFC コントロールでテーマを有効にするために、"Windows ネイティブ" のビジュアル マネージャーをアクティブ化
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));

	CMCCGPDlg dlg;
	CLoginDlg Logindlg;
	CPatientDlg Patientdlg;
	CEmployeeDlg Employeedlg;
	

	//CEditDlg Editdatadlg;
	//Editdatadlg.DoModal();
	//CEEditDlg EEditdlg;
	//EEditdlg.DoModal();

	//CEInputDlg Einputdlg;
	//Einputdlg.DoModal();

	//Patientdlg.DoModal();
	
	//Employeedlg.DoModal();

	
	while (true)
	{
		switch (dlg.DoModal())
		{
		case IDC_Shutdown:return FALSE;
		case IDC_PatientSYS:
		case IDC_EmployeeSYS:
			switch (Logindlg.DoModal())
			{
			case IDCANCEL:m_LoginFlag = 0; break;
			}
			break;
		}

		if (m_LoginFlag == 1)
		{
			switch (Patientdlg.DoModal())
			{
			case IDC_PLOGOUT:break;
			}

		}
		else if(m_LoginFlag==2)
		{
			switch (Employeedlg.DoModal())
			{
			case IDC_ELOGOUT:break;
			}
		}

	}

	
	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

