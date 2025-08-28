#include <iostream>

class Tuna
{
    int smelliness;

    public:
        Tuna(int inputSmelliness) : smelliness{inputSmelliness}
        {   
            std::cout << "Constructor is called\n";         
        }

        Tuna(const Tuna &operand)
        {
            std::cout << "Copy Constructor is called\n";
            this->smelliness = operand.smelliness;
        }

        Tuna& operator=(const Tuna &operand)
        {
            std::cout << "Assignment operator is called\n";
            this->smelliness = operand.smelliness;
            return *this;
        }

        int getSmelliness()
        {
            return this->smelliness;
        }
};


int main()
{
    Tuna canned{10};
    Tuna newCanned{canned};
    Tuna random{4};
    random = canned;

    std::cout << newCanned.getSmelliness() << std::endl;   
    std::cout << random.getSmelliness();
}