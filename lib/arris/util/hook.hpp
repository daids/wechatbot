#pragma once
#include <Windows.h>
#include <vector>
namespace arris {
namespace util {
	static CRITICAL_SECTION  g_cs;
	static  BOOL             g_bVarsInitialized = FALSE;
	struct unhook
	{
		DWORD address;//unhookµÿ÷∑
		BYTE  backcode[5];
	};
	std::vector<unhook> g_unhook_ary;
	BYTE G_HOOKED = 0;
	void __stdcall EnterCritSec()
	{
		if (!g_bVarsInitialized) {
			InitializeCriticalSection(&g_cs);
			g_bVarsInitialized = TRUE;
		}
		EnterCriticalSection(&g_cs);
	}

	void  __stdcall LeaveCritSec()
	{
		LeaveCriticalSection(&g_cs);
	}
	void __stdcall backup_hook_code(DWORD hook_address)
	{
		BYTE  backcode[5] = { 0 };
		HANDLE process = ::GetCurrentProcess();
		if (ReadProcessMemory(process, (LPVOID)hook_address, backcode, 5, 0) == 0)
		{
			return;
		}
		else
		{
			unhook m;
			m.address = hook_address;
			for (int i = 0; i <= 4; i++)
			{
				m.backcode[i] = backcode[i];
			}
			g_unhook_ary.push_back(m);
		}
	}
	void __stdcall un_hook_five()
	{

		if (G_HOOKED == 0) { return; }
		EnterCritSec();

		SIZE_T WriteSize = NULL;

		for (auto item : g_unhook_ary)
		{
			unhook m = { 0 };
			m = item;
			WriteProcessMemory(::GetCurrentProcess(), (LPDWORD)(m.address + 0x00), m.backcode, 5, &WriteSize);
		}
		LeaveCritSec();
		g_unhook_ary.clear();//«Âø’

	}
	BOOL __stdcall EnableDebugPrivilege(BOOL bEnable)
	{
		BOOL fOK = FALSE;
		HANDLE hToken;
		if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)) //
		{
			TOKEN_PRIVILEGES tp;
			tp.PrivilegeCount = 1;
			LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
			tp.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
			AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
			fOK = (GetLastError() == ERROR_SUCCESS);
			CloseHandle(hToken);
		}
		return fOK;
	}
	
	void  hook_five_bytes(DWORD hook_addr,DWORD function_addr) //HOOK 5 bytes
	{
		EnterCritSec();
		backup_hook_code(hook_addr);

		DWORD dwTargetAddr = function_addr;
		EnableDebugPrivilege(TRUE);//
		DWORD pid = NULL;
		SIZE_T WriteSize = NULL;
		

		BYTE Temp = 0xE9;  //jmp
		WriteProcessMemory(::GetCurrentProcess(), (LPDWORD)(hook_addr + 0x00), &Temp, 1, &WriteSize);

		DWORD Temp1 = dwTargetAddr - hook_addr - 5;
		WriteProcessMemory(::GetCurrentProcess(), (LPDWORD)(hook_addr + 0x01), &Temp1, 4, &WriteSize);

		LeaveCritSec();
		G_HOOKED = 1;
	}


}//namespace util
}//namespace arris