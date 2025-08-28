#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;

void sleep_for_two_seconds() {
    this_thread::sleep_for(chrono::seconds(2));
    {
        lock_guard<mutex> lock(mtx);
        cout << "\nThread : " << this_thread::get_id() << " is sleeping for 2 seconds.";
    }
}

int main() {
    vector<thread> sleepy_threads;
    for (int i = 0; i < 5; i++)
        sleepy_threads.push_back(thread(sleep_for_two_seconds));

    for (auto &t : sleepy_threads) 
        t.join();

    return 0;
}