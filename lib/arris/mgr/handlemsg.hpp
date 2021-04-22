#pragma once

#include <memory>
#include <string>
#include <arris/mgr/msgmgr.hpp>
#include <arris/util/json_util.hpp>

using namespace arris::util;
namespace arris {
namespace objectmgr {
	//template<typename T>
class handlemsg final{
public:
	handlemsg() {
		msgmgr_ = std::make_unique<msgmgr>();
		tinyjson_ = std::make_unique<tinyjson>();
		//msgmgr_->run
	}
	std::string msg(const std::string& msg) {
		//std::wstring wmsg = string_to_wstring(msg);
		//string_to_char(msg)
			
		//
		std::wstring wmsg = utf8_to_ucs2(string_to_char(msg));
		__OutputDebugString(TEXT("size:%d msg:%s"), wmsg.size(),wmsg.c_str());
		bool js_json_type = tinyjson_->is_json(msg);
		if (js_json_type == true) {
			int type = tinyjson_->get_type(msg);
			wx_msg st_msg = tinyjson_->get_st(msg);
			__OutputDebugString(TEXT("handle_msg type:%d"),type);
			//__OutputDebugString();
			return msgmgr_->run(type, st_msg);
		}
		return "msg exception";
	}

	std::string msg(const std::string& para, const std::string& msg) {
		bool js_json_type = tinyjson_->is_json(msg);
		if (js_json_type == true) {
			int type = tinyjson_->get_type(para,msg);
			wx_msg st_msg = tinyjson_->get_st(para,msg);
			return msgmgr_->run(type, st_msg);
		}
		return "msg exception";
	}

	
private:
	std::unique_ptr<msgmgr> msgmgr_;
	std::unique_ptr<tinyjson> tinyjson_;

};//class handlemsg
}//namespace objectmgr
}//namespace arris