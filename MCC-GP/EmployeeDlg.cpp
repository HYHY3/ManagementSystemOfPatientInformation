// EmployeeDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "MCC-GP.h"
#include "EmployeeDlg.h"
#include "EEditDlg.h"
#include "afxdialogex.h"
#include<algorithm> 


// CEmployeeDlg �_�C�A���O

IMPLEMENT_DYNAMIC(CEmployeeDlg, CDialogEx)

CEmployeeDlg::CEmployeeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EmployeeDlg, pParent)
{
	m_Font_context = new CFont();
	m_Font_context->CreateFont(24, 8, 0, 0, 15,
		FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Arial"));
}

CEmployeeDlg::~CEmployeeDlg()
{
	delete m_Font_context;
}

void CEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEmployeeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EADD, &CEmployeeDlg::OnBnClickedEadd)
	ON_BN_CLICKED(IDC_EDEL, &CEmployeeDlg::OnBnClickedEdel)
	ON_BN_CLICKED(IDC_EEDIT, &CEmployeeDlg::OnBnClickedEedit)
	ON_BN_CLICKED(IDC_ESAVE, &CEmployeeDlg::OnBnClickedEsave)
	ON_BN_CLICKED(IDC_ELOGOUT, &CEmployeeDlg::OnBnClickedElogout)
END_MESSAGE_MAP()


// CEmployeeDlg ���b�Z�[�W �n���h���[


BOOL CEmployeeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: �����ɏ�������ǉ����Ă�������

	GetDlgItem(IDC_EADD)->SetFont(m_Font_context);
	GetDlgItem(IDC_EDEL)->SetFont(m_Font_context);
	GetDlgItem(IDC_EEDIT)->SetFont(m_Font_context);
	GetDlgItem(IDC_ESAVE)->SetFont(m_Font_context);
	GetDlgItem(IDC_ELOGOUT)->SetFont(m_Font_context);

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_ELIST);
	pList->SetFont(m_Font_context);
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetBkColor(RGB(200, 230, 252));
	pList->SetTextColor(RGB(0, 0, 252));
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	pList->InsertColumn(0, _T("�R�[�h"), LVCFMT_CENTER, 120);
	pList->InsertColumn(1, _T("���O"), LVCFMT_CENTER, 135);
	pList->InsertColumn(2, _T("����"), LVCFMT_CENTER, 50);
	pList->InsertColumn(3, _T("��E"), LVCFMT_CENTER, 70);
	pList->InsertColumn(4, _T("���l"), LVCFMT_CENTER, 180);
	pList->InsertColumn(5, _T("�N��"), LVCFMT_CENTER, 50);
	pList->InsertColumn(6, _T("���N����"), LVCFMT_CENTER, 150);
	pList->InsertColumn(7, _T("�d�b�ԍ�"), LVCFMT_CENTER, 150);
	pList->InsertColumn(8, _T("�Z��"), LVCFMT_CENTER, 360);

	pList->SetColumnWidth(5, LVSCW_AUTOSIZE_USEHEADER);

	FileData_Read();

	CEInputDlg::m_CodeNumber_Index = 0;
	CEInputDlg::m_CodeNumber = 0;
	m_Code_Number.clear();
	CodeNumber_Check();
	CEInputDlg::m_Flag = 1;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ��O : OCX �v���p�e�B �y�[�W�͕K�� FALSE ��Ԃ��܂��B
}


unsigned int CEmployeeDlg::m_nCount_EmployeeDlg = 0;
unsigned int CEmployeeDlg::m_ElistFlag_EmployeeDlg = 0;
std::vector<unsigned int>CEmployeeDlg::m_Code_Number;


