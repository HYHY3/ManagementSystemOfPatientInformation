// PatientDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "PatientDlg.h"
#include "afxdialogex.h"
#include "InputDlg.h"
#include "EditDlg.h"
#include "TipDlg.h"
#include<algorithm> 


// CPatientDlg ダイアログ

IMPLEMENT_DYNAMIC(CPatientDlg, CDialogEx)

CPatientDlg::CPatientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PatientDlg, pParent)
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(23, 8, 0, 0, 15,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));

}

CPatientDlg::~CPatientDlg()
{
	delete m_Font_context;
}

void CPatientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPatientDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PEDIT, &CPatientDlg::OnBnClickedPedit)
	ON_BN_CLICKED(IDC_PADD, &CPatientDlg::OnBnClickedPadd)
	ON_BN_CLICKED(IDC_PDEL, &CPatientDlg::OnBnClickedPdel)
	ON_BN_CLICKED(IDC_PLOGOUT, &CPatientDlg::OnBnClickedPlogout)
	ON_BN_CLICKED(IDC_PSAVE, &CPatientDlg::OnBnClickedPsave)
END_MESSAGE_MAP()


// CPatientDlg メッセージ ハンドラー


BOOL CPatientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください

	GetDlgItem(IDC_PADD)->SetFont(m_Font_context);
	GetDlgItem(IDC_PDEL)->SetFont(m_Font_context);
	GetDlgItem(IDC_PEDIT)->SetFont(m_Font_context);
	GetDlgItem(IDC_PSAVE)->SetFont(m_Font_context);
	GetDlgItem(IDC_PLOGOUT)->SetFont(m_Font_context);

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_PLIST);
	pList->SetFont(m_Font_context);
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetBkColor(RGB(200, 230, 252));
	pList->SetTextColor(RGB(0, 0, 252));
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	pList->InsertColumn(0, _T("コード"), LVCFMT_CENTER, 120);
	pList->InsertColumn(1, _T("名前"), LVCFMT_CENTER, 135);
	pList->InsertColumn(2, _T("性別"), LVCFMT_CENTER, 50);
	pList->InsertColumn(3, _T("備考"), LVCFMT_CENTER, 170);
	pList->InsertColumn(4, _T("年齢"), LVCFMT_CENTER, 50);
	pList->InsertColumn(5, _T("生年月日"), LVCFMT_CENTER, 150);
	pList->InsertColumn(6, _T("電話番号"), LVCFMT_CENTER, 150);
	pList->InsertColumn(7, _T("住所"), LVCFMT_CENTER, 360);

	pList->SetColumnWidth(4, LVSCW_AUTOSIZE_USEHEADER);    


	FileData_Read();

	CInputDlg::m_CodeNumber_Index = 0;
	CInputDlg::m_CodeNumber = 0;
	m_Code_Number.clear();
	CodeNumber_Check();
	CInputDlg::m_Flag = 1;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


unsigned int CPatientDlg::m_nCount_PatientDlg = 0;
unsigned int CPatientDlg::m_PlistFlag_PatientDlg = 0;
std::vector<unsigned int>CPatientDlg::m_Code_Number;

