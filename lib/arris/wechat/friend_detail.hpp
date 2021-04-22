#pragma once

#include <arris/wechat/base.hpp>
#include <arris/util/log_util.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/offset_version.hpp>
#include <arris/util/str_util.hpp>
#include <arris/util/json_util.hpp>
#include <nlohmann/json.hpp>
using namespace arris::util;
using nlohmann::json;
namespace arris {
namespace wechat {
	class friend_detail :public iwxmsg {
	public:
		friend_detail() :
			type_(static_cast<int>(MsgType::kPersonalDetail))
		{
		}
		~friend_detail() = default;
	public:
		virtual std::string handle_msg(const wx_msg& v_st_msg) override {
			//wchar_t* wxid = wstring_to_wchar(v_st_msg.wxid);
			//wchar_t* roomid = wstring_to_wchar(v_st_msg.roomid);
			std::string msg = to_string(v_st_msg);
			return msg;
		}
		virtual int get_type()override {
			return type_;
		}
private:
	std::string to_string(const wx_msg& v_st_msg) {
		wchar_t* wxid = wstring_to_wchar(v_st_msg.wxid);
		DWORD dw_eax = call_personal_detail(wxid);
		__OutputDebugString(TEXT("dw_eax is %x"),dw_eax);
		//std::wstring v1 = get_msg_byaddress(dw_eax + 0x58);
		//std::wstring wxcode = get_msg_byaddress(dw_eax + 0x44);
		//std::wstring name1 = get_msg_byaddress(dw_eax + 0x78);

		//std::wstring nickname = get_msg_byaddress(dw_eax + 0x8c);
		std::wstring big_headimg = get_msg_byaddress(dw_eax + 0x11c);

		std::wstring little_headimg = get_msg_byaddress(dw_eax + 0x130);
		std::wstring signature = get_msg_byaddress(dw_eax + 0x1bc);
		//std::wstring nation = get_msg_byaddress(dw_eax + 0x1d0);
		//std::wstring provice = get_msg_byaddress(dw_eax + 0x1e4);
		//std::wstring city = get_msg_byaddress(dw_eax + 0x1f8);
		std::wstring cover = get_msg_byaddress(dw_eax + 0x29c);
		//__OutputDebugMaxString(TEXT("cover:%s\n"),cover.c_str());

		json j;
		//j["v1"] = ucs2_to_utf8(wstring_to_wchar(v1));
		//j["wxcode"] = ucs2_to_utf8(wstring_to_wchar(wxcode));
		//j["name1"] = ucs2_to_utf8(wstring_to_wchar(name1));
		//j["name2"] = ucs2_to_utf8(wstring_to_wchar(nickname));
		j["big_headimg"] = ucs2_to_utf8(wstring_to_wchar(big_headimg));
		j["little_headimg"] = ucs2_to_utf8(wstring_to_wchar(little_headimg));
		j["signature"] = ucs2_to_utf8(wstring_to_wchar(signature));
		//j["nation"] = ucs2_to_utf8(wstring_to_wchar(nation));
		//j["provice"] = ucs2_to_utf8(wstring_to_wchar(provice));
		//j["city"] = ucs2_to_utf8(wstring_to_wchar(city));
		j["cover"] = ucs2_to_utf8(wstring_to_wchar(cover));


		json jmsg;
		jmsg["id"] = v_st_msg.id;
		jmsg["content"] = j;
		jmsg["sender"] = kServerSide;
		jmsg["receiver"] = kClientSide;
		jmsg["srvid"] = MsgType::kServerSideMsg;
		jmsg["time"] = s_wxtime();
		jmsg["type"] = type_;
		jmsg["status"] = kMsgOkStatus;
		std::string result;
		try {
			result = jmsg.dump();
		}
		catch (json::exception& e)
		{
			//__OutputDebugString(TEXT("json:json dump error!\n"));
			//__OutputDebugString(TEXT("line:%d,file:%s,func:%s\n"), __LINE__, TEXT(__FILE__), TEXT(__FUNCTION__));
			//logger->error("json:json dump error!");
			//std::string id = v_st_msg.id;
			//std::string content = "json dump error!";
			tinyjson tiny;
			result = tiny.ret_msg(time2id(), kMsgFailedStatus, e.what(), type_);
			//result = ret_msg(PERSONAL_DETAIL, id, content, "FAIL");
		}
		return result;
		//ret_msg

	}
	DWORD call_personal_detail(wchar_t* wxid)
	{
		wxid_st id = { 0 };
		id.pstr = wxid;
		id.len = wcslen(wxid);
		id.max_len = wcslen(wxid) * 2;

		char* pwxid = (char*)&id.pstr;
		
		//2.8.0.121 51b90
		DWORD dw_call = get_wx_baseaddr() + 0xFB2D0;
		__OutputDebugString(TEXT("dw call:%x"),dw_call);
		DWORD dw_eax = 0;

		DWORD ebx_value = *(DWORD*)(get_wx_baseaddr() + static_cast<DWORD>(version::contact_data_offset::contact_offset));
		__OutputDebugString(TEXT("ebx_value:%x"), ebx_value);
		//[WeChatWin.dll+0x161CF54]+0x28+0x84
		DWORD dw_ebx = ebx_value + 0x28 + 0x8c;
		__OutputDebugString(TEXT("dw_ebx:%x"), dw_ebx);


		//return 0;
		try
		{
			__asm
			{
				pushad
				pushfd
				mov eax, pwxid
				push eax
				mov ebx, dw_ebx
				mov ecx, ebx
				call dw_call
				mov dw_eax, eax
				popfd
				popad
			}

		}
		catch (...)
		{
			__OutputDebugString(TEXT("personal detail call error\n"));
			__OutputDebugString(TEXT("line:%d,file:%s,func:%s\n"), __LINE__, TEXT(__FILE__), TEXT(__FUNCTION__));
			//__OutputDebugString(TEXT("dw_ebx:%d\n"), dw_ebx);
		}
		return dw_eax;
	}
private:
	int type_;

};
}//namespace wechat
}//namespace arris
