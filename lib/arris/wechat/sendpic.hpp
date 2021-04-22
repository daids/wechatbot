#pragma once

#include <arris/wechat/base.hpp>
//#include <arris/wechat/msgtoqueue.hpp>
#include <arris/util/json_util.hpp>
#include <arris/util/log_util.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/offset_version.hpp>

using namespace arris::wechat;
using namespace arris::util;

namespace arris {
namespace wechat {
class send_pic:public iwxmsg{
public:
	send_pic() {
		//msgtoqueue_ = std::make_unique<msgtoqueue>();
		tinyjson_ptr_ = std::make_unique<tinyjson>();
		type_ = static_cast<int>(MsgType::kSendPicMsg);
	}
	~send_pic() = default;
	virtual int get_type() override {
		return type_;
	}
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
		std::string msg = send_to(v_st_msg);

		//msgtoqueue_->send_to_queue(msg);
		return msg;
	}
private:
	std::string send_to(const wx_msg& v_st_msg)
	{

		wchar_t* wxid=wstring_to_wchar(v_st_msg.wxid);
		wchar_t* filepath = wstring_to_wchar(v_st_msg.content);
		//log("发图片\n");
		//接收图片的Wxid结构体
		struct SendImageWxidStruct
		{
			wchar_t* pWxid;
			DWORD length = 0;
			DWORD maxLength = 0;
		};
		//发送图片的结构体
		struct SendImageFileStruct
		{
			wchar_t* filePath;
			DWORD length = 0;
			DWORD maxLength = 0;
			char fillbuff[0x18] = { 0 };
		};
		// 获取微信基址
		DWORD winAddress = get_wx_baseaddr();

		//组装微信ID的数据结构
		SendImageWxidStruct imagewxid;
		imagewxid.pWxid = wxid;
		imagewxid.length = wcslen(wxid);
		imagewxid.maxLength = wcslen(wxid) * 2;

		//组装文件路径的数据结构
		SendImageFileStruct imagefilepath;
		imagefilepath.filePath = filepath;
		imagefilepath.length = wcslen(filepath);
		imagefilepath.maxLength = wcslen(filepath) * 2;
		DWORD dwCall1 = winAddress + static_cast<DWORD>(version::send_picmsg_offset::call1_offset);
		DWORD dwCall2 = winAddress + static_cast<DWORD>(version::send_picmsg_offset::call2_offset);
		DWORD dwCall3 = winAddress + static_cast<DWORD>(version::send_picmsg_offset::call3_offset);
		char buffwxid[0x20] = { 0 };
		char buff[0x568] = { 0 };
		try{
		__asm {
			pushad
			sub esp, 0x14;
			lea eax, buffwxid;
			mov ecx, esp;
			push eax;
			call dwCall1;
			lea ebx, imagefilepath;
			push ebx;
			lea eax, imagewxid;
			push eax;
			lea eax, buff;
			push eax;
			call dwCall2;
			mov ecx, eax;
			call dwCall3;
			popad
		}
		}
		catch (...) {
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus, "send pic msg:asm execution error", static_cast<int>(MsgType::kSendPicMsg));
		}
		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send pic msg:asm execution succsessed", static_cast<int>(MsgType::kSendPicMsg));

	}
	std::string send_to_problem(const wx_msg& v_st_msg)
	{
		struct filepath
		{
			wchar_t* str;
			int len = 0;
			int max_len = 0;
			char file[0x1C] = { 0 };
		};

		DWORD dw_call1 = get_wx_baseaddr() + static_cast<DWORD>(version::send_picmsg_offset::call1_offset);
		DWORD dw_call2 = get_wx_baseaddr() + static_cast<DWORD>(version::send_picmsg_offset::call2_offset);
		DWORD dw_call3 = get_wx_baseaddr() + static_cast<DWORD>(version::send_picmsg_offset::call3_offset);

		char buff[0x568] = { 0 };
		wxid_st id = { 0 };
		id.pstr = wstring_to_wchar(v_st_msg.wxid);
		id.len = wcslen(id.pstr);
		id.max_len = id.len * 2;


		filepath file_path_struct = { 0 };
		file_path_struct.str = wstring_to_wchar(v_st_msg.content);
		file_path_struct.len = wcslen(file_path_struct.str);
		file_path_struct.max_len = file_path_struct.len * 2;

		char* p_filepath = (char*)&file_path_struct.str;
		char* p_wxid = (char*)&id.pstr;

		char buffwxid[0x20] = { 0 };

		try {
			__asm {
				pushad
				pushfd

				sub esp, 0x14
				lea eax, buffwxid
				mov ecx, esp
				push eax
				call dw_call1

				lea ebx, p_filepath
				push ebx
				lea eax, p_wxid
				push eax
				lea eax, buff
				push eax
				call dw_call2

				mov ecx, eax
				call dw_call3


				popfd
				popad
			}
		}
		catch (...) {
			return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgFailedStatus, "send pic msg:asm execution error", static_cast<int>(MsgType::kSendPicMsg));
		}

		return tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus, "send pic msg:asm execution succsessed", static_cast<int>(MsgType::kSendPicMsg));

	}
private:
	int type_;
	//msgtoqueue_ptr msgtoqueue_;
	tinyjson_ptr tinyjson_ptr_;

};//class 
}//namespace wechat
}//namespace arris