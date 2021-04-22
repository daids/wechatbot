#pragma once
#include <arris/wechat/base.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/util/json_util.hpp>
#include <arris/wechat/offset_version.hpp>
using namespace arris::wechat;

//https://github.com/chengciming/wechatPc/blob/master/%E5%BE%AE%E4%BF%A1%E5%9F%BA%E5%9D%80-2.8.0.121.txt
namespace arris {
namespace wechat {
class atmsg :public iwxmsg {//3.2.1.121
public:
	atmsg() :type_(static_cast<int>(MsgType::kSendAtMsg)) {
		tinyjson_ptr_ = std::make_unique<tinyjson>();
	}
	~atmsg() = default;
	virtual std::string handle_msg(const wx_msg& msg)override {
		std::string result = sendtonew(msg);
		return result;
	}
	virtual int get_type() override {
		return type_;
	}
private:
	std::string sendtonew(const wx_msg& v_st_msg) {

		//DWORD call1 = get_wx_baseaddr() + 0x619C0;
		DWORD call_addr = get_wx_baseaddr() + static_cast<DWORD>(version::send_txtmsg_offset::send_call_addr);

		wxid_st id = { 0 };
		id.pstr = wstring_to_wchar(v_st_msg.wxid);
		id.len = wcslen(id.pstr);
		id.max_len = wcslen(id.pstr) * 2;

		/*-------------wxid new structure for at msg-------------*/
		struct wxid_atmsg {
			wxid_st* wxid;
			int* temp1;
			int* temp2;
			int  temp4 = 0;
		};

		int temp3 = 0xF;
		wxid_atmsg atmsg_wxid_st = {0};
		atmsg_wxid_st.wxid = &id;
		atmsg_wxid_st.temp1 = &temp3; 
		atmsg_wxid_st.temp2 = &temp3;

		room_at roomid = { 0 };
		roomid.roomid = wstring_to_wchar(v_st_msg.roomid);
		roomid.len = wcslen(roomid.roomid);
		roomid.max_len = roomid.len * 2;
		/*-------------wxid new structure for at msg-------------*/

		struct txt_content {
			const wchar_t* content;
			DWORD len;
			DWORD max_len;
			DWORD num[0x1c];
		};

		std::wstring tmp_content = TEXT("@") + v_st_msg.nickname + TEXT(" ") + v_st_msg.content;
		txt_content content = { 0 };
		content.content = wstring_to_wchar(tmp_content);
		content.len = wcslen(content.content);
		content.max_len = wcslen(content.content) * 2;
		//取出微信ID和消息的地址
		//char* p_wxid = (char*)&id.pstr;
		char* p_roomid = (char*)&roomid.roomid;
		char* p_content = (char*)&content.content;
		wxid_atmsg* patmsg_wxid = &atmsg_wxid_st;
		char buff[0x5a8] = { 0 };
		//LPSTR
			//调用微信发送消息call
			try
		{
			__asm {
				pushad
				pushfd
				//mov eax, 0x40
				//call call1

				//mov ebx, p_content;//内容
				//mov esi, 0x1
				mov ebx, p_content
				//lea edi, pwxid
				mov edi, patmsg_wxid
				push 1
				//mov edi, p_wxid //at 消息的wxid结构体地址

				push edi  //

				push ebx
				//mov edx, p_roomid//at消息的roomid地址
				mov edx, p_roomid
				lea ecx, buff
				call call_addr
				add esp, 0xC

				popfd
				popad
			}

		}
		catch (...)
		{
			//__OutputDebugString(TEXT("send txt msg:asm execution error!\n"));
			//__OutputDebugString(TEXT("line:%d,file:%s,func:%s\n"), __LINE__, TEXT(__FILE__), TEXT(__FUNCTION__));
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus, "send at msg:asm execution error", static_cast<int>(MsgType::kSendAtMsg));
		}

		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send at msg:asm execution succsessed", static_cast<int>(MsgType::kSendAtMsg));


	}
	std::string sendto(const wx_msg& v_st_msg) {

		DWORD call1 = get_wx_baseaddr() + 0x619C0;
		DWORD call_addr = get_wx_baseaddr() + static_cast<DWORD>(version::send_txtmsg_offset::send_call_addr);

		wxid_st id = { 0 };
		id.pstr = wstring_to_wchar(v_st_msg.wxid);
		id.len = wcslen(id.pstr);
		id.max_len = wcslen(id.pstr) * 2;

		wxid_st roomid = {0};
		roomid.pstr = wstring_to_wchar(v_st_msg.roomid);
		roomid.len = wcslen(id.pstr);
		roomid.max_len = wcslen(id.pstr) * 2;

		struct txt_content {
			const wchar_t* content;
			DWORD len;
			DWORD max_len;
			DWORD num[0xD];
		};

		std::wstring tmp_content = TEXT("@") + v_st_msg.nickname+TEXT(" ")+ v_st_msg.content;
		txt_content content = { 0 };
		content.content = wstring_to_wchar(tmp_content);
		content.len = wcslen(content.content);
		content.max_len = wcslen(content.content) * 2;
		//取出微信ID和消息的地址
		char* p_wxid = (char*)&id.pstr;
		char* p_roomid = (char*)&roomid.pstr;
		char* p_content = (char*)&content.content;

		char buff[0x5a8] = { 0 };
		//LPSTR
		//调用微信发送消息call
		try
		{
			__asm {
				pushad
				pushfd
				mov eax,0x40
				call call1

				//mov ebx, p_content;//内容
				mov esi,0x1
				mov ebx,p_content
				lea edi, p_wxid
				push 1
					//mov edi, p_wxid //at 消息的wxid结构体地址
					
					push edi  //

					push ebx
					//mov edx, p_roomid//at消息的roomid地址
					mov edx,p_roomid
					lea ecx, buff
					call call_addr
					add esp, 0xC

					popfd
					popad
			}

		}
		catch (...)
		{
			//__OutputDebugString(TEXT("send txt msg:asm execution error!\n"));
			//__OutputDebugString(TEXT("line:%d,file:%s,func:%s\n"), __LINE__, TEXT(__FILE__), TEXT(__FUNCTION__));
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus, "send at msg:asm execution error", static_cast<int>(MsgType::kSendAtMsg));
		}

		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send at msg:asm execution succsessed", static_cast<int>(MsgType::kSendAtMsg));


	}
private:
	int type_;
	tinyjson_ptr tinyjson_ptr_;
};
}
}