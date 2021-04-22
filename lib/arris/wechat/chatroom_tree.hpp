#pragma once
#include <Windows.h>
#include <memory>
#include <list>
#include <vector>
#include <nlohmann/json.hpp>
#include <arris/util/json_util.hpp>
#include <arris/util/log_util.hpp>
#include <arris/util/str_util.hpp>
#include  <arris/util/read_mem.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/wechat/offset_version.hpp>

using nlohmann::json;
using namespace arris::util;
using namespace arris::wechat;

namespace arris {
	namespace wechat {
		class chatroom_tree {
		public:
			chatroom_tree(){
				header_node_ = header_node();
				contact_json_["type"] = static_cast<int>(MsgType::kListChatRoomMember);
			}

			DWORD node() {
				DWORD result = read_dword(NULL, header_node());
				return result;
			}

			std::string to_string(const std::string& id,int type) {
				std::string result;
				try {
					contact_json_["id"] = id;
					result = contact_json_.dump();
				}
				catch (json::exception& e) {
					tinyjson tiny;
					result = tiny.ret_msg(id, kMsgFailedStatus, e.what(),type);
				}
				return result;
			}

			void list_clear() {//2021/02/01  不清除的话，有些更新无效，contact类似
				if (node_list_.size() > 0) {
					node_list_.clear();
					__OutputDebugString(TEXT("node list length:%d\n"),node_list_.size());
				}
				if (contact_json_["content"].size() > 0) {
					contact_json_["content"].clear();
				}
				
			}
			void recurse(DWORD node) {

				//node_list_.clear();
				if (node == header_node_) {
					return;
				}

				for (auto item : node_list_) {
					if (item == node) return;
				}
			
				//__OutputDebugString(TEXT(),room_id.c_str());
				//std::wstring nick = get_nick(node);
				
				DWORD size = read_dword(NULL, node + static_cast<DWORD>(version::chatroom_member_offset::memberid_list_len));
				if (size > 4) {
					node_list_.push_back(node);
					std::string room_id = get_roomid(node);

					json j;
					std::string member_list = get_memberid(node, size);
					std::vector<std::string> member_split = ws_split(member_list, "[\\^][G]");

					if (member_split.size() > 0)
					{
						j["room_id"] = room_id;
						j["address"] = node;
						for (size_t i = 0; i < member_split.size(); i++)
						{
							std::string member = member_split[i];
							if (member.length() > 0)//member id may be is null
							{
								j["member"].push_back(member);
							}
						}
					}
					contact_json_["content"].push_back(j);
				}
				

				DWORD node1 = read_dword(NULL, node);
				DWORD node2 = read_dword(NULL, node + 0x04);
				DWORD node3 = read_dword(NULL, node + 0x08);

				recurse(node1);
				recurse(node2);
				recurse(node3);

			}
			void recurse_old(DWORD node) {
				if (node == header_node_) {
					return;
				}

				for (auto item : node_list_){
					if (item == node) return;
				}
				node_list_.push_back(node);
				
				std::string room_id = get_roomid(node);
				//__OutputDebugString(TEXT(),room_id.c_str());
				//std::wstring nick = get_nick(node);
				json j;
				DWORD size = read_dword(NULL, node + static_cast<DWORD>(version::chatroom_member_offset::memberid_list_len));
				if (size == 0 || size == 4) { 
					__OutputDebugString(TEXT("null node:%x\n"),node);
					return; 
				}//null
				std::string member_list = get_memberid(node,size);
				std::vector<std::string> member_split = ws_split(member_list, "[\\^][G]");
				
				if(member_split.size()>0)
				{
					j["room_id"] = room_id;
					j["address"] = node;
					for (size_t i = 0; i < member_split.size(); i++)
					{
						std::string member = member_split[i];
						if(member.length()>0)//member id may be is null
						{
							j["member"].push_back(member);
						}
					}
				}
				contact_json_["content"].push_back(j);

				DWORD node1 = read_dword(NULL, node);
				DWORD node2 = read_dword(NULL, node + 0x04);
				DWORD node3 = read_dword(NULL, node + 0x08);

				recurse_old(node1);
				recurse_old(node2);
				recurse_old(node3);

			}
		private:

			DWORD header_node() {
				DWORD result = read_dword(NULL, base_node() + static_cast<DWORD>(version::chatroom_member_offset::chatroom_addr_offset));
				return result;
			}
			DWORD base_node() {
				DWORD base_addr = get_wx_baseaddr();
				DWORD addr = read_dword(NULL, base_addr + static_cast<DWORD>(version::contact_data_offset::contact_offset));//和userlist共用
				return addr;
			}
			std::string get_roomid(DWORD node) {
				DWORD size = read_dword(NULL, node + static_cast<DWORD>(version::chatroom_member_offset::room_id_offset)+0x04);
				DWORD addr = read_dword(NULL,node+ static_cast<DWORD>(version::chatroom_member_offset::room_id_offset));
				//std::string room_id = read_char(NULL, addr, size);
				std::wstring temp_id = read_wchar(NULL,addr,size);
				std::string room_id = wstring_to_string(temp_id);
				return room_id;

			}

			std::string get_memberid(DWORD node,DWORD size) {
				//DWORD size = read_dword(NULL, node + static_cast<DWORD>(version::chatroom_member_offset::memberid_list_len));
				DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::chatroom_member_offset::memberid_list_offset));
				std::string	member_id = read_char(NULL, addr, size);
				return member_id;
				//}
				
			}
			/*
			std::wstring get_wxid(DWORD node) {
				DWORD sign = read_dword(NULL,node+ static_cast<DWORD>(version::contact_data_offset::wxid_sign));
				
				if (sign == 0) {
					int size = read_dword(NULL,node + static_cast<DWORD>(version::contact_data_offset::wxid1_len));
					DWORD addr = read_dword(NULL,node + static_cast<DWORD>(version::contact_data_offset::wxid1_offset));
					std::string wxid = read_char(NULL,addr , size);
					std::wstring w_wxid = string_to_wstring(wxid);
					return w_wxid;
				}
				else {
					int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_len));
					DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxid2_offset));
					std::wstring wxid = read_wchar(NULL,addr,size);
					return wxid;
				}
			}
			std::wstring get_nick(DWORD node) {
				int size = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxnick_len));
				DWORD addr = read_dword(NULL, node + static_cast<DWORD>(version::contact_data_offset::wxnick_offset));
				std::wstring nick = read_wchar(NULL, addr, size);
				return nick;
			}*/
		private:
			DWORD header_node_;
			json contact_json_;
			std::list<DWORD> node_list_;
		};//class btree

		using chatroom_tree_ptr = std::unique_ptr<chatroom_tree>;
	}//namespace util
}//namespace arris