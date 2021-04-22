#pragma once

#include <arris/wechat/base.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/util/json_util.hpp>

using namespace arris::wechat;
namespace arris {
namespace wechat {

class attatch:public iwxmsg {
private:
	DWORD call1 = 0x58C9E0;
	DWORD call2 = 0x58C9A0;
	DWORD call3 = 0x58C9E0;
	DWORD call4 = 0x58C9E0;
	DWORD call5 = 0x68A40;
	DWORD call6 = 0x2C0BE0;
	DWORD para = 0x17DB9C8;
public:
	attatch() :type_(static_cast<int>(MsgType::kAttatchFile)) {
		tinyjson_ptr_ = std::make_unique<tinyjson>();
	}
	virtual std::string handle_msg(const wx_msg& msg) override{
		std::string result = sendto(msg);
		return result;
		//return "null";
	}
	virtual int get_type()override {
		return type_;
	}
private:
	std::string sendto(const wx_msg& v_st_msg) {
		wxid_st id = {0};

		DWORD dwCall1 = get_wx_baseaddr() + call1;
		DWORD dwCall2 = get_wx_baseaddr() + call2;
		DWORD dwCall3 = get_wx_baseaddr() + call3;
		DWORD dwCall4 = get_wx_baseaddr() + call4;
		DWORD dwCall5 = get_wx_baseaddr() + call5;
		DWORD dwCall6 = get_wx_baseaddr() + call6;
		DWORD dwParams = get_wx_baseaddr() + para;

		char buff[0x350] = { 0 };//
		id.pstr = wstring_to_wchar(v_st_msg.wxid);
		id.len = wcslen(id.pstr);
		id.max_len = id.len * 2;

		struct FilePath
		{
			wchar_t* str;
			int strLen = 0;
			int maxLen = 0;
			char file[0x1C] = { 0 };
		};

		FilePath filePathStruct = { 0 };
		filePathStruct.str = wstring_to_wchar(v_st_msg.content);
		filePathStruct.strLen = wcslen(filePathStruct.str);
		filePathStruct.maxLen = wcslen(filePathStruct.str) * 2;

		char* pFilePath = (char*)&filePathStruct.str;
		char* pWxid = (char*)&id.pstr;

		
		//3.1.0.66
		try {
			__asm {
				pushad
				pushfd

				sub esp, 0x14
				mov byte ptr ss : [ebp - 0x6C] , 0x0
				mov ebx, pFilePath
				lea eax, [ebx + 0x14]
				mov ecx, esp
				push eax
				call dwCall1


				//push 0;//[ebp - 0x6C] = 0
				push dword ptr ss : [ebp - 0x6C]
				sub esp, 0x14;
				mov ecx, esp;
				push - 0x1;
				push dwParams;
				call dwCall2;
				sub esp, 0x14;
				mov ecx, esp;
				push pFilePath;
				call dwCall3;
				sub esp, 0x14;
				mov ecx, esp;
				push pWxid;
				call dwCall4;
				lea eax, buff;
				push eax;
				call dwCall5;
				mov ecx, eax;
				call dwCall6;

				popfd;
				popad;
			}
		}
		catch (...) {
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus, "send  attatch:asm execution error", static_cast<int>(MsgType::kAttatchFile));
		}
		
		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send attatch:asm execution succsessed", static_cast<int>(MsgType::kAttatchFile));
	}
private:
	int type_;
	tinyjson_ptr tinyjson_ptr_;

};
}//namespace arris
}//namespace wechat