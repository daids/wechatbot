#pragma once

#pragma once

#include <memory>
#include <string>
namespace arris {
	namespace wechat {
		class room_at {
		public:
			wchar_t* roomid;
			int len;
			int max_len;
			int temp1 = 0;
			int temp2 = 0;
			int temp3 = 0;
		};
		struct wxid_st
		{
			wchar_t* pstr;
			int len;
			int max_len;
			int temp1 = 0;
			int temp2 = 0;
		};
		struct wx_msg {
			std::string id;
			std::wstring wxid;
			std::wstring roomid;
			std::wstring content;
			std::wstring nickname;
			std::wstring ext;
		};

		/*struct st_personal_detail {
			char top[0x8];
			wxid_st wxid;
			wxid_st account;
			wxid_st vData;
			int un_0;
			int un_1;
			char un_2[0x18];
			wxid_st name;
			char un_3[0x28];
			int un_4;
			wxid_st nameUpper;
			wxid_st nameUn;
			char un_5[0x28];
			wxid_st pic;
			wxid_st img;
			char* md5;
			char un_6[0xC];
			int un_7;
			int addSource;
			char un_8[0x2AC];
		};*/

		//class imsg {};
		//using imsg_ptr = std::unique_ptr<imsg>;
		class iwxmsg {
		public:
			virtual ~iwxmsg() {}
			virtual std::string handle_msg(const wx_msg& msg) = 0;
			virtual int get_type() = 0;
		};//class iwxbase

		using iwxmsg_ptr = std::unique_ptr<iwxmsg>;
		template<typename T>
		class wxmsgfactory {
		public:
			virtual iwxmsg_ptr create() = 0;
			virtual ~wxmsgfactory() {}
		};//class wxmsgfactory

		template<typename T, typename Q>
		class msgconcreate :public wxmsgfactory<T> {
		public:
			~msgconcreate() {}
			virtual iwxmsg_ptr create() {
				return std::make_unique<Q>();
			}
		};//class msgconcreate

	}//namespace wechat
}//namespace arris