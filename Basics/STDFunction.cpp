#include <iostream>
#include <functional>

int operateTwoNumbers(int a, int b, const std::function<int(int, int)> &operation)
{
    return operation(a, b);
}

int main()
{
    int num1 = 5, num2 = 6;
    auto add = [](int a, int b)
    {
        return a + b;
    };

    auto subtract = [](int a, int b)
    {
        return a - b;
    };

    auto multiply = [](int a, int b)
    {
        return a * b;
    };

    auto divide = [](int a, int b)
    {
        return a / b;
    };

    std::cout << "Addition : " << operateTwoNumbers(num1, num2, add) << "\n";
    std::cout << "Subtraction : " << operateTwoNumbers(num1, num2, subtract) << "\n";
    std::cout << "Multiplication : " << operateTwoNumbers(num1, num2, multiply) << "\n";
    std::cout << "Division : " << operateTwoNumbers(num1, num2, divide) << "\n";

    return 0;
}
