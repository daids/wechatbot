#pragma once
#include <nlohmann/json.hpp>
#include <arris/util/log_util.hpp>
#include <arris/util/str_util.hpp>
#include <arris/util/utf8.hpp>
#include <arris/wechat/constant.hpp>
//using namespace arris::net;
using nlohmann::json;
using namespace arris::util;
using namespace arris::wechat;


namespace arris {
namespace util {

class tinyjson final{
public:
	tinyjson() = default;
	~tinyjson() = default;

	bool is_json(const std::string& str) {
		//__OutputDebugString(TEXT("is json string:%s\n"),str.c_str());
		bool is_json_type = true;
		try {
			json_obj_ = nlohmann::json::parse(str);
		}
		catch (json::exception& e) {
			std::wstring str = string_to_wstring(e.what());
			//__OutputDebugString(TEXT("error:%s\n"), str.c_str());
			is_json_type = false;
		}
		return is_json_type;
	}

	std::string ret_msg(const std::string& id,const std::string& status,const std::string& content,int type) {
		json j;
		j["id"] = id;
		j["sender"] = kServerSide;
		j["receiver"] = kClientSide;
		j["status"] = status;
		j["content"] = content;
		j["time"] = s_wxtime();
		j["type"] = type;
		j["srvid"] = MsgType::kServerSideMsg;

		std::string dump_str = j.dump();
		return dump_str;
	}
	

	json parser(const std::string& str) {
		//std::wstring wstr = string_to_wstring(str);
		json j;
		try {
			j = nlohmann::json::parse(str);
		}
		catch (json::exception& e) {
			__OutputDebugString(TEXT("error:%s\n"), e.what());
		}
		return j;
	}

	int get_type(const std::string& str) {//for ws
		int type;
		try {
			json j = parser(str);
			type = j["type"];
		}
		catch (json::exception& e) {
			type = -1;
		}
		
		return type;
	}

	int get_type(const std::string& para, const std::string& str) {//for http
		int type;
		try {
			json j = parser(str);
			type = j[para]["type"];
		}
		catch (json::exception& e) {
			type = -1;
		}
		
		return type;
	}


	wx_msg get_st(const std::string& para, const std::string& str) {//for http
		
		wx_msg st;
		std::string s_wxid;
		std::string s_roomid;
		std::string s_content;
		std::string s_nickname;
		std::string s_ext;
		std::string s_id;
		try {

			json j = parser(str);
			s_id = j[para]["id"];
			s_wxid = j[para]["wxid"];
			s_roomid = j[para]["roomid"];
			s_content = j[para]["content"];
			s_nickname = j[para]["nickname"];
			s_ext = j[para]["ext"];
		}
		catch (json::exception& e) {
			s_content = e.what();
		}

		st.id = s_id;
		st.wxid = utf8_to_ucs2(string_to_char(s_wxid));
		st.roomid = utf8_to_ucs2(string_to_char(s_roomid));
		st.content = utf8_to_ucs2(string_to_char(s_content));
		st.nickname = utf8_to_ucs2(string_to_char(s_nickname));
		st.ext = utf8_to_ucs2(string_to_char(s_ext));
	
		return st;
	}
	wx_msg get_st(const std::string &str) {//for ws
		
		wx_msg st;
		std::string s_wxid;
		std::string s_roomid;
		std::string s_content;
		std::string s_nickname;
		std::string s_ext;
		std::string s_id;
		try{
		json j = parser(str);
		s_id = j["id"];
		s_wxid = j["wxid"];
		s_roomid = j["roomid"];
		s_content = j["content"];
		s_nickname = j["nickname"];
		s_ext = j["ext"];
		}
		catch (json::exception& e) {
			s_content = e.what();
		}
		st.id = s_id;
		st.wxid = utf8_to_ucs2(string_to_char(s_wxid));
		st.roomid = utf8_to_ucs2(string_to_char(s_roomid));
		st.content = utf8_to_ucs2(string_to_char(s_content));
		st.nickname = utf8_to_ucs2(string_to_char(s_nickname));
		st.ext      = utf8_to_ucs2(string_to_char(s_ext));


		return st;
	}
	std::string dump(const json& j,const int type) {
		std::string result;
		try {
			result = j.dump();
		}
		catch (json::exception& e) {
			//__OutputDebugString(TEXT("error:%s\n"), e.what());
			result = ret_msg(time2id(), kMsgFailedStatus,e.what(),type);
		}
		return result;
	}
//protected:
	//json opr() {
	//}
	
private:
	json json_obj_;
};// class tinyjson

using tinyjson_ptr = std::unique_ptr<tinyjson>;

}//namespace util
}//namespace arris