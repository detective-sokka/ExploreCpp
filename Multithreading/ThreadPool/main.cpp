#include <iostream>
#include <mutex>

#include "include/ThreadPool.h"

void thread_task() {
    static std::mutex mtx;
    this_thread::sleep_for(chrono::seconds(2));    
    std::lock_guard<mutex> lock(mtx);
    cout << "Running thread " << this_thread::get_id() << "\n";
}

void custom_task_milliseconds(const long long &time) {
    static std::mutex mtx;
    this_thread::sleep_for(chrono::milliseconds(time));    
    std::lock_guard<mutex> lock(mtx);
    cout << "Running thread " << this_thread::get_id() << "\n";
}

int custom_task_thread_id(const long long &time) {
    static std::mutex mtx;
    this_thread::sleep_for(chrono::milliseconds(time));    
    std::lock_guard<mutex> lock(mtx);
    cout << "Running thread " << this_thread::get_id() << "\n";
}

int main() {

    ThreadPool pool(8);    
    for (int i = 0; i < 100; ++i)       
        pool.executeTask(thread_task);
    
    return 0;
}
