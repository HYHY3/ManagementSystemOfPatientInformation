#pragma once

#include <vector>
#include "ATLComTime.h"


// CTipDlg ダイアログ

class CTipDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTipDlg)

public:
	CTipDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	~CTipDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TipDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
	CFont *m_Font;

	struct HistoryFileData
	{
		TCHAR m_Date_buf[12];
		TCHAR m_Condition_buf[32];
		TCHAR m_Medicine_buf[32];
	};
	HistoryFileData patient_history;
	std::vector<HistoryFileData> Patient_Data_History;

	COleDateTime m_Date_Tipdlg;
	CString m_Condition_Tipdlg;
	CString m_Medicine_Tipdlg;

	virtual BOOL OnInitDialog();
	void Detail_Edit();
	void Detail_Delete(CListCtrl *, POSITION);
	void Detail_Read();
	afx_msg void OnBnClickedEditSave();
	afx_msg void OnBnClickedEditDel();
	afx_msg void OnIdcancel();

	static unsigned int m_Flag;

	CString m_Name_Tipdlg;
	unsigned int m_CodeNumber_Tipdlg;
	
	
};
