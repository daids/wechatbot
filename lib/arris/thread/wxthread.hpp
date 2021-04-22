#pragma once

#include <ThreadPool/ThreadPool.h>

namespace arris {
namespace thread{

const int kThreadPoolNum = 100;
ThreadPool thread_pool(kThreadPoolNum);

}//namespace thread
}//namespace arris