#pragma once

#include "afxdialogex.h"
// botwin 对话框

//IMPLEMENT_DYNAMIC(botwin, CDialogEx)
class botwin : public CDialogEx
{
	DECLARE_DYNAMIC(botwin)

public:
	botwin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~botwin();
	//void WebsocketServerThreadProc();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNcPaint();
};
