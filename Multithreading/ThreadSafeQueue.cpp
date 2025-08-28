#include <condition_variable>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <thread>

template <typename T>
class ThreadSafeQueue {

    public:
    ThreadSafeQueue() = default;
    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    void push(T data) {

        {
            std::unique_lock<std::mutex> lock(mMutex);
            mData.push_back(data);
        }

        mConditionVar.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mMutex);
        mConditionVar.wait(lock, [this]() {return !mData.empty() || !mRunning;});
        T data = mData.front();
        mData.pop_front();
        return data;
    }

    size_t size() const {
        std::unique_lock<std::mutex> lock(mMutex);
        return mData.size();
    }

    bool empty() const {
        std::unique_lock<std::mutex> lock(mMutex);
        return mData.empty();
    }

    void shutdown() {
        {
            std::lock_guard<std::mutex> lock(mutex);
            mRunning = false; 
        }
        mConditionVar.notify_all();
    }

    private:    
        std::mutex mMutex;
        std::condition_variable mConditionVar;
        std::list<T> mData;
        bool mRunning{true};
};


int main() {
    ThreadSafeQueue<std::string> queue;
    const std::vector<std::string> data = {"first", "second", "third", "forth", "fifth"};
    
    std::thread write_thread([&queue, &data]() {
        for (auto &e : data) 
            queue.push(e);
    });        


    std::thread read_and_delete_thread([&queue](size_t count) {
        for (size_t i=0; i < count; i++) 
            std::cout << queue.pop() << "\n";             
    }, data.size());

    write_thread.join();
    read_and_delete_thread.join();

    return 0;    
}

