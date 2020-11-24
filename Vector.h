#pragma once
#ifndef VEKTOR_H 
#define VEKTOR_H

#include <cassert>
#include <iostream>
#include <math.h>

class Vector {
private:
    int m_length;
    double* m_data;

public:

    // конструктор по умолчанию  
    Vector();

    // конструктор изменяющий длину Vector
    Vector(int length);

    void push_back(double value);

    void front();

    void swap();

    void pop_back();

    void clear();

    double& operator[](int index);

    ~Vector();
};

#endif VEKTOR_H