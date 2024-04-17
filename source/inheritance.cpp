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
    // TO DO: override the draw class
};

int main() {
    Shape* shape = new Rectangle();
    shape->draw(); // Calls the draw() function of Rectangle
    
    delete shape;
    
    return 0;
}