#pragma once
#ifndef VEKTOR_H 
#define VEKTOR_H

#include <cassert>
#include <iostream>
#include <math.h>

class Vektor {
private:
    int m_length;
    double* m_data;

    Vektor();

    Vektor(int length);

    void push_back(double value);

    void front();

    double& operator[](int index);

    ~Vektor();
};

#endif VEKTOR_H