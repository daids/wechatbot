#pragma once

namespace arris {
	namespace wechat {
		class version {//
		public:
			enum class chatroom_member_offset {
				chatroom_addr_offset=0x8c8,//0x840+0x88
				room_id_offset=0x10,
				memberid_list_offset = 0x3c,
				memberid_list_len = 0x4c

			};
			enum class contact_data_offset
			{
				contact_offset = 0x1A8818C,//==chatroom_offset 1A8818C
				contact_addr_offset = 0xB4,//0x28+0x8c
				wxid_sign   = 0x14,
				wxid1_offset = 0x10,
				wxid1_len = 0x20,
				wxid2_offset = 0x30,
				wxid2_len    = 0x34,
				wxcode_offset = 0x44,
				wxnick_offset = 0x8c,
				wxnick_len = 0x90,
				wx_remarks=0x78,//0x78+0x4 length
				wx_headimg=0x130//0x130+0x4 length
			};

			enum class hook_common_offset {//3.2.1.154
				hook_point_offset = 0x3DF42C,
				call_offset = 0x87A70
			};
			enum class hook_msg_type {
				hook_msg_type_offset = 0x30
			};
			enum class hook_txtmsg_offset {
				wxid_offset = 0x40,
				msg_content_offset = 0x68,
				group_msg_sender_offset = 0x164,
				xml_content_offset=0x1b8,
				by_atmsg_wxid_offset=0x2dc,//被At消息人的wxid
				sender_offset1=0x308
			};
			enum class hook_friendrequest_offset {
				msg_content_offset=0x68
			};
			enum class send_txtmsg_offset {//3.2.1.154
				send_call_addr = 0x10CCFB,
			};

			enum class send_xmlmsg_offset {
				call_addr = 0x2C389D
			};
			
			enum class wx_personal_info {
				wx_name_offset = 0x1AA6C1C,//start address
				wx_code_length_offset = 0x174,
				wx_code_new_version = 0x164,
				wx_code_old_version = 0x41c,//asc
				wx_id_offset = 0x41c,
				//wx_headimg_132=0x2e0//asc
			};

			enum class send_picmsg_offset {
				call1_offset = 0x58C9E0,
				call2_offset = 0x63720,
				call3_offset = 0x3B4F60
			};
		};
	}
}