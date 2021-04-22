#pragma once
#include <memory>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/base.hpp>
//#include <arris/wechat/msgtoqueue.hpp>
#include <arris/wechat/chatroom_tree.hpp>
using namespace arris::wechat;

namespace arris {
namespace wechat {
class chatroom :public iwxmsg {
public:
	chatroom() {
		type_ = static_cast<int>(MsgType::kListChatRoomMember);
		chatroom_tree_ = std::make_unique<chatroom_tree>();
		//msgtoqueue_ = std::make_unique<msgtoqueue>();
		//__OutputDebugString(TEXT("chatroom create"));
	}
	~chatroom() = default;/* {
		__OutputDebugString(TEXT("chatroom destroy"));
	}*/
	virtual std::string handle_msg(const wx_msg& v_st_msg) override{
		DWORD node = chatroom_tree_->node();
		chatroom_tree_->list_clear();
		__OutputDebugString(TEXT("char room node:%x\n"),node);
		chatroom_tree_->recurse(node);
		std::string msg = chatroom_tree_->to_string(v_st_msg.id,type_);
		return msg;
		//msgtoqueue_->send_to_queue(msg);
	}
	virtual int get_type() override{
		return type_;
	}
	//virtual void set_data(const wx_msg& msg) {};

private:
	int type_;
	chatroom_tree_ptr chatroom_tree_;
	//msgtoqueue_ptr msgtoqueue_;
};
}//namespace wechat
}//namespace arris