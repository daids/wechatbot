#pragma once

#include <Windows.h>
#include <arris/wechat/base.hpp>
#include <arris/wechat/constant.hpp>
#include <arris/util/log_util.hpp>
#include <arris/util/str_util.hpp>
#include <arris/util/json_util.hpp>
#include <nlohmann/json.hpp>
using nlohmann::json;
using namespace arris::util;
namespace arris{
namespace wechat{

class detail :public iwxmsg {
public:
	detail():
		type_(static_cast<int>(MsgType::kPersonalDetail)) 
	{}
    ~detail() = default;
public:
	virtual std::string handle_msg(const wx_msg& v_st_msg) override {
        std::string msg = to_string(v_st_msg);
        return msg;

	}
	virtual int get_type()	override {
		return type_;
	}
private:
	std::string to_string(const wx_msg& v_st_msg) {
        char* d = {0};
        DWORD edi = get_detail(v_st_msg.wxid);

        // 0xF4  0x108 
        std::wstring pic = get_pic(edi,0xF4);
        std::wstring png = get_pic(edi,0x108);

        json j;
        j["wxid"] = ucs2_to_utf8(wstring_to_wchar(v_st_msg.wxid));
        j["pic"] = ucs2_to_utf8(wstring_to_wchar(pic));
        j["img"] = ucs2_to_utf8(wstring_to_wchar(png));

        json jmsg;
        jmsg["id"] = v_st_msg.id;
        jmsg["content"] = j;
        jmsg["sender"] = kServerSide;
        jmsg["receiver"] = kClientSide;
        jmsg["srvid"] = MsgType::kServerSideMsg;
        jmsg["time"] = s_wxtime();
        jmsg["type"] = type_;
        jmsg["status"] = kMsgOkStatus;
        std::string result;
        try {
            result = jmsg.dump();
        }
        catch (json::exception& e)
        {
            tinyjson tiny;
            result = tiny.ret_msg(time2id(), kMsgFailedStatus, e.what(), type_);
        }
        return result;

	}
    std::wstring get_pic(DWORD edi,DWORD offset) {
        int size = read_dword(NULL, edi + +offset + 0x4);//0xF4
        DWORD addr = read_dword(NULL, edi + offset);//static_cast<DWORD>(version::contact_data_offset::wxnick_offset));
        std::wstring nick = read_wchar(NULL, addr, size);
        return nick;
    }
    DWORD get_detail(std::wstring wxid) {
        char buf[0x3e0] = { 0 };
        wxid_st temp = { 0 };
        temp.pstr = (wchar_t*)wxid.c_str();
        temp.len = wxid.size();
        temp.max_len = wxid.size() * 2;

        DWORD call_1 = get_wx_baseaddr() + 0x58C9E0;
        //DWORD call_2 = //Util->Offset(0x7AD11900 - 0x7ACB0000);
            //Util->Offset(0x7B2241C0 - 0x7ACB0000);
        DWORD call_2 = get_wx_baseaddr() + 0x63660;

            //Util->Offset(0x7AD11900 - 0x7ACB0000);
        DWORD call_3 = get_wx_baseaddr() + 0x323840;
            //Util->Offset(0x7AFC9E70 - 0x7ACB0000);
        __OutputDebugString(TEXT("call_3:%0x\n"), call_3);
        __OutputDebugString(TEXT("call_2:%0x\n"), call_2);
        __OutputDebugString(TEXT("call_1:%0x\n"), call_1);
        DWORD result = 0;
        __asm {
            pushad;
            pushfd;

            //mov edi, buf;//buff = 0x3E0
            lea edi,buf
            push edi;
            sub esp, 0x14;
            lea eax, temp;
            mov ecx, esp;
            push eax;

            call call_1;
            call call_2;
            call call_3;

            mov result, edi;

            popfd;
            popad;
        }
        //return result == 1;
        return result;
    }

private:
	int type_;
};

}//namespace wechat
}//namespace arris


/*
0EE7E628            00000000  ....
0EE7E62C            00000000  ....
0EE7E630            0FFAF708  .÷ú.  L"wxid_ktwum1lm0nry22"
0EE7E634            00000013  ....
0EE7E638            00000014  ....
0EE7E63C            00000000  ....
0EE7E640            00000000  ....
0EE7E644            062AB038  8°*.  L"loc012"
0EE7E648            00000006  ....
0EE7E64C            00000006  ....
0EE7E650            00000000  ....
0EE7E654            00000000  ....
0EE7E658            17112928  ()..  L"v3_020b3826fd030100000000001cd01941aab656000000501ea9a3dba12f95f6b60a0536a1adb63fe0cf60f3f349b29f98deb59b95224f16c63079093940113974a32c83c4add550c7e837419bc614a1118bab66fee4dc60c6c707d3909953a78a97fb@stranger"
0EE7E65C            000000D0  Ð...
0EE7E660            000000D0  Ð...
0EE7E664            00000000  ....
0EE7E668            00000000  ....
0EE7E66C            00000000  ....
0EE7E670            00000001  ....
0EE7E674            00000000  ....
0EE7E678            17935800  .X..  L"AAC"

*/