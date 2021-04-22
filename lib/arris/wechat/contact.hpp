#pragma once
#include <memory>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/base.hpp>
#include <arris/wechat/msgdispatch.hpp>
#include <arris/wechat/contact_tree.hpp>
using namespace arris::wechat;

namespace arris {
namespace wechat {
class contact :public iwxmsg {
public:
	contact() {
		//MsgType::kUserListFromContact
		type_ = static_cast<int>(MsgType::kUserListFromContact);
		contact_tree_ = std::make_unique<contact_tree>();
	}
	~contact() = default;
	virtual std::string handle_msg(const wx_msg& v_st_msg) override{
		
		DWORD node = contact_tree_->node();
		contact_tree_->list_clear();
		contact_tree_->recurse(node);
		std::string msg = contact_tree_->to_string(v_st_msg.id,type_);
		//msgdispatch_->send_to_queue(msg);
		//std::wstring wmsg = utf8_to_ucs2(string_to_char(msg));
		//__OutputDebugString(TEXT("node %x,contact msg return:%s"),node,wmsg.c_str());
		return msg;
	}
	virtual int get_type() override{
		return type_;
	}
	//virtual void set_data(const wx_msg& msg) {};

private:
	int type_;
	contact_tree_ptr contact_tree_;
	//msgdispatch_ptr msgdispatch_;
};
}//namespace wechat
}//namespace arris