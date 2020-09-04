
// MCC-GP.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
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


// CMCCGPApp �R���X�g���N�V����

CMCCGPApp::CMCCGPApp()
{
	// �ċN���}�l�[�W���[���T�|�[�g���܂�
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� CMCCGPApp �I�u�W�F�N�g�ł��B

CMCCGPApp theApp;


// CMCCGPApp ������

BOOL CMCCGPApp::InitInstance()
{
	// �A�v���P�[�V���� �}�j�t�F�X�g�� visual �X�^�C����L���ɂ��邽�߂ɁA
	// ComCtl32.dll Version 6 �ȍ~�̎g�p���w�肷��ꍇ�́A
	// Windows XP �� InitCommonControlsEx() ���K�v�ł��B�����Ȃ���΁A�E�B���h�E�쐬�͂��ׂĎ��s���܂��B
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �A�v���P�[�V�����Ŏg�p���邷�ׂẴR���� �R���g���[�� �N���X���܂߂�ɂ́A
	// �����ݒ肵�܂��B
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// �_�C�A���O�ɃV�F�� �c���[ �r���[�܂��̓V�F�� ���X�g �r���[ �R���g���[����
	// �܂܂�Ă���ꍇ�ɃV�F�� �}�l�[�W���[���쐬���܂��B
	CShellManager *pShellManager = new CShellManager;

	// MFC �R���g���[���Ńe�[�}��L���ɂ��邽�߂ɁA"Windows �l�C�e�B�u" �̃r�W���A�� �}�l�[�W���[���A�N�e�B�u��
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// �W��������
	// �����̋@�\���g�킸�ɍŏI�I�Ȏ��s�\�t�@�C����
	// �T�C�Y���k���������ꍇ�́A�ȉ�����s�v�ȏ�����
	// ���[�`�����폜���Ă��������B
	// �ݒ肪�i�[����Ă��郌�W�X�g�� �L�[��ύX���܂��B
	// TODO: ��Ж��܂��͑g�D���Ȃǂ̓K�؂ȕ������
	// ���̕������ύX���Ă��������B
	SetRegistryKey(_T("�A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ���[�J�� �A�v���P�[�V����"));

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

	
	// �_�C�A���O�͕����܂����B�A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n���Ȃ���
	//  �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}

