#pragma once

#include <arris/wechat/base.hpp>
#include <arris/util/log_util.hpp>

using namespace arris::wechat;
using namespace arris::util;

namespace arris {
namespace objectmgr {
	template<typename T>
	class mgr {
	public:
		mgr() {}
		~mgr() {
			typename std::unordered_map<int, T*>::iterator  iter = obj_map_.begin();
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
		}
		std::string run(const int type, const wx_msg& st_msg) {
			if (exist(type) == false) {
				return "null";
			}
			try {
				return obj_map_[type]->handle_msg(st_msg);
			}
			catch (...) {
				__OutputDebugString(TEXT("type no error:%d\n"), type);
				return "execption";
			}
		}
		void add(int type, T* p) {
			obj_map_.insert(std::make_pair(type, p));
		}
	private:
		bool exist(int type) {
			bool is_exist = true;
			size_t n = obj_map_.count(type);

			if (n == 0) {
				is_exist = false;
			}
			return is_exist;
		}

	private:
		std::unordered_map<int, T*> obj_map_;
	};//class mgr
}//namespace mgr
}//namespace arris