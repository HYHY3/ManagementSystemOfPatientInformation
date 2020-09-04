
// MCC-GPDlg.h : ヘッダー ファイル
//

#pragma once


// CMCCGPDlg ダイアログ
class CMCCGPDlg : public CDialogEx
{
// コンストラクション
public:
	CMCCGPDlg(CWnd* pParent = NULL);	// 標準コンストラクター
	~CMCCGPDlg();


// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MCCGP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
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
