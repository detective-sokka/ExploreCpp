#include <iostream>

struct ComplexNumber {
    int base;
    int complex;

    ComplexNumber(int base, int complex) : base{base},
                                           complex{complex} {
        std::cout << "\nParam constructor called.";
    }

    ComplexNumber(const ComplexNumber &number) : base{number.base}, 
                                                 complex{number.complex} {
        std::cout << "\nParam constructor called.";
    }

    ComplexNumber(ComplexNumber &&number) noexcept : base{std::move(number.base)},
                                                     complex{std::move(number.complex)} {
        std::cout << "\nMove constructor called.";
    }    

    ComplexNumber& operator = (const ComplexNumber &number) {        
        std::cout << "\nCopy assignment operator called.";
        
        if (this != &number) {
            this->base = number.base;    
            this->complex = number.complex;            
        }

        return *this;        
    }
    
    ComplexNumber& operator = (ComplexNumber &&number) {
        std::cout << "\nMove assignment operator called."; 
        
        if (this != &number) {
            this->base = number.base;
            this->complex = number.complex;
        }

        return *this;
    }

    ~ComplexNumber() {        
        std::cout << "Destructor called.";
    }
};