void CPatientDlg::OnBnClickedPadd()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CInputDlg Inputdlg;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_PLIST);

	m_nCount_PatientDlg = pList->GetItemCount();
	switch (Inputdlg.DoModal())
	{
	case IDCANCEL: break;
	case IDC_SAVE:m_PlistFlag_PatientDlg = 1;
		pList->InsertItem(m_nCount_PatientDlg, Inputdlg.m_Code_InputDlg);
		pList->SetItemText(m_nCount_PatientDlg, 1, Inputdlg.m_Name_InputDlg);
		pList->SetItemText(m_nCount_PatientDlg, 2, Inputdlg.m_Sex_InputDlg);
		pList->SetItemText(m_nCount_PatientDlg, 3, Inputdlg.m_Others_InputDlg);
		if (m_LoginAdmin)
		{//ルート権限
			pList->SetItemText(m_nCount_PatientDlg, 4, Inputdlg.m_Age_InputDlg);
			pList->SetItemText(m_nCount_PatientDlg, 5, Inputdlg.m_Birthday_InputDlg.Format(_T("%Y年%m月%d日")));
			pList->SetItemText(m_nCount_PatientDlg, 6, Inputdlg.m_Phone_InputDlg);
			pList->SetItemText(m_nCount_PatientDlg, 7, Inputdlg.m_Address_InputDlg);
		}
		Insert_Data(Inputdlg);

		MessageBox(_T("引き続き、患者の診察情報を入力してください。"), _T("提示"), MB_ICONINFORMATION);
		CTipDlg tipdlg;
		tipdlg.m_CodeNumber_Tipdlg = _ttoi(Inputdlg.m_Code_InputDlg.Right(Inputdlg.m_Code_InputDlg.GetLength() - 6)) - 101;
		tipdlg.m_Name_Tipdlg = Inputdlg.m_Name_InputDlg;
		switch (tipdlg.DoModal())
		{
		case IDCANCEL:MessageBox(_T("患者情報の登録が完了しました。"), _T("提示"), MB_ICONINFORMATION); break;
		default:break;
		}
		break;
	}


}


void CPatientDlg::Delete_nItem(CListCtrl *plist, POSITION nItemPos)
{
	static unsigned int del_flag = 0;
	int nItem = plist->GetNextSelectedItem(nItemPos);

	if (nItemPos)
	{
		Delete_nItem(plist, nItemPos);
	}
	else
	{
		del_flag = 1;
	}

	if (del_flag == 1)
	{
		if (IDYES == MessageBox(_T("選ばれた患者のすべて情報を削除しますか。"), _T("提示"), MB_ICONINFORMATION | MB_YESNO))
		{
			del_flag = 0;
			m_PlistFlag_PatientDlg = 1;
			CString str = plist->GetItemText(nItem, 0);
			str.Format(_T("%d"), _ttoi(str.Right(str.GetLength() - 6)) - 100);
			CFile::Remove(_T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_History\\Patient_Data_File_") +str+_T(".txt"));
			plist->DeleteItem(nItem);
			Patient_Data.erase(Patient_Data.begin() + nItem);
		}
		else
		{
			del_flag = 2;
		}
	}
	else if (del_flag == 0)
	{
		CString str = plist->GetItemText(nItem, 0);
		str.Format(_T("%d"), _ttoi(str.Right(str.GetLength() - 6)) - 100);
		CFile::Remove(_T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_History\\Patient_Data_File_") + str + _T(".txt"));
		plist->DeleteItem(nItem);
		Patient_Data.erase(Patient_Data.begin() + nItem);
	}

}


void CPatientDlg::OnBnClickedPdel()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (m_LoginAdmin)
	{
		CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_PLIST);
		m_nCount_PatientDlg = pList->GetItemCount();
		if (m_nCount_PatientDlg == 0)
		{
			MessageBox(_T("患者情報が入ってないので、削除できません。"), _T("提示"), MB_ICONINFORMATION);
			return;
		}
		POSITION nPos = pList->GetFirstSelectedItemPosition();
		if (nPos == NULL)
		{
			MessageBox(_T("患者情報を選んでください。"), _T("提示"), MB_ICONINFORMATION);
		}
		else
		{
			Delete_nItem(pList, nPos);
			CInputDlg::m_CodeNumber_Index = 0;
			CInputDlg::m_CodeNumber = 0;
			m_Code_Number.clear();
			CodeNumber_Check();
			CInputDlg::m_Flag = 1;
		}
	}
	else
	{
		MessageBox(_T("患者情報を削除する権限がありません。"), _T("提示"), MB_ICONINFORMATION);
	}

}


