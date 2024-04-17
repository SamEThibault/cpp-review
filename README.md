# Object-oriented C++ Review
Review for college-level C++ Curriculum

## Dynamic Memory Management
Dynamic memory management in C++ refers to the allocation and deallocation of memory during program execution. Unlike static memory allocation, where memory is allocated at compile time, dynamic memory allocation allows memory to be allocated at runtime using pointers.

```cpp
#include <iostream>

int main() {
    // Dynamic memory allocation for an integer
    int* ptr = new int;
    
    // Assigning a value
    *ptr = 10;
    
    std::cout << "Value stored at dynamically allocated memory: " << *ptr << std::endl;
    
    // Freeing memory
    delete ptr;
    
    return 0;
}

```

## Shallow and Deep Copies
Shallow and deep copies are concepts related to copying objects in C++. Shallow copy creates a new object and copies the values of all data members to the new object. If the data members include pointers, the addresses they point to are copied, not the data itself. Deep copy, on the other hand, creates a new object and copies not only the values of data members but also allocates new memory and copies the contents pointed to by pointers.
```cpp
#include <iostream>

class DeepCopyExample {
private:
    int* data;
    int size;
public:
    // Constructor
    DeepCopyExample(int size) {
        this->size = size;
        data = new int[size];
    }
    
    // Copy constructor (deep copy)
    DeepCopyExample(const DeepCopyExample& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    
    // Destructor
    ~DeepCopyExample() {
        delete[] data;
    }
};

int main() {
    DeepCopyExample obj1(5);
    DeepCopyExample obj2 = obj1; // Perform deep copy
    
    return 0;
}
```

## Inheritance
Allows a class to inherit properties and behaviors from another class. The class that inherits is called a derived class, and the class it inherits from is called a base class. In C++, inheritance is achieved using the : symbol followed by the access specifier (public, protected, or private) and the name of the base class.
```cpp
#include <iostream>

// Base class
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {
    Shape* shape = new Rectangle();
    shape->draw(); // Calls the draw() function of Rectangle
    
    delete shape;
    
    return 0;
}
```

## Virtual Functions and Dynamic Dispatch
Virtual functions enable runtime polymorphism in C++. A virtual function is a member function declared within a base class that can be overridden by derived classes. Dynamic dispatch ensures that the appropriate function is called at runtime based on the actual object type rather than the pointer or reference type.
```cpp
#include <iostream>

// Base class
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Animal sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound(); // Calls the makeSound() of Dog due to dynamic dispatch
    
    delete animal;
    
    return 0;
}
```

## Abstract Classes and Pure Virtual Functions
Abstract classes in C++ are classes that contain one or more pure virtual functions. A pure virtual function is a virtual function that has no definition in the base class and must be overridden by derived classes. Abstract classes cannot be instantiated; they serve as interfaces for derived classes to implement. 
```cpp
#include <iostream>

// Abstract base class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw(); // Calls the draw() function of Circle
    
    delete shape;
    
    return 0;
}
```

## Polymorphism
Polymorphism is the ability of objects to take on multiple forms. In C++, polymorphism is achieved through inheritance and virtual functions. Using inheritance, we can achieve polymorphic behaviors to allow objects of different classes to be treated as objects of a common base class during runtime. Using virtual functions, we can bind function calls to their definitions at runtime.
```cpp
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
    
    dog->makeSound(); // Calls the makeSound() of Dog
    cat->makeSound(); // Calls the makeSound() of Cat
    
    delete dog;
    delete cat;
    
    return 0;
}
```

## Template Functions and Template Classes
They allow for the creation of generic functions and classes that can work with any data type. Template functions and classes are defined with one or more template parameters, which are replaced with actual types or values when the function or class is used.
```cpp
#include <iostream>

// Template function
template<typename T>
T add(T a, T b) {
    return a + b;
}

// Template class
template<typename T>
class Pair {
private:
    T first;
    T second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    
    T getFirst() const {
        return first;
    }
    
    T getSecond() const {
        return second;
    }
};

int main() {
    // Template function example
    std::cout << "Sum of integers: " << add(5, 3) << std::endl;
    std::cout << "Sum of doubles: " << add(3.5, 2.5) << std::endl;
    
    // Template class example
    Pair<int> pair1(10, 20);
    Pair<double> pair2(3.14, 6.28);
    
    std::cout << "Pair 1: " << pair1.getFirst() << ", " << pair1.getSecond() << std::endl;
    std::cout << "Pair 2: " << pair2.getFirst() << ", " << pair2.getSecond() << std::endl;
    
    return 0;
}
```
