#include <iostream>
#include <thread>

using namespace std;

class SpinLock {
    public:
        void lock() {          
            while (locked.exchange(true)) {                
            }
        }

        void unlock() {
            locked.store(false);
        }

    private:
        atomic<bool> locked{false};
};

void increment (SpinLock &s, int64_t &val) {
    for (int i=0; i < 100000; ++i) {
        s.lock();
        ++val;
        cout << val << " ";
        s.unlock();
    }
}

int main() {
    SpinLock s;
    int64_t counter = 0;
    
    vector<thread> thread_vector;
    for (int i = 0; i < 2; i++) 
        thread_vector.emplace_back(increment, ref(s), ref(counter));

    for (auto &t : thread_vector) 
        t.join();
        
    return 0;
}