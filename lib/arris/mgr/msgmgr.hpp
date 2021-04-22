#pragma once

#include <unordered_map>
#include <memory>
#include <arris/mgr/mgr.hpp>
#include <arris/wechat/base.hpp>

#include <arris/wechat/personal_info.hpp>
#include <arris/wechat/contact.hpp>
#include <arris/wechat/chatroom.hpp>
#include <arris/wechat/sendtxtmsg.hpp>
#include <arris/wechat/room_nick.hpp>
#include <arris/wechat/sendpic.hpp>
#include <arris/wechat/attatch.hpp>
#include <arris/wechat/atmsg.hpp>

//------------------hook-----------------------
#include <arris/hook/txtmsg_hook.hpp>


//------------------hook-----------------------
using namespace arris::wechat;
using namespace arris::objectmgr;
//using namespace arris::wechat;
namespace arris {
	namespace objectmgr {
		//template<typename T>
		class msgmgr {
		public:
			msgmgr() {
				mgr_ptr_ = std::make_unique<mgr<iwxmsg, wx_msg, std::string>>();
				init();
			}
			msgmgr(DWORD eax):eax_(eax) {
				mgr_ptr_ = std::make_unique<mgr<iwxmsg, wx_msg, std::string>>();
				init();
			}
			~msgmgr() = default;
			/*~msgmgr() {
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
			std::string run(const int type, const wx_msg& st_msg) {
				return mgr_ptr_->run(type, st_msg);
			}

			/*void run(const int type) {
				mgr_ptr_->run(type);
			}*/

			
		private:
			void init() {
				//p_personal_info_ = new personal_info();
				//mgr_ptr_->add(p_personal_info_->get_type(), p_personal_info_);
				
				// p_contact_ = new contact();
				//mgr_ptr_->add(p_contact_->get_type(), p_contact_);
				/*
				p_chatroom_ = new chatroom();
				mgr_ptr_->add(p_chatroom_->get_type(), p_chatroom_);

				p_sendtxtmsg_ = new send_txt_msg();
				mgr_ptr_->add(p_sendtxtmsg_->get_type(), p_sendtxtmsg_);
				
				p_room_nick_ = new room_nick();
				mgr_ptr_->add(p_room_nick_->get_type(), p_room_nick_);

				p_sendpic_ = new send_pic();
				mgr_ptr_->add(p_sendpic_->get_type(), p_sendpic_);

				p_txtmsg_hook_ = new txtmsg_hook(eax_);
				mgr_ptr_->add(p_txtmsg_hook_->get_type(), p_txtmsg_hook_);
				
				p_attatch_ = new attatch();
				mgr_ptr_->add(p_attatch_->get_type(), p_attatch_);

				p_atmsg_ = new atmsg();
				mgr_ptr_->add(p_atmsg_->get_type(), p_atmsg_);*/

			    //contact_ptr = std::make_unique<contact>();
				//mgr_ptr_->add(contact_ptr->get_type(), std::move(contact_ptr));
				//std::unique_ptr<iwxmsg> contact_ptr = std::make_unique<contact>();
				//mgr_ptr_->add(contact_ptr->get_type(), std::move(contact_ptr));

				
				std::unique_ptr<iwxmsg> personal_info_ptr = std::make_unique<personal_info>();
				mgr_ptr_->add(personal_info_ptr->get_type(), std::move(personal_info_ptr));
				
				

				std::unique_ptr<iwxmsg> room_ptr = std::make_unique<chatroom>();
				mgr_ptr_->add(room_ptr->get_type(), std::move(room_ptr));

				std::unique_ptr<iwxmsg> sendtxt_ptr = std::make_unique<send_txt_msg>();
				mgr_ptr_->add(sendtxt_ptr->get_type(), std::move(sendtxt_ptr));

				std::unique_ptr<iwxmsg> roomnick_ptr = std::make_unique<room_nick>();
				mgr_ptr_->add(roomnick_ptr->get_type(), std::move(roomnick_ptr));

				std::unique_ptr<iwxmsg> sendpic_ptr = std::make_unique<send_pic>();
				mgr_ptr_->add(sendpic_ptr->get_type(), std::move(sendpic_ptr));

				std::unique_ptr<iwxmsg> hooktxtmsg_ptr = std::make_unique<txtmsg_hook>(eax_);
				mgr_ptr_->add(hooktxtmsg_ptr->get_type(), std::move(hooktxtmsg_ptr));

				std::unique_ptr<iwxmsg> attatch_ptr = std::make_unique<attatch>();
				mgr_ptr_->add(attatch_ptr->get_type(), std::move(attatch_ptr));

				std::unique_ptr<iwxmsg> atmsg_ptr = std::make_unique<atmsg>();
				mgr_ptr_->add(atmsg_ptr->get_type(), std::move(atmsg_ptr));
			}
			
		private:
			DWORD eax_;
			std::unique_ptr<mgr<iwxmsg, wx_msg, std::string>> mgr_ptr_;
			//std::unique_ptr<iwxmsg> contact_ptr;
			//iwxmsg* p_contact_;
			//std::unordered_map<int, T*> obj_map_;
			//std::unique_ptr<mgr<iwxmsg>> mgr_ptr_;
			/*iwxmsg* p_personal_info_;
			iwxmsg* p_contact_;
			iwxmsg* p_chatroom_;
			iwxmsg* p_sendtxtmsg_;
			iwxmsg* p_room_nick_;
			iwxmsg* p_sendpic_;
			iwxmsg* p_txtmsg_hook_;
			iwxmsg* p_attatch_;
			iwxmsg* p_atmsg_;*/
		};//class msg_mgr


	}//namespace wechat
}//namespace arris