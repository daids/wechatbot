#pragma once
#include <Windows.h>
#include <tchar.h>

namespace arris {
namespace util {
//namespace log{
	const size_t kTxtMsgBufferLen = 1024;
	DWORD get_wx_baseaddr() {
		return (DWORD)::GetModuleHandle(TEXT("WeChatWin.dll"));
	}
	
	int __stdcall __OutputDebugString(LPCTSTR pstrFormat, ...)
	{
		TCHAR szBuffer[kTxtMsgBufferLen] = { 0 };
		va_list argList;
		va_start(argList, pstrFormat);
		int iRet = ::_vstprintf_s(szBuffer, pstrFormat, argList);
		va_end(argList);
		size_t len = wcslen(szBuffer);
		if (len> kTxtMsgBufferLen) {
			OutputDebugString(TEXT("buffer length overflow!\n"));
		}
		else {
			OutputDebugString(szBuffer);
		}
		
		return iRet;
	}
//}//namespacde log
}//namespace util
}//namespace arris