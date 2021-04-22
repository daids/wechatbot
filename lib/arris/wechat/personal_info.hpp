#pragma once

#include <Windows.h>
#include <arris/wechat/base.hpp>
//#include <arris/wechat/msgdispatch.hpp>
#include <arris/util/json_util.hpp>
#include <arris/wechat/offset_version.hpp>
#include <arris/util/read_mem.hpp>
#include <arris/wechat/constant.hpp>
// $+80      15E908E8  ¨¨.¨¦.  "wxid_2xx8uqgknb3l22"  ×Ó·ÇÓã
namespace arris {
namespace wechat {
class personal_info :public iwxmsg {
public:
	personal_info() {
		//msgdispatch_ = std::make_unique<msgdispatch>();
		tinyjson_ptr_ = std::make_unique<tinyjson>();
		baseaddr_ = get_wx_baseaddr() + static_cast<DWORD>(version::wx_personal_info::wx_name_offset);
		sign_ = get_sign();
		type_ = static_cast<int>(MsgType::kPersonalInfo);
	}
	~personal_info() = default;

	virtual int get_type() override {
		return type_;
	}
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
		json j;
		//j["id"] = v_st_msg.id;
		//j["type"] = static_cast<int>(MsgType::kPersonalInfo);
		j["wx_id"] = get_wxid();
		j["wx_code"] = get_wxcode();
		j["wx_name"] = get_nick();

		std::string msg = tinyjson_ptr_->dump(j, static_cast<int>(MsgType::kPersonalInfo));
		std::string result = tinyjson_ptr_->ret_msg(v_st_msg.id, kMsgOkStatus,msg, static_cast<int>(MsgType::kPersonalInfo));
		
		//msgdispatch_->send_to_queue(result);
		return result;
	}
private:
	DWORD get_sign() {
		DWORD addr = baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_code_length_offset);
		DWORD result = read_dword(NULL, addr);
		return result;
	}
	std::string get_wxid() {
		std::string result;
		DWORD addr, len;
		if (sign_ == 0) {//old wxid 
			addr = baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_id_offset);
			len = read_dword(NULL, baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_id_offset) + 0x10);
		}
		else {//new wxid
			DWORD temp_addr = baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_id_offset);
			addr = read_dword(NULL, temp_addr);
			len = read_dword(NULL, baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_id_offset) + 0x10);
		}
		
		result = read_char(NULL, addr, len);
		return result;
	}
	std::string get_wxcode() {
		

		DWORD addr, len;
		if (sign_ == 0) {//old wxcode 
			std::string result;
			addr = baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_code_old_version);
			len = read_dword(NULL, baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_code_old_version) + 0x10);
			// #100
			result = read_char(NULL, addr, len);
			return result;
			// #100
		}
		else {//new wxcode
			std::string result;
			addr = baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_code_new_version);
			len = read_dword(NULL, baseaddr_ + static_cast<DWORD>(version::wx_personal_info::wx_code_new_version) + 0x10);
			// #100
			result = read_char(NULL, addr, len);
			
			//std::wstring w_result = utf8_to_ucs2(string_to_char(result));
			//std::string ret = ucs2_to_utf8(wstring_to_wchar(w_result));
			//result = read_wchar(NULL, addr, len);
			//std::string ret = ucs2_to_utf8(wstring_to_wchar(result));
			return result;
			// #100
		}
		
	}
	std::string get_nick() {
		DWORD len;
		len = read_dword(NULL, baseaddr_ + 0x10);		
		std::string nick = read_char(NULL, baseaddr_, len);
		std::wstring w_result = utf8_to_ucs2(string_to_char(nick));
		std::string result = ucs2_to_utf8(wstring_to_wchar(w_result));
		return result;
	}
private:
	DWORD baseaddr_;
	DWORD sign_;
	int type_;
	//msgdispatch_ptr msgdispatch_;
	tinyjson_ptr tinyjson_ptr_;
};//class personal_info
}//namespace wechat
}//namespace arris