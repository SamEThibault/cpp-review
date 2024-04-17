#include <iostream>

// Abstract base class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class
class Circle : public Shape {
public:
    // TO DO: implement draw() for circle
};

int main() {
    Shape* shape = new Circle();
    shape->draw();
    
    delete shape;
    
    return 0;
}