/*
This some basic code that demonstrates Exception handling in C++.
Problem statement: Write a function that divides two numbers and throws exception when divided by zero. 
*/

#include <exception>
#include <iostream>

int main()
{
    auto divideTwoIntegers = [](int divident, int divisor)
    {
        if(divisor == 0)
            throw std::runtime_error{"Invalid operation : Divide by Zero"};
        
        return divident/divisor;
    };

    try 
    {
        std::cout << divideTwoIntegers(10, 3) << std::endl;
        std::cout << divideTwoIntegers(10, 2) << std::endl;
        std::cout << divideTwoIntegers(10, 1) << std::endl;
        std::cout << divideTwoIntegers(3, 10) << std::endl;
        std::cout << divideTwoIntegers(3, 0)  << std::endl;
    } catch (const std::runtime_error &error)
    {
        std::cout << "Exception thrown : " << error.what();
    }
    
    return 0;
}