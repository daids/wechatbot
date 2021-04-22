#pragma once

#include <iostream>
#include <string>
#include <list>
#include <arris/util/str_util.hpp>

using namespace arris::util;

namespace arris {
namespace util {
class urlparser final {
public:
	urlparser() = default;
	~urlparser() = default;
	std::string getpara(const std::string& url) {
        std::string strRequestOperateCommand = "";
        std::list<st_name_and_value> listRequestOperateParameter;	//操作参数列表	
        get_httpreqeust_command_and_parmeter(url, strRequestOperateCommand, listRequestOperateParameter);
        std::vector<std::string> vecRequest;
        int nRetSplit = string_split(vecRequest, url, "?");

        std::string para = vecRequest[1];
        size_t pos = para.find("para");
        std::string result = para.substr(pos+4);
        return result;
	}
};

}//namespace util
}//namespace arris