void CEmployeeDlg::FileData_Read()
{
	CFile File;

	try
	{
		if (!File.Open(_T("D:\\Graduation Production\\Data\\Employee_Data\\Employee_Data_File.txt"), CFile::modeRead))
		{
			MessageBox(_T("�]�ƈ���񂪓����Ă��Ȃ��̂ŁA���͂��Ă��������B"), _T("��"), MB_ICONINFORMATION);
			File.Open(_T("D:\\Graduation Production\\Data\\Employee_Data\\Employee_Data_File.txt"), CFile::modeCreate);
			//return;
		}

		while (File.Read(&employee, sizeof(employee)))
		{
			Employee_Data.push_back(employee);
			++m_nCount_EmployeeDlg;
		}
		File.Close();
		//MessageBox(_T("�t�@�C������̓ǂݎ�肪�������܂����B"), _T("��"), MB_ICONINFORMATION);
		if (m_nCount_EmployeeDlg)  //if (!Patient_Data.empty())
		{
			List_Show();
		}

	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("���s���R:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}

}

void CEmployeeDlg::List_Show()
{
	CString  str;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_ELIST);

	MessageBox(_T("�t�@�C������̓ǂݎ�肪�������܂����B"), _T("��"), MB_ICONINFORMATION);

	for (int i = 0; i != m_nCount_EmployeeDlg; ++i)
	{
		str.Format(_T("%s"), Employee_Data.at(i).m_Code_buf);
		pList->InsertItem(i, str);
		str.Format(_T("%s"), Employee_Data.at(i).m_Name_buf);
		pList->SetItemText(i, 1, str);
		str.Format(_T("%s"), Employee_Data.at(i).m_Sex_buf);
		pList->SetItemText(i, 2, str);
		str.Format(_T("%s"), Employee_Data.at(i).m_Position_buf);
		pList->SetItemText(i, 3, str);
		str.Format(_T("%s"), Employee_Data.at(i).m_Others_buf);
		pList->SetItemText(i, 4, str);

		if (m_LoginAdmin)
		{//���[�g����
			str.Format(_T("%s"), Employee_Data.at(i).m_Age_buf);
			pList->SetItemText(i, 5, str);
			str.Format(_T("%s"), Employee_Data.at(i).m_Birthday_buf);
			pList->SetItemText(i, 6, str);
			str.Format(_T("%s"), Employee_Data.at(i).m_Phone_buf);
			pList->SetItemText(i, 7, str);
			str.Format(_T("%s"), Employee_Data.at(i).m_Address_buf);
			pList->SetItemText(i, 8, str);
		}
	}
}





void CEmployeeDlg::OnBnClickedEadd()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	CEInputDlg EInputdlg;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_ELIST);

	m_nCount_EmployeeDlg = pList->GetItemCount();
	switch (EInputdlg.DoModal())
	{
	case IDCANCEL: break;
	case IDC_ESAVE:m_ElistFlag_EmployeeDlg = 1;
		pList->InsertItem(m_nCount_EmployeeDlg, EInputdlg.m_Code_EInputDlg);
		pList->SetItemText(m_nCount_EmployeeDlg, 1, EInputdlg.m_Name_EInputDlg);
		pList->SetItemText(m_nCount_EmployeeDlg, 2, EInputdlg.m_Sex_EInputDlg);
		pList->SetItemText(m_nCount_EmployeeDlg, 3, EInputdlg.m_Position_EInputDlg);
		pList->SetItemText(m_nCount_EmployeeDlg, 4, EInputdlg.m_Others_EInputDlg);
		if (m_LoginAdmin)
		{//���[�g����
			pList->SetItemText(m_nCount_EmployeeDlg, 5, EInputdlg.m_Age_EInputDlg);
			pList->SetItemText(m_nCount_EmployeeDlg, 6, EInputdlg.m_Birthday_EInputDlg.Format(_T("%Y�N%m��%d��")));
			pList->SetItemText(m_nCount_EmployeeDlg, 7, EInputdlg.m_Phone_EInputDlg);
			pList->SetItemText(m_nCount_EmployeeDlg, 8, EInputdlg.m_Address_EInputDlg);
		}
		Insert_Data(EInputdlg);
		break;
	}

}

