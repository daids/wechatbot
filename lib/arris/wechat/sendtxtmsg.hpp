#pragma once

#include <arris/wechat/base.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/util/log_util.hpp>
#include <arris/wechat/offset_version.hpp>
#include <arris/util/str_util.hpp>
#include <arris/util/json_util.hpp>

using namespace arris::wechat;
using namespace arris::util;

namespace arris {
namespace wechat {

class send_txt_msg :public iwxmsg {
public:
	send_txt_msg() {
		tinyjson_ptr_ = std::make_unique<tinyjson>();
		type_ = static_cast<int>(MsgType::kSendTxtMsg);
	}
	~send_txt_msg() = default;
	virtual int get_type() override{
		return type_;
	}
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
		std::string msg= send_to(v_st_msg);
		return msg;
	}

private:
	std::string send_to(const wx_msg& v_st_msg) {

		DWORD call_addr = get_wx_baseaddr() + static_cast<DWORD>(version::send_txtmsg_offset::send_call_addr);

		wxid_st id = { 0 };
		id.pstr = wstring_to_wchar(v_st_msg.wxid);
		id.len = wcslen(id.pstr);
		id.max_len = wcslen(id.pstr) * 2;

		
		struct txt_content {
			const wchar_t* content;
			DWORD len;
			DWORD max_len;
			DWORD num[0xD];
		};
		txt_content content = { 0 };
		content.content = wstring_to_wchar(v_st_msg.content);
		content.len = wcslen(content.content);
		content.max_len = wcslen(content.content) * 2;
		//取出微信ID和消息的地址
		char* p_wxid = (char*)&id.pstr;
		char* p_content = (char*)&content.content;

		char buff[0x5a8] = { 0 };

		//调用微信发送消息call
		try
		{
			__asm {
				    mov ebx, p_content;//内容

				    push 1
					mov edi,0 //at 消息的wxid结构体地址
					push edi

					push ebx
					mov edx, p_wxid//at消息的roomid地址
					lea ecx, buff
					call call_addr
					add esp, 0xC
			}

		}
		catch (...)
		{
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus,"send txt msg:asm execution error", static_cast<int>(MsgType::kSendTxtMsg));
		}

		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send txt msg:asm execution succsessed", static_cast<int>(MsgType::kSendTxtMsg));


	}
private:
	int type_;
	tinyjson_ptr tinyjson_ptr_;
};

}
}//namespace arris