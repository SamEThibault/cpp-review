#include <iostream>

// Template function
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// Template class
template <typename T>
class Pair
{
private:
    T first;
    T second;

public:
    Pair(T a, T b)
    {
        first = a;
        second = b;
    }

    // TO DO: implement getFirst() and getSecond()
};

int main()
{
    // Template function example
    std::cout << "Sum of integers: " << add(5, 3) << std::endl;
    std::cout << "Sum of doubles: " << add(3.5, 2.5) << std::endl;

    // Template class example
    Pair<int> pair1(10, 20);
    Pair<double> pair2(3.14, 6.28);

    // std::cout << "Pair 1: " << pair1.getFirst() << ", " << pair1.getSecond() << std::endl;
    // std::cout << "Pair 2: " << pair2.getFirst() << ", " << pair2.getSecond() << std::endl;

    return 0;
}