void CEmployeeDlg::Insert_Data(const CEInputDlg &EInputdlg)
{
	_tcscpy(employee.m_Code_buf, EInputdlg.m_Code_EInputDlg);
	_tcscpy(employee.m_Name_buf, EInputdlg.m_Name_EInputDlg);
	_tcscpy(employee.m_Sex_buf, EInputdlg.m_Sex_EInputDlg);
	_tcscpy(employee.m_Position_buf, EInputdlg.m_Position_EInputDlg);
	_tcscpy(employee.m_Age_buf, EInputdlg.m_Age_EInputDlg);
	_tcscpy(employee.m_Birthday_buf, EInputdlg.m_Birthday_EInputDlg.Format(_T("%Y�N%m��%d��")));
	_tcscpy(employee.m_Phone_buf, EInputdlg.m_Phone_EInputDlg);
	_tcscpy(employee.m_Address_buf, EInputdlg.m_Address_EInputDlg);
	_tcscpy(employee.m_Others_buf, EInputdlg.m_Others_EInputDlg);

	Employee_Data.push_back(employee);
}



void CEmployeeDlg::OnBnClickedEdel()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	if (m_LoginAdmin)
	{
		CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_ELIST);
		m_nCount_EmployeeDlg = pList->GetItemCount();

		if (m_nCount_EmployeeDlg == 0)
		{
			MessageBox(_T("�]�ƈ���񂪓����ĂȂ��̂ŁA�폜�ł��܂���B"), _T("��"), MB_ICONINFORMATION);
			return;
		}
		POSITION nPos = pList->GetFirstSelectedItemPosition();
		if (nPos == NULL)
		{
			MessageBox(_T("�]�ƈ�����I��ł��������B"), _T("��"), MB_ICONINFORMATION);
		}
		else
		{
			Delete_nItem(pList, nPos);
			CEInputDlg::m_CodeNumber_Index = 0;
			CEInputDlg::m_CodeNumber = 0;
			m_Code_Number.clear();
			CodeNumber_Check();
			CEInputDlg::m_Flag = 1;
		}
	}
	else
	{
		MessageBox(_T("�]�ƈ������폜���錠��������܂���B"), _T("��"), MB_ICONINFORMATION);
	}
}


void CEmployeeDlg::Delete_nItem(CListCtrl *plist,POSITION nItemPos)
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
		if (IDYES == MessageBox(_T("�I�΂ꂽ�]�ƈ��̏����폜���܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
		{
			del_flag = 0;
			m_ElistFlag_EmployeeDlg = 1;
			plist->DeleteItem(nItem);
			Employee_Data.erase(Employee_Data.begin() + nItem);
		}
		else
		{
			del_flag = 2;
		}
	}
	else if (del_flag == 0)
	{
		plist->DeleteItem(nItem);
		Employee_Data.erase(Employee_Data.begin() + nItem);
	}
}





void CEmployeeDlg::OnBnClickedEedit()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	if (m_LoginAdmin)
	{
		CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_ELIST);
		m_nCount_EmployeeDlg = pList->GetItemCount();

		if (m_nCount_EmployeeDlg == 0)
		{
			MessageBox(_T("�]�ƈ���񂪓����ĂȂ��̂ŁA�ҏW�ł��܂���B"), _T("��"), MB_ICONINFORMATION);
			return;
		}
		POSITION nPos = pList->GetFirstSelectedItemPosition();
		if (nPos == NULL)
		{
			MessageBox(_T("�]�ƈ�����I��ł��������B"), _T("��"), MB_ICONINFORMATION);
		}
		else
		{
			Edit_nItem(pList, nPos);
		}
	}
	else
	{
		MessageBox(_T("�]�ƈ�����ҏW���錠��������܂���B"), _T("��"), MB_ICONINFORMATION);
	}
}

