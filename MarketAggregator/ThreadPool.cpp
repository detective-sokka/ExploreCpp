#include <functional>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>

#include "include/ThreadPool.h"

using namespace custom::threading;

ThreadPoolBuilder::ThreadPoolBuilder() = default;
ThreadPoolBuilder::~ThreadPoolBuilder() = default;

ThreadPoolBuilder &ThreadPoolBuilder::setThreadCount(size_t numberOfThreads)
{
    if (numberOfThreads == 0 || numberOfThreads > 100)
    {
        throw std::invalid_argument("Number of threads must be between 1 and 100");
    }

    mThreadCount = numberOfThreads;
    return *this;
}

std::unique_ptr<ThreadPool> ThreadPoolBuilder::build()
{
    std::unique_ptr<ThreadPool> threadPool{new ThreadPool(mThreadCount)};
    return threadPool;
}

ThreadPool::ThreadPool(size_t numberOfThreads) : mThreadCount{numberOfThreads}
{
    auto executeTask = [this]()
    {
        while (true)
        {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(this->mMutex);
                this->mCondition.wait(lock, [this]() -> bool
                                      { return this->mShutdown || !this->mTasks.empty(); });

                if (this->mShutdown && this->mTasks.empty())
                {
                    return;
                }

                task = std::move(this->mTasks.front());
                this->mTasks.pop();
            }
            try
            {
                task();
            }
            catch (std::exception &e)
            {
                std::cerr << "Exception : " << e.what();
            }
            catch (...)
            {
                std::cerr << "Exception";
            }
        }
    };

    try
    {
        for (size_t i = 0; i < mThreadCount; i++)
        {
            mThreads.emplace_back(executeTask);
        }
    }
    catch (...)
    {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mShutdown = true;
            mCondition.notify_all();
        }
        for (auto &t : mThreads)
        {
            if (t.joinable())
            {
                t.join();
            }
        }
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mShutdown = true;
        mCondition.notify_all();
    }
    for (auto &t : mThreads)
    {
        t.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mTasks.push(std::move(task));
        mCondition.notify_one();
    }
}