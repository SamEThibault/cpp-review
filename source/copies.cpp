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
        // TO DO: create copy constructor
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