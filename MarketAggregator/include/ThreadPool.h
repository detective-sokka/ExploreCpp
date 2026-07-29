
#pragma once

#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>


namespace custom 
{
namespace threading
{
class ThreadPool 
{        
public:
    ~ThreadPool();
    void enqueue(std::function<void()> task);

private:
    friend class ThreadPoolBuilder;
    explicit ThreadPool(size_t numberOfThreads);

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&) = delete;
    
    ThreadPool& operator=(const ThreadPool&) = delete;        
    ThreadPool& operator=(ThreadPool&&) = delete;

    std::vector<std::thread> mThreads;
    std::queue<std::function<void()>> mTasks;
    size_t mThreadCount;
    std::mutex mMutex;
    std::condition_variable mCondition;
    bool mShutdown = false;
};

class ThreadPoolBuilder 
{
public:
    ThreadPoolBuilder();
    ~ThreadPoolBuilder();

    ThreadPoolBuilder& setThreadCount(size_t threadCount);

    std::unique_ptr<ThreadPool> build();

    private:
    ThreadPoolBuilder(const ThreadPoolBuilder&) = delete;
    void operator=(const ThreadPoolBuilder&) = delete;

    ThreadPoolBuilder(ThreadPoolBuilder&&) = delete;
    void operator=(ThreadPoolBuilder&&) = delete;

    size_t mThreadCount{1};
};
}
}
