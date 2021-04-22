#pragma once

#include <string>
#include <memory>
#include <functional>
#include <arris/wechat/constant.hpp>
#include <arris/thread/wxthread.hpp>

using namespace arris::thread;
using arris::wechat::kMsgQueue;
namespace arris {
	namespace wechat {

		class msgdispatch final{
		public:
			msgdispatch() = default;
			~msgdispatch() = default;

			void send_to_queue(const std::string& msg) {
				auto p = thread_pool.enqueue(std::bind(&msgdispatch::push, this, msg));
			}
		private:
			void push(const std::string& msg) {
				kMsgQueue.push(msg);
			}

		};//class msgtoqueue

		using msgdispatch_ptr = std::unique_ptr<msgdispatch>;
	}//namespace wechat
}//namespace arris