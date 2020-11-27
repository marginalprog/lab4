// Лабораторная работа №4 <24.11.2020; 19:09>

#include "Vector.h"
#include <ctime>

int main() {
    double start = clock();
    Vector vector(300);
    std::cout << vector;
    vector.swap();
    std::cout << vector;
    int end = clock();
    double t = (end - start) / CLOCKS_PER_SEC;
    std::cout << " " << t;
    return(0);

}
