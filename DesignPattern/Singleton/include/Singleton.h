#pragma once

class Singleton final
{
public:    
    ~Singleton() = default;
    
    Singleton(Singleton&) = delete;
    Singleton(const Singleton&) = delete; // while strictly not necessary, gives a more accurate compiler error

    Singleton& operator=(Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete; // same

    Singleton(Singleton&&) = delete; // Move deletion is necessary as otherwise it leaves instance in a valid but unspecified state
    Singleton& operator=(Singleton&&) = delete;

    static Singleton& instance() 
    {
        static Singleton instance;
        return instance;
    }
private:
    Singleton() = default;

};