void CEmployeeDlg::Edit_nItem(CListCtrl *plist,POSITION nItemPos)
{
	CEEditDlg editdlg;
	int nItem = plist->GetNextSelectedItem(nItemPos);

	editdlg.m_Name_EEditDlg = plist->GetItemText(nItem, 1);
	editdlg.m_Position_EEditDlg = plist->GetItemText(nItem, 3);
	editdlg.m_Others_EEditDlg = plist->GetItemText(nItem, 4);
	editdlg.m_Phone_EEditDlg = plist->GetItemText(nItem, 7);
	editdlg.m_Address_EEditDlg = plist->GetItemText(nItem, 8);

	switch (editdlg.DoModal())
	{
	case IDCANCEL:break;
	case IDC_ESAVE:
		m_ElistFlag_EmployeeDlg = 1;
		plist->SetItemText(nItem, 1, editdlg.m_Name_EEditDlg);
		plist->SetItemText(nItem, 3, editdlg.m_Position_EEditDlg);
		plist->SetItemText(nItem, 4, editdlg.m_Others_EEditDlg);
		plist->SetItemText(nItem, 7, editdlg.m_Phone_EEditDlg);
		plist->SetItemText(nItem, 8, editdlg.m_Address_EEditDlg);

		_tcscpy(Employee_Data.at(nItem).m_Name_buf, editdlg.m_Name_EEditDlg);
		_tcscpy(Employee_Data.at(nItem).m_Position_buf, editdlg.m_Position_EEditDlg);
		_tcscpy(Employee_Data.at(nItem).m_Others_buf, editdlg.m_Others_EEditDlg);
		_tcscpy(Employee_Data.at(nItem).m_Phone_buf, editdlg.m_Phone_EEditDlg);
		_tcscpy(Employee_Data.at(nItem).m_Address_buf, editdlg.m_Address_EEditDlg);

		break;
	}
}





void CEmployeeDlg::OnBnClickedEsave()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CFile File;
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_ELIST);

	m_nCount_EmployeeDlg = pList->GetItemCount();

	try
	{
		if (m_ElistFlag_EmployeeDlg)
		{
			File.Open(_T("D:\\Graduation Production\\Data\\Employee_Data\\Employee_Data_File.txt"), CFile::modeCreate | CFile::modeWrite);

			//File.SeekToBegin(); // CFile::modeNoTruncate

			List_Data_Sort();

			for (int i = 0; i != m_nCount_EmployeeDlg; ++i)
			{
				File.Write(&(Employee_Data.at(i)), sizeof(Employee_Data.at(i)));
			}
			File.Flush();
			File.Close();
			m_ElistFlag_EmployeeDlg = 0;
			MessageBox(_T("�t�@�C���ւ̏������݂��������܂����B"), _T("��"), MB_ICONINFORMATION);
		}

		//MessageBox(_T("�t�@�C���ւ̏������݂��������܂����B"), _T("��"), MB_ICONINFORMATION);
	}
	catch (CFileException *e)
	{
		CString e_str;
		e_str.Format(_T("���s���R:%d"), e->m_cause);
		MessageBox(e_str);
		File.Abort();
		e->Delete();
	}
}





void CEmployeeDlg::OnBnClickedElogout()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	switch (MessageBox(_T("���O�A�E�g���܂����B"), _T("��"), MB_ICONINFORMATION | MB_YESNO))
	{
	case IDYES:
		OnBnClickedEsave();
		m_nCount_EmployeeDlg = 0; Employee_Data.clear(); CEInputDlg::m_Flag = 1;
		EndDialog(IDC_ELOGOUT);
		break;
	}
}



void CEmployeeDlg::OnCancel()
{
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊��N���X���Ăяo���Ă��������B
	OnBnClickedElogout();
}




void CEmployeeDlg::CodeNumber_Check()
{
	CString str;
	unsigned int len = 0, code_head = 0, code_rear = 0;
	std::vector<unsigned int>code_temp;

	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_ELIST);
	m_nCount_EmployeeDlg = pList->GetItemCount();

	if (m_nCount_EmployeeDlg)
	{
		for (unsigned int i = 0; i != m_nCount_EmployeeDlg; ++i)
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
		m_Code_Number.push_back(code_rear + 1);
	}
	else
	{
		m_Code_Number.push_back(101);
	}

}


void CEmployeeDlg::List_CodeNumber_Sort(std::vector<unsigned int>&code_temp)
{
	sort(code_temp.begin(), code_temp.end(), [](unsigned int&x, unsigned int&y)
	{
		return x < y;
	}
	);
}




void CEmployeeDlg::List_Data_Sort()
{
	sort(Employee_Data.begin(), Employee_Data.end(), [](FileData &x, FileData &y)
	{
		//return (_ttoi(x.m_Code_buf)) < (_ttoi(y.m_Code_buf));
		return _tcscmp(x.m_Code_buf, y.m_Code_buf) < 0;
	}
	);
}
