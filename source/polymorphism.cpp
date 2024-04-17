#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal sound" << std::endl;
    }
};

// Derived classes
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
    dog->makeSound();
    cat->makeSound(); 
    
    delete dog;
    delete cat;
    
    return 0;
}