#pragma once
#include <arris/wechat/base.hpp>
namespace arris {
namespace wechat {
class txl :public iwxmsg {

public:
	txl():
		type_(static_cast<int>(MsgType::kUserListFromContact))
		, header_node_(header_node())
	{
	}
	virtual std::string handle_msg(const wx_msg& v_st_msg) override{
		//tinyjson tiny;
		//std::string result = tiny.ret_msg(time2id(), kMsgFailedStatus, "test message", 5000);
		//return result;
		//return "hello world";
		__OutputDebugString(TEXT("handle_msg is begin"));
		DWORD root_node = rootnode();
		list_clear();
		__OutputDebugString(TEXT("rootnode is begin"));
		recurse(root_node);
		__OutputDebugString(TEXT("recurse is begin"));
		std::string msg =to_string(v_st_msg.id, type_);
		//msgdispatch_->send_to_queue(msg);
		//std::wstring wmsg = utf8_to_ucs2(string_to_char(msg));
		//__OutputDebugString(TEXT("node %x,contact msg return:%s"), root_node, wmsg.c_str());
		return msg;
	}
	virtual int get_type()override {
		return type_;
	}
private:
	std::string to_string(const std::string& id, int type) {
		std::string result;
		try {
			contact_json_["id"] = id;
			contact_json_["type"] = type_;
			result = contact_json_.dump();
			//std::wstring tmpstr = utf8_to_ucs2(string_to_char(result));
			//__OutputDebugString(TEXT("contact dump:%d"), result.size());

		}
		catch (json::exception& e) {
			tinyjson tiny;
			result = tiny.ret_msg(id, kMsgFailedStatus, e.what(), type);
		}
		return result;
	}
	void recurse(DWORD node) {
		//node_list_.clear();
		if (node == header_node_) {
			return;
		}

		for (auto item : node_list_) {
			if (item == node) return;
		}
		node_list_.push_back(node);

		std::wstring id = get_wxid(node);
		std::wstring nick = get_nick(node);
		std::wstring wxcode = get_wxcode(node);
		std::wstring headimg = get_headimg(node);
		std::wstring remarks = get_remarks(node);
		json j;
		
		j["wxid"] = wstring_to_string(id);
		j["node"] = node;
		j["name"] = ucs2_to_utf8(wstring_to_wchar(nick));
		j["wxcode"] = ucs2_to_utf8(wstring_to_wchar(wxcode));
		j["headimg"] = ucs2_to_utf8(wstring_to_wchar(headimg));
		j["remarks"] = ucs2_to_utf8(wstring_to_wchar(remarks));
		contact_json_["content"].push_back(j);

		DWORD node1 = read_dword(NULL, node);
		DWORD node2 = read_dword(NULL, node + 0x04);
		DWORD node3 = read_dword(NULL, node + 0x08);

		recurse(node1);
		recurse(node2);
		recurse(node3);

	}
	void list_clear() {

		//     #5

		if (node_list_.size() > 0) {
			node_list_.clear();
		}

		//    #6
		if (contact_json_["content"].size() > 0) {
			contact_json_["content"].clear();
		}
		//
		if (contact_json_.size() > 0) {
			contact_json_.clear();
		}

	}
	DWORD rootnode() {
		DWORD result = read_dword(NULL, header_node());
		return result;
	}
	DWORD header_node() {
		DWORD result = read_dword(NULL, base_node() + static_cast<DWORD>(version::contact_data_offset::contact_addr_offset));
		return result;
	}
	DWORD base_node() {
		DWORD base_addr = get_wx_baseaddr();
		DWORD addr = read_dword(NULL, base_addr + static_cast<DWORD>(version::contact_data_offset::contact_offset));
		return addr;
	}
	std::wstring get_wxid(DWORD node) {
		DWORD sign = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid_sign));

		if (sign == 0) {
			int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid1_len));
			DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid1_offset));
			std::string wxid = read_char(NULL, addr, size);
			std::wstring w_wxid = string_to_wstring(wxid);
			return w_wxid;
		}
		else {
			int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_len));
			DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_offset));
			std::wstring wxid = read_wchar(NULL, addr, size);
			return wxid;
		}
	}
	std::wstring get_nick(DWORD node) {
		int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxnick_len));
		DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxnick_offset));
		std::wstring nick = read_wchar(NULL, addr, size);
		return nick;
	}
	std::wstring get_remarks(DWORD node) {
		int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wx_remarks)+0x4);
		if (size==0) {
			return TEXT("");
		}
		DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wx_remarks));
		std::wstring remarks = read_wchar(NULL, addr, size);
		return remarks;
	}
	std::wstring get_headimg(DWORD node) {
		int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wx_headimg)+0x4);
		if (size==0) {
			return TEXT("");
		}

		DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wx_headimg));
		
		std::wstring headimg = read_wchar(NULL, addr, size);
		__OutputDebugString(TEXT("addr:%x size:%d node:%x headimg size:%d"), addr, size, node,headimg.size());
		return headimg;
	}

	std::wstring get_wxcode(DWORD node) {
		int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxcode_offset)+0x4);//如果44=0就去找30
		if (size == 0) {
			//return TEXT("");
			int len = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_offset) + 0x4);
			DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_offset));
			//DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxcode_offset));
			std::wstring wxcode = read_wchar(NULL, addr, len);
			return wxcode;
		}
		DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxcode_offset));
		std::wstring wxcode = read_wchar(NULL, addr, size);
		return wxcode;
	}
private:
	json contact_json_;
	std::list<DWORD> node_list_;
	int type_;
	DWORD header_node_;
};
}
}