void CPatientDlg::Edit_nItem(CListCtrl *plist, POSITION nItemPos)
{
	CEditDlg editdlg;
	int nItem = plist->GetNextSelectedItem(nItemPos);

	editdlg.m_CodeNumber_Editdlg = plist->GetItemText(nItem, 0);
	editdlg.m_Name_EditDlg = plist->GetItemText(nItem, 1);
	editdlg.m_Others_EditDlg = plist->GetItemText(nItem, 3);
	editdlg.m_Phone_EditDlg = plist->GetItemText(nItem, 6);
	editdlg.m_Address_EditDlg = plist->GetItemText(nItem, 7);

	switch (editdlg.DoModal())
	{
	case IDCANCEL:break;
	case IDC_SAVE:
		m_PlistFlag_PatientDlg = 1;
		plist->SetItemText(nItem, 1, editdlg.m_Name_EditDlg);
		plist->SetItemText(nItem, 3, editdlg.m_Others_EditDlg);
		plist->SetItemText(nItem, 6, editdlg.m_Phone_EditDlg);
		plist->SetItemText(nItem, 7, editdlg.m_Address_EditDlg);

		_tcscpy(Patient_Data.at(nItem).m_Name_buf, editdlg.m_Name_EditDlg);
		_tcscpy(Patient_Data.at(nItem).m_Others_buf, editdlg.m_Others_EditDlg);
		_tcscpy(Patient_Data.at(nItem).m_Phone_buf, editdlg.m_Phone_EditDlg);
		_tcscpy(Patient_Data.at(nItem).m_Address_buf, editdlg.m_Address_EditDlg);

		break;
	}

}

void CPatientDlg::OnBnClickedPedit()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	if (m_LoginAdmin)
	{
		CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_PLIST);
		m_nCount_PatientDlg = pList->GetItemCount();

		if (m_nCount_PatientDlg == 0)
		{
			MessageBox(_T("患者情報が入ってないので、編集できません。"), _T("提示"), MB_ICONINFORMATION);
			return;
		}
		POSITION nPos = pList->GetFirstSelectedItemPosition();
		if (nPos == NULL)
		{
			MessageBox(_T("患者情報を選んでください。"), _T("提示"), MB_ICONINFORMATION);
		}
		else
		{
			Edit_nItem(pList, nPos);
		}
	}
	else
	{
		MessageBox(_T("患者情報を編集する権限がありません。"), _T("提示"), MB_ICONINFORMATION);
	}
}


void CPatientDlg::OnBnClickedPsave()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CFile File;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_PLIST);

	m_nCount_PatientDlg = pList->GetItemCount();

	try
	{
		if (m_PlistFlag_PatientDlg)
		{
			File.Open(_T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_File.txt"), CFile::modeCreate | CFile::modeWrite);

			//File.SeekToBegin(); // CFile::modeNoTruncate

			List_Data_Sort();

			for (int i = 0; i != m_nCount_PatientDlg; ++i)
			{
				File.Write(&(Patient_Data.at(i)), sizeof(Patient_Data.at(i)));
			}
			File.Flush();
			File.Close();
			m_PlistFlag_PatientDlg = 0;
			MessageBox(_T("ファイルへの書き込みが成功しました。"), _T("提示"), MB_ICONINFORMATION);
		}

		//MessageBox(_T("ファイルへの書き込みが成功しました。"), _T("提示"), MB_ICONINFORMATION);
	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("失敗理由:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}

}


void CPatientDlg::OnBnClickedPlogout()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	switch (MessageBox(_T("ログアウトしますか。"), _T("提示"), MB_ICONINFORMATION | MB_YESNO))
	{
	case IDYES:
		OnBnClickedPsave();
		m_nCount_PatientDlg = 0; Patient_Data.clear(); CInputDlg::m_Flag = 1;
		EndDialog(IDC_PLOGOUT);
		break;
	}

}


void CPatientDlg::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	OnBnClickedPlogout();
}


