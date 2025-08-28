#include <iostream>

using namespace std;

template <typename T>
class Vehicle {
    public: 
        void printNumberOfWheels() {
            cout << "\nThe number of wheels in this vehicle are : " << static_cast<T*>(this)->numberOfWheels();
        }
};

class Car : public Vehicle<Car> {
    public:
        size_t numberOfWheels() {
            return 4;
        }
};

class Bike : public Vehicle<Bike> {
    public:
        size_t numberOfWheels() {
            return 2;
        }
};

int main() {
    Car *vehicle1 = new Car();
    Bike *vehicle2 = new Bike();
    
    vehicle1->printNumberOfWheels(); 
    vehicle2->printNumberOfWheels(); 

    delete vehicle1;
    delete vehicle2;

    vehicle1 = nullptr;
    vehicle2 = nullptr;
    return 0;
}