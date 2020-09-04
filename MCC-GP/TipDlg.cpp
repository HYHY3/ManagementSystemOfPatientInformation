// TipDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "TipDlg.h"
#include "afxdialogex.h"
#include "PatientDlg.h"

// CTipDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CTipDlg, CDialogEx)

CTipDlg::CTipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TipDlg, pParent)
	, m_Date_Tipdlg(COleDateTime::GetCurrentTime())
	, m_Condition_Tipdlg(_T(""))
	, m_Medicine_Tipdlg(_T(""))
	, m_Name_Tipdlg(_T(""))
{
	m_Font = new CFont();
	m_Font->CreateFont(30, 10, 0, 0, 20,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CTipDlg::~CTipDlg()
{
	delete m_Font;
}

void CTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_EDIT_DATESHOW, m_Date_Tipdlg);
	DDX_Text(pDX, IDC_EDIT_CONDITIONSHOW, m_Condition_Tipdlg);
	DDX_Text(pDX, IDC_EDIT_MEDICINESHOW, m_Medicine_Tipdlg);
	DDX_Text(pDX, IDC_EDIT_NAMESHOW, m_Name_Tipdlg);
}


BEGIN_MESSAGE_MAP(CTipDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTipDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_EDIT_SAVE, &CTipDlg::OnBnClickedEditSave)
	ON_BN_CLICKED(IDC_EDIT_DEL, &CTipDlg::OnBnClickedEditDel)
	ON_COMMAND(IDCANCEL, &CTipDlg::OnIdcancel)
END_MESSAGE_MAP()


// CTipDlg ���b�Z�[�W �n���h���[

BOOL CTipDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: �����ɏ�������ǉ����Ă�������

	GetDlgItem(IDC_EDIT_NAME)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_NAMESHOW)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_DATE)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_DATESHOW)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_CONDITION)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_CONDITIONSHOW)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_MEDICINE)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_MEDICINESHOW)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_SAVE)->SetFont(m_Font);
	GetDlgItem(IDC_EDIT_DEL)->SetFont(m_Font);
	GetDlgItem(IDOK)->SetFont(m_Font);

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_EDIT_LIST);
	pList->SetFont(m_Font);
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetBkColor(RGB(200, 230, 252));
	pList->SetTextColor(RGB(0, 0, 252));
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	pList->InsertColumn(0, _T("���t"), LVCFMT_CENTER, 170);
	pList->InsertColumn(1, _T("�a��"), LVCFMT_CENTER, 300);
	pList->InsertColumn(2, _T("��"), LVCFMT_CENTER, 300);
	//pList->SetColumnWidth(2, LVSCW_AUTOSIZE_USEHEADER);

	Detail_Read();

	//pList->SetColumnWidth(2, LVSCW_AUTOSIZE_USEHEADER);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


void CTipDlg::Detail_Read()
{

	CFile File;
	CString str = _T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_History\\Patient_Data_File_"), str1;
	str1.Format(_T("%d"), m_CodeNumber_Tipdlg + 1);
	str += str1 + _T(".txt");

	try
	{
		if (!File.Open(str, CFile::modeRead))
		{
			//MessageBox(_T("�����t�@�C���̊J�������s���܂����B!"), _T("��"), MB_ICONINFORMATION);
			//return;
			File.Open(str, CFile::modeCreate);
			//MessageBox(_T("�V���������t�@�C�������܂����B!"), _T("��"), MB_ICONINFORMATION);
		}

		//File.Seek(m_CodeNumber_Tipdlg*sizeof(Patient_Data_History), CFile::begin);

		Patient_Data_History.clear();
		while (File.Read(&patient_history, sizeof(patient_history)))
		{
			Patient_Data_History.push_back(patient_history);
		}
		File.Close();
	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("���s���R:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}


	if (!Patient_Data_History.empty())
	{
		//MessageBox(_T("�����t�@�C������̓ǂݎ�肪�������܂����B"), _T("��"), MB_ICONINFORMATION);
		CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_EDIT_LIST);
		CString str;
		for (unsigned int i = 0; i != Patient_Data_History.size(); ++i)
		{
			str.Format(_T("%s"), Patient_Data_History.at(i).m_Date_buf);
			pList->InsertItem(i, str);
			str.Format(_T("%s"), Patient_Data_History.at(i).m_Condition_buf);
			pList->SetItemText(i, 1, str);
			str.Format(_T("%s"), Patient_Data_History.at(i).m_Medicine_buf);
			pList->SetItemText(i, 2, str);

		}
	}
	/*else
	{
		MessageBox(_T("���҂̐f�@������͂��Ă��������B"), _T("��"), MB_ICONINFORMATION);
	}*/

}



void CTipDlg::Detail_Edit()
{
	UpdateData(TRUE);

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_EDIT_LIST);
	unsigned int nCnt = pList->GetItemCount();

	pList->InsertItem(nCnt, m_Date_Tipdlg.Format(_T("%Y�N%m��%d��")));
	pList->SetItemText(nCnt, 1, m_Condition_Tipdlg);
	pList->SetItemText(nCnt, 2, m_Medicine_Tipdlg);


	_tcscpy(patient_history.m_Date_buf, m_Date_Tipdlg.Format(_T("%Y�N%m��%d��")));
	_tcscpy(patient_history.m_Condition_buf, m_Condition_Tipdlg);
	_tcscpy(patient_history.m_Medicine_buf, m_Medicine_Tipdlg);

	Patient_Data_History.push_back(patient_history);

	//m_Condition_Tipdlg = m_Medicine_Tipdlg = "";
	//UpdateData(FALSE);

}