void CPatientDlg::FileData_Read()
{
	CFile File;

	try
	{
		if (!File.Open(_T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_File.txt"), CFile::modeRead))
		{
			MessageBox(_T("患者情報が入っていないので、入力してください。"), _T("提示"), MB_ICONINFORMATION);
			File.Open(_T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_File.txt"), CFile::modeCreate);
			//return;
		}

		while (File.Read(&patient, sizeof(patient)))
		{
			Patient_Data.push_back(patient);
			++m_nCount_PatientDlg;
		}
		File.Close();
		//MessageBox(_T("ファイルからの読み取りが成功しました。"), _T("提示"), MB_ICONINFORMATION);
		if(m_nCount_PatientDlg)  //if (!Patient_Data.empty())
		{
			List_Show();
		}

	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("失敗理由:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}
}

void CPatientDlg::List_Show()
{
	CString  str;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_PLIST);

	MessageBox(_T("ファイルからの読み取りが成功しました。"), _T("提示"), MB_ICONINFORMATION);

	for (int i = 0; i != m_nCount_PatientDlg; ++i)
	{
		str.Format(_T("%s"), Patient_Data.at(i).m_Code_buf);
		pList->InsertItem(i, str);
		str.Format(_T("%s"), Patient_Data.at(i).m_Name_buf);
		pList->SetItemText(i, 1, str);
		str.Format(_T("%s"), Patient_Data.at(i).m_Sex_buf);
		pList->SetItemText(i, 2, str);
		str.Format(_T("%s"), Patient_Data.at(i).m_Others_buf);
		pList->SetItemText(i, 3, str);

		if (m_LoginAdmin)
		{//ルート権限
			str.Format(_T("%s"), Patient_Data.at(i).m_Age_buf);
			pList->SetItemText(i, 4, str);
			str.Format(_T("%s"), Patient_Data.at(i).m_Birthday_buf);
			pList->SetItemText(i, 5, str);
			str.Format(_T("%s"), Patient_Data.at(i).m_Phone_buf);
			pList->SetItemText(i, 6, str);
			str.Format(_T("%s"), Patient_Data.at(i).m_Address_buf);
			pList->SetItemText(i, 7, str);
		}
	}

}


void CPatientDlg::Insert_Data(const CInputDlg &Inputdlg)
{
	_tcscpy(patient.m_Code_buf, Inputdlg.m_Code_InputDlg);
	_tcscpy(patient.m_Name_buf, Inputdlg.m_Name_InputDlg);
	_tcscpy(patient.m_Sex_buf, Inputdlg.m_Sex_InputDlg);
	_tcscpy(patient.m_Others_buf, Inputdlg.m_Others_InputDlg);
	_tcscpy(patient.m_Age_buf, Inputdlg.m_Age_InputDlg);
	_tcscpy(patient.m_Birthday_buf, Inputdlg.m_Birthday_InputDlg.Format(_T("%Y年%m月%d日")));
	_tcscpy(patient.m_Phone_buf, Inputdlg.m_Phone_InputDlg);
	_tcscpy(patient.m_Address_buf, Inputdlg.m_Address_InputDlg);
	Patient_Data.push_back(patient);
}


void CPatientDlg::CodeNumber_Check()
{
	CString str;
	unsigned int len = 0, code_head = 0, code_rear = 0;
	std::vector<unsigned int>code_temp;

	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_PLIST);
	m_nCount_PatientDlg = pList->GetItemCount();

	if (m_nCount_PatientDlg)
	{
		for (unsigned int i = 0; i != m_nCount_PatientDlg; ++i)  
		{
			str = pList->GetItemText(i, 0);
			len = str.GetLength();
			code_temp.push_back(_ttoi(str.Right(len - 6)));
		}

		List_CodeNumber_Sort(code_temp);

		code_head = code_temp.front();
		code_rear = code_temp.back();

		for (unsigned int i = 101; i != code_head; ++i)
		{
			m_Code_Number.push_back(i);
		}

		for (unsigned int i = code_head, j = 1; i != code_rear;)
		{
			++i;
			if (i != code_temp.at(j))
			{
				m_Code_Number.push_back(i);
			}
			else
			{
				++j;
			}

		}
		m_Code_Number.push_back(code_rear+1);
	}
	else
	{
		m_Code_Number.push_back(101);
	}

}

void CPatientDlg::List_CodeNumber_Sort(std::vector<unsigned int> &code_temp)
{
	sort(code_temp.begin(), code_temp.end(), [](unsigned int&x, unsigned int&y)
	{
		return x < y;
	}
	);
}

void CPatientDlg::List_Data_Sort()
{
	sort(Patient_Data.begin(), Patient_Data.end(), [](FileData &x, FileData &y)
	{
		//return (_ttoi(x.m_Code_buf)) < (_ttoi(y.m_Code_buf));
		return _tcscmp(x.m_Code_buf, y.m_Code_buf) < 0;
	}
	);
}