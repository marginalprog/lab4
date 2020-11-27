// Лабораторная работа №4 <24.11.2020; 19:09>

#include "Vector.h"

int main() {
    Vector vector(30);
    std::cout << vector;
    //vector.insert(7.3);
    //std::cout << vector;
    // vector.erase(2);
    //std::cout << vector;
    //vector.insert(4, 3, 6);
    //std::cout << vector;

    //vector.resize(7);
    //std::cout << vector;
    vector.swap();
    std::cout << vector;
    return(0);

}
