#include <iostream>
#include <thread>

#include "include/ThreadPool.h"

int main() {
    using namespace custom::threading;
    
    std::unique_ptr<ThreadPool> threadPool;

    try 
    {
        threadPool = ThreadPoolBuilder()
            .setThreadCount(10)
            .build();
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}