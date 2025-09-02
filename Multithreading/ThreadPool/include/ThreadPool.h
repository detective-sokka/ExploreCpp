#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

/* 
Some cases to think about - 
1. What if the capacity is 0?
2. What if it is 1? 
3. What if all threads are busy? 
*/
class ThreadPool {

    public:
        explicit ThreadPool(size_t capacity) : m_stop{false},
                                               m_capacity{capacity} {

            if (capacity == 0)
                throw invalid_argument("Pool size should be atleast 1.");

            for (size_t i=0; i < capacity; i++) {
                m_threads.emplace_back(thread([this] () {
                    while (true) {
                        std::unique_lock<mutex> lock(m_mtx);
                        m_cv.wait(lock, [this]{ return !m_tasks.empty() || m_stop; });

                        if (m_stop && m_tasks.empty()) 
                            return;

                        auto task = std::move(m_tasks.front());
                        m_tasks.pop();                        
                        lock.unlock();
                        
                        try {
                            task();
                        } 
                        catch(const exception &e) {
                            cout << "\n" << e.what();
                        }
                    }
                }));
            }
        }

        ThreadPool (const ThreadPool& ) = delete;
        ThreadPool (ThreadPool&& ) = delete;
        ThreadPool& operator=(const ThreadPool& ) = delete;
        ThreadPool& operator=(ThreadPool && ) = delete;

        ~ThreadPool() {
            {
                lock_guard<mutex> lock(m_mtx);
                m_stop = true;
            }
            m_cv.notify_all();

            for (auto &thread : m_threads)
                thread.join();
        }
        
        void executeTask (function<void()> task) {
            
            if (m_capacity == 0) 
                return;

            unique_lock<mutex> lock(m_mtx);
            
            if (m_stop) return;
                
            m_tasks.push(task);
            lock.unlock();
            m_cv.notify_one();
        }

    private:
        vector<thread> m_threads;
        queue<function<void()>> m_tasks;
        mutex m_mtx;        
        condition_variable m_cv;
        size_t m_capacity;
        bool m_stop;
};