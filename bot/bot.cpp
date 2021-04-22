// bot.cpp: 定义 DLL 的初始化例程。
//
#pragma once
#include "pch.h"
#include "framework.h"
#include "bot.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CbotApp

BEGIN_MESSAGE_MAP(CbotApp, CWinApp)
END_MESSAGE_MAP()


// CbotApp 构造

CbotApp::CbotApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CbotApp 对象

CbotApp theApp;


// CbotApp 初始化
DWORD WINAPI show_dialog(_In_ LPVOID lpParameter) {
	AfxGetStaticModuleState();//vs 2019必须加这句	
	botwin* pDlg = new botwin();
	if (NULL == pDlg)
	{
		::OutputDebugString(TEXT("new dlg is null"));
	}
	else {
		::OutputDebugString(TEXT("new dlg is not null"));
	}
	pDlg->DoModal();
	return 0;
}
BOOL CbotApp::InitInstance()
{
	CWinApp::InitInstance();
	DWORD dwThreadId;
	::CreateThread(0, 0, show_dialog, 0, 0, &dwThreadId);
	return TRUE;
}

int CbotApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