void CTipDlg::OnBnClickedOk()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	switch (MessageBox(_T("���҂̐f�@����ҏW���܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
	{
	case IDYES:Detail_Edit(); m_Flag = 1; break;
	default:break;
	}
	m_Condition_Tipdlg = m_Medicine_Tipdlg = "";
	UpdateData(FALSE);


}



void CTipDlg::OnBnClickedEditSave()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CFile File;
	CString str = _T("D:\\Graduation Production\\Data\\Patient_Data\\Patient_Data_History\\Patient_Data_File_"), str1;
	str1.Format(_T("%d"), m_CodeNumber_Tipdlg + 1);
	str += str1 + _T(".txt");

	try
	{

		if (!File.Open(str, CFile::modeCreate | CFile::modeWrite))
		{
			MessageBox(_T("�����t�@�C���̊J�������s���܂����B!"), _T("��"), MB_ICONINFORMATION);
			return;
		}

		for (int i = 0; i != Patient_Data_History.size(); ++i)
		{
			File.Write(&(Patient_Data_History.at(i)), sizeof(Patient_Data_History.at(i)));
		}
		File.Flush();
		File.Close();

		Patient_Data_History.clear();
		MessageBox(_T("�����t�@�C���ւ̏������݂��������܂����B"), _T("��"), MB_ICONINFORMATION);
	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("���s���R:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}
	m_Flag = 0;
}




void CTipDlg::Detail_Delete(CListCtrl *plist, POSITION nItemPos)
{
	static unsigned int del_flag = 0;
	int nItem = plist->GetNextSelectedItem(nItemPos);

	if (nItemPos)
	{
		Detail_Delete(plist, nItemPos);
	}
	else
	{
		del_flag = 1;
	}

	if (del_flag == 1)
	{
		if (IDYES == MessageBox(_T("�I�΂ꂽ���Ґf�@�����폜���܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
		{
			del_flag = 0;
			plist->DeleteItem(nItem);
			Patient_Data_History.erase(Patient_Data_History.begin() + nItem);
		}
		else
		{
			del_flag = 2;
		}
	}
	else if (del_flag == 0)
	{
		plist->DeleteItem(nItem);
		Patient_Data_History.erase(Patient_Data_History.begin() + nItem);
	}
}


void CTipDlg::OnBnClickedEditDel()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_EDIT_LIST);
	unsigned int nCnt = pList->GetItemCount();

	if (nCnt == 0)
	{
		MessageBox(_T("���҂̐f�@��񂪓����ĂȂ��̂ŁA�폜�ł��܂���B"), _T("��"), MB_ICONINFORMATION);
		return;
	}

	POSITION nPos = pList->GetFirstSelectedItemPosition();
	if (nPos == NULL)
	{
		MessageBox(_T("���҂̐f�@����I��ł��������B"), _T("��"), MB_ICONINFORMATION);
	}
	else
	{
		Detail_Delete(pList, nPos);
	}
	m_Flag = 1;

}

unsigned int CTipDlg::m_Flag = 0;

void CTipDlg::OnIdcancel()
{
	// TODO: �����ɃR�}���h �n���h���[ �R�[�h��ǉ����܂��B
	if (m_Flag)
	{
		if (IDYES == MessageBox(_T("���҂̐f�@����ۑ����܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
		{
			OnBnClickedEditSave();
		}
	}
	EndDialog(IDCANCEL);
}


