
// MCC-GP.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMCCGPApp:
// このクラスの実装については、MCC-GP.cpp を参照してください。
//

class CMCCGPApp : public CWinApp
{
public:
	CMCCGPApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMCCGPApp theApp;