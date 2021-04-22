#pragma once

#include <memory>
#include <unordered_map>
namespace arris {
	namespace objectmgr {

		template<typename OBJ, typename PARA, typename RESULT>
		//OBJ=object PARA=parameter RESULT = return value
		class mgr final {
		public:
			mgr() = default;
			~mgr() = default;

			RESULT run(const int type) {
				if (exist(type) == false) {
					return "not exist";
				}
				try {
					return obj_map_[type]->message();
				}
				catch (...) {
					return "execption";
				}
			}
			RESULT run(const int type, const PARA& st_msg) {
				if (exist(type) == false) {
					return "not exist";
				}
				try {
					return obj_map_[type]->handle_msg(st_msg);
				}
				catch (...) {
					return "execption";
				}
			}
			void add(int type, std::unique_ptr<OBJ> p) {
				obj_map_.insert(std::make_pair(type, std::move(p)));
				
				__OutputDebugString(TEXT("type %d obj_map insert %d"), type,obj_map_.size());
				
			}
			//void add(int type,OBJ* p) {
			//	obj_map_.insert(std::make_pair(type,p));
			//}
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
			std::unordered_map<int, std::unique_ptr<OBJ>> obj_map_;
			//std::unordered_map<int, OBJ*> obj_map_new_;
		};//class mgr

	}//namespace objectmgr
}//namespace arris