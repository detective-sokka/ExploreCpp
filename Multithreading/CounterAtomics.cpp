#include <atomic>
#include <iostream>
#include <string>
#include <thread>

using std::atomic;
using std::cout;
using std::string;
using std::thread;

int main() {
    atomic<int> counter(0);
    constexpr int maxCount = 50;
    auto incrementAndDisplay = [&counter, &maxCount] (string threadId) {
        int value = counter.fetch_add(1);
        while (value <= maxCount) {
            cout << "\n" << threadId << " - " << counter ;
        }
    };

    thread t1(incrementAndDisplay, "Thread A");
    thread t2(incrementAndDisplay, "Thread B");

    t1.join();
    t2.join();

    return 0;
}