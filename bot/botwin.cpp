// botwin.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "bot.h"
#include "botwin.h"
#include "afxdialogex.h"

#include <arris/net/server.hpp>
#include <arris/util/hook.hpp>
#include <arris/hook/hook.hpp>
//#include <arris/net/websocket.hpp>

using namespace arris::net;
//inet_ptr ptr;
//using namespace arris::util;

// botwin 对话框

IMPLEMENT_DYNAMIC(botwin, CDialogEx)

const unsigned int g_server_port = 5555;
using server_ptr = std::unique_ptr<arrisserver>;
server_ptr server;
//arrisserver server(g_server_port);
botwin::botwin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

botwin::~botwin()
{
}

void botwin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(botwin, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_NCPAINT()
END_MESSAGE_MAP()

// botwin 消息处理程序
void botwin::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	un_hook_five();
	server->stop();
	/*----------释放掉注入的dll-------------*/
	HINSTANCE hInstance = AfxGetInstanceHandle();
	//__OutputDebugString(TEXT("instance:%x\n"), hInstance);
	FreeLibraryAndExitThread(hInstance, 0);
	/*----------释放掉注入的dll-------------*/
	CDialogEx::OnClose();
}


DWORD WINAPI WebsocketServerThreadProc(_In_ LPVOID lpParameter) {
	//netcreate<inet, wsserver> server;
	//server = server.create();
	//std::string h = "arrisserver";
	//std::unique_ptr<arrisserver> server = std::make_unique<arrisserver>(5555);
	//server->start();
	//ptr->loop();
	//netcreate<inet, arrisserver> server;
	//ptr = server.create();
	//ptr->start();
	server = std::make_unique<arrisserver>(g_server_port);
	server->start();
	return 0;
}
DWORD WINAPI HookThreadProc(_In_ LPVOID lpParameter) {
	hook();
	return 0;
}
int botwin::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	DWORD serverid,hookid;
	HANDLE srv_handle=::CreateThread(0, 0, WebsocketServerThreadProc, 0, 0, &serverid);
	//WaitForSingleObject(srv_handle, INFINITE);
	HANDLE hook_handle = ::CreateThread(0, 0, HookThreadProc, 0, 0, &hookid);
	//WaitForSingleObject(hook_handle, INFINITE);
	return 0;
}


void botwin::OnNcPaint()
{
	//return;//注释掉return,可隐藏窗口
	static int i = 2;
	if (i > 0)
	{

		i--;
		ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnNcPaint();
	}
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnNcPaint()
}
