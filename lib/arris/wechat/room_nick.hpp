#pragma once

#include <string>
#include <arris/wechat/base.hpp>
//#include <arris/wechat/msgtoqueue.hpp>
#include <arris/util/json_util.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/util/read_mem.hpp>

using namespace arris::wechat;
using namespace arris::util;
namespace arris {
namespace wechat {
class room_nick :public iwxmsg {
public:
	room_nick() {
		//msgtoqueue_ = std::make_unique<msgtoqueue>();
		tinyjson_ptr_ = std::make_unique<tinyjson>();
		type_ = static_cast<int>(MsgType::kListChatRoomMemberNick);
	}
	~room_nick() = default;
	virtual int get_type() override {
		return type_;
	}
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
		std::string msg = send_to(v_st_msg);
		return msg;
		//msgtoqueue_->send_to_queue(msg);
	}
private:
	std::string send_to(const wx_msg& v_st_msg) {

		wchar_t* wxid= wstring_to_wchar(v_st_msg.wxid);
		wchar_t* roomid = wstring_to_wchar(v_st_msg.roomid);

		std::wstring w_nick = asm_nick(wxid,roomid);
		std::string nick = ucs2_to_utf8(wstring_to_wchar(w_nick));

		std::string s_wxid = ucs2_to_utf8(wstring_to_wchar(v_st_msg.wxid));
		std::string s_roomid= ucs2_to_utf8(wstring_to_wchar(v_st_msg.roomid));

		json j;
		//j["id"] = v_st_msg.id;
		//j["type"] = static_cast<int>(MsgType::kListChatRoomMemberNick);
		j["wxid"] = s_wxid;
		j["roomid"] = s_roomid;
		j["nick"] = nick;
		//j["time"] = s_wxtime();

		std::string msg = tinyjson_ptr_->dump(j, static_cast<int>(MsgType::kListChatRoomMemberNick));
		std::string result = tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, msg, static_cast<int>(MsgType::kListChatRoomMemberNick));
		return result;

	}
	std::wstring asm_nick(wchar_t* wxid, wchar_t* roomid)
	{
		wxid_st id = { 0 };
		id.pstr = wxid;
		id.len = wcslen(wxid);
		id.max_len = wcslen(wxid) * 2;
		char* p_wxid = (char*)&id.pstr;

		wxid_st room = { 0 };
		room.pstr = roomid;
		room.len = wcslen(roomid);
		room.max_len = wcslen(roomid) * 2;
		char* p_roomid = (char*)&room.pstr;

		HMODULE hMod = ::GetModuleHandle(L"wechatwin.dll");
		DWORD dw_call1 = (DWORD)hMod + 0x51E400;//2.8.0.121 =474c30
		DWORD dw_call2 = (DWORD)hMod + 0x378BB0;//2f8430
		DWORD dw_call3 = (DWORD)hMod + 0x524E30;//47b700  50D650
		DWORD dw_call4 = (DWORD)hMod + 0x324A00;//2ada70 31AFE0


		char buf[0x7d4] = { 0 };
		struct tempStruc
		{
			wchar_t* pstr;
			int iLen;
			int iMaxLen;
			int full1 = 0;
			int full2 = 0;
		};


		tempStruc* p_edi = new tempStruc();
		//p_edi->pstr = new wchar_t();
		DWORD r_ebx = 0;
		__asm
		{
			pushad
			pushfd
			//1
			mov eax, 0
			mov ebx, p_edi

			mov edi, p_roomid
			mov esi, p_wxid
			lea ecx, buf
			call dw_call1

			//2
			lea eax, buf
			push eax
			push esi
			call dw_call2
			//3
			mov ecx, eax
			call dw_call3

			//4
			push 1


			push ebx
			mov edx, edi//room id 

			lea ecx, buf
			call dw_call4
			add esp, 0x08
			mov r_ebx, ebx
			popfd
			popad
		}

		DWORD len = read_dword(NULL, r_ebx + 0x04);//³¤¶È
		DWORD addr = read_dword(NULL, r_ebx);//addr
		std::wstring nick = read_wchar(NULL, addr, len);

		/*if (nullptr != p_edi->pstr) {
			delete p_edi->pstr;
			p_edi->pstr = nullptr;
		}*/
		if (nullptr != p_edi) {
			delete p_edi;
			p_edi = nullptr;
		}

		return nick;
	}
private:
	int type_;
	//msgtoqueue_ptr msgtoqueue_;
	tinyjson_ptr tinyjson_ptr_;

};//class room_nick
}//namespace wechat
}//namespace arris
