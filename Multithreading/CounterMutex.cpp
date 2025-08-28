/*
This is code to demostrate mutex thread safety in C++.
Problem - Print 1 to 100 in order.
 */

#include <iostream>
#include <mutex>
#include<thread>

int main()
{
    int counter=1;

    std::mutex mutex;

    auto increment = [&counter, &mutex]()
    {
        std::lock_guard<std::mutex> lock{mutex};
        for (int i=0; i < 50; i++)
        {            
            std::cout << counter++ << " ";
        }
            
    };

    std::thread count1{increment};
    std::thread count2{increment};

    count1.join();
    count2.join();

    return 0;
}