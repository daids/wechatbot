#pragma once

#pragma once

#include <arris/wechat/base.hpp>
#include <arris/util/log_util.hpp>
#include <unordered_map>

#include <arris/wechat/personal_info.hpp>
//#include <arris/wechat/contact.hpp>
#include <arris/wechat/chatroom.hpp>
#include <arris/wechat/sendtxtmsg.hpp>
#include <arris/wechat/room_nick.hpp>
#include <arris/wechat/sendpic.hpp>
#include <arris/wechat/attatch.hpp>
#include <arris/wechat/atmsg.hpp>
#include <arris/wechat/txl.hpp>
#include <arris/hook/friend_request.hpp>
#include <arris/hook/txtmsg_hook.hpp>
#include <arris/hook/agree_friend_request.hpp>
//#include <arris/wechat/friend_detail.hpp>
#include <arris/wechat/detail.hpp>
using namespace arris::wechat;
using namespace arris::util;

namespace arris {
	namespace objectmgr {
		class mgrnew {
		public:
			mgrnew() {
				tinyjson_ = std::make_unique<tinyjson>();
				init();
			}
			
			mgrnew(DWORD eax):eax_(eax) {
				tinyjson_ = std::make_unique<tinyjson>();
				init_hook();
			}
			~mgrnew() = default;
			/*~mgrnew() {
				typename std::unordered_map<int, iwxmsg*>::iterator  iter = obj_map_.begin();
				for (; iter != obj_map_.end(); iter++) {
					if ((*iter).second != nullptr) {//first key,second value
						try {
							delete (*iter).second;//free pointer
							(*iter).second = nullptr;
						}
						catch (...) {
							__OutputDebugString(TEXT("mgr error:free pointer\n"));
						}
					}
				}
			}*/
			std::string msg(const std::string& para, const std::string& msg) {
				bool js_json_type = tinyjson_->is_json(msg);
				if (js_json_type == true) {
					int type = tinyjson_->get_type(para, msg);
					wx_msg st_msg = tinyjson_->get_st(para, msg);
					return run(type, st_msg);
				}
				else {
					return tinyjson_->ret_msg(time2id(), kMsgFailedStatus, "not json type", static_cast<int>(MsgType::kAbnormalMsg));
				}
			}
			std::string msg(const std::string& msg) {
				bool js_json_type = tinyjson_->is_json(msg);
				if (js_json_type == true) {
					int type = tinyjson_->get_type(msg);
					wx_msg st_msg = tinyjson_->get_st(msg);
					//__OutputDebugString(TEXT("handle_msg type:%d"), type);
					return run(type, st_msg);
				}
				else {
					return tinyjson_->ret_msg(time2id(), kMsgFailedStatus,"not json type", static_cast<int>(MsgType::kAbnormalMsg));
				}
			}
			std::string run(const int type, const wx_msg& st_msg) {
				__OutputDebugString(TEXT("msg run....."));
				if (exist(type) == false) {
					__OutputDebugString(TEXT("the type is not exist!"));
					return "null";
				}
				try {
					if (obj_map_.find(type) == obj_map_.end()) {
						__OutputDebugString(TEXT("obj map not found"));
					}
					else {
						__OutputDebugString(TEXT("obj map found"));
					}

					//int type=obj_map_[type]->get_type();
					__OutputDebugString(TEXT("run type is:%d"),type);
					return obj_map_[type]->handle_msg(st_msg);
				}
				catch (...) {
					__OutputDebugString(TEXT("type no error:%d\n"), type);
					return "execption";
				}
			}

		private:
			/*void add(int type, iwxmsg* p) {
				obj_map_.insert(std::make_pair(type, p));
			}*/
			void add(int type,std::unique_ptr<iwxmsg> ptr) {
				obj_map_.insert(std::make_pair(type, std::move(ptr)));
			}
			void init_hook() {
				std::unique_ptr<txtmsg_hook> p_txtmsg_hook_ = std::make_unique<txtmsg_hook>(eax_);
				add(p_txtmsg_hook_->get_type(), std::move(p_txtmsg_hook_));

				std::unique_ptr<friend_request_msg> p_friendrequest_hook_ = std::make_unique<friend_request_msg>(eax_);
				add(p_friendrequest_hook_->get_type(), std::move(p_friendrequest_hook_));

				std::unique_ptr<agree_friend_request_msg> p_agree_friendrequest_hook_ = std::make_unique<agree_friend_request_msg>(eax_);
				add(p_agree_friendrequest_hook_->get_type(), std::move(p_agree_friendrequest_hook_));
			}
			void init() {
				std::unique_ptr<txl> p_contact_ = std::make_unique<txl>();
				add(p_contact_->get_type(), std::move(p_contact_));

				std::unique_ptr<personal_info> p_personal_info_ = std::make_unique<personal_info>();
				add(p_personal_info_->get_type(), std::move(p_personal_info_));

				std::unique_ptr<chatroom> p_chatroom_ = std::make_unique<chatroom>();
				add(p_chatroom_->get_type(), std::move(p_chatroom_));

				std::unique_ptr<send_txt_msg> p_sendtxtmsg_ = std::make_unique<send_txt_msg>();
				add(p_sendtxtmsg_->get_type(), std::move(p_sendtxtmsg_));

				std::unique_ptr<room_nick> p_room_nick_ = std::make_unique<room_nick>();
				add(p_room_nick_->get_type(), std::move(p_room_nick_));

				std::unique_ptr<send_pic> p_sendpic_ = std::make_unique<send_pic>();
				add(p_sendpic_->get_type(), std::move(p_sendpic_));

				std::unique_ptr<attatch> p_attatch_ = std::make_unique<attatch>();
				add(p_attatch_->get_type(), std::move(p_attatch_));

				std::unique_ptr<atmsg> p_atmsg_ = std::make_unique<atmsg>();
				add(p_atmsg_->get_type(), std::move(p_atmsg_));

				std::unique_ptr<detail> p_friend_detail_ = std::make_unique<detail>();
				add(p_friend_detail_->get_type(), std::move(p_friend_detail_));
			}
			bool exist(int type) {
				bool is_exist = true;
				size_t n = obj_map_.count(type);
				if (n == 0) {
					is_exist = false;
				}
				return is_exist;
			}

		private:
			DWORD eax_;
			std::unordered_map<int, std::unique_ptr<iwxmsg>> obj_map_;
			std::unique_ptr<tinyjson> tinyjson_;
			/*iwxmsg* p_contact_;
			iwxmsg* p_personal_info_;
			iwxmsg* p_chatroom_;
			iwxmsg* p_sendtxtmsg_;
			iwxmsg* p_room_nick_;
			iwxmsg* p_atmsg_;
			iwxmsg* p_attatch_;
			iwxmsg* p_txtmsg_hook_;
			iwxmsg* p_sendpic_;*/
		};//class mgr
	}//namespace mgr
}//namespace arris