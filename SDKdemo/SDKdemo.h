


#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		




class CSDKdemoApp : public CWinApp
{
public:
	CSDKdemoApp();


public:
	virtual BOOL InitInstance();



	DECLARE_MESSAGE_MAP()
};

extern CSDKdemoApp theApp;