#pragma once
#include <Windows.h>
#include <arris/wechat/base.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/offset_version.hpp>
#include <arris/util/read_mem.hpp>
#include <nlohmann/json.hpp>
#include <arris/util/str_util.hpp>
#include <arris/util/json_util.hpp>
#include <arris/wechat/msgdispatch.hpp>
using nlohmann::json;
namespace arris {
namespace wechat {
class friend_request_msg :public iwxmsg {
public:
	friend_request_msg(DWORD eax)://kHookNewFriendRequest
		type_(static_cast<int>(MsgType::kHookNewFriendRequest)),
		eax_(eax) 
	{
		msgdispatch_ = std::make_unique<msgdispatch>();
	}
	~friend_request_msg() = default;
public:
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
		std::string msg = to_string();
		msgdispatch_->send_to_queue(msg);
		return msg;
	}
	virtual int get_type() override {
		return type_;
	}
private:
	std::string to_string() {
		json j;
		j["id"] = time2id();
		j["sender"] = kServerSide;
		j["receiver"] = kClientSide;
		j["status"] = kMsgOkStatus;
		j["content"] = ucs2_to_utf8(wstring_to_wchar(get_msgcontent()));;
		j["time"] = s_wxtime();
		j["type"] = type_;
		j["srvid"] = MsgType::kServerSideMsg;
		std::string result;
		try {
			result = j.dump();
		}
		catch (json::exception& e) {
			tinyjson tiny;
			result = tiny.ret_msg(time2id(), kMsgFailedStatus, e.what(), type_);
		}
		return result;


	}
	std::wstring get_msgcontent() {
		DWORD size = static_cast<DWORD>(version::hook_friendrequest_offset::msg_content_offset) + 0x4;
		DWORD addr = static_cast<DWORD>(version::hook_friendrequest_offset::msg_content_offset);
		//__OutputDebugString(TEXT("size addr:%x\n"),size_addr);
		//__OutputDebugString(TEXT("wxid_addr addr:%x\n"), wxid_addr);

		std::wstring content = getwstr_from_addr(eax_, size,addr);
		return content;
	}
private:
	int type_;
	DWORD eax_;
	msgdispatch_ptr msgdispatch_;
};
}//namespace wechat
}//namespace arris