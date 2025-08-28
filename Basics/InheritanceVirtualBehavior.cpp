#include <iostream>

class Base {
    void method() {
      std::cout << "from Base" << std::endl;
    }
public:
    Base() {
      std::cout << "Base constructor" << std::endl;
      method();
    }
    virtual ~Base() {
      std::cout << "Base destructor" << std::endl;
      method();
    }
    void baseMethod() {
      std::cout << "baseMethod" << std::endl;
      method();
    }
};

class A : public Base {
    void method() {
      std::cout << "from A" << std::endl;
    }
public:
  	A() {
      std::cout << "A constructor" << std::endl;
      method();
    }
    ~A() {
      std::cout << "A destructor" << std::endl;
      method();
    }
};

int main(void) {
    Base* base = new A;
    base->baseMethod();
    delete base;
    return 0;
}

