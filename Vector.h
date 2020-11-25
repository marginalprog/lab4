#pragma once
#ifndef VEKTOR_H 
#define VEKTOR_H

#include <cassert>
#include <iostream>
#include <math.h>
#include <iostream>

class Vector {
private:
    int m_length;
    double* m_data;

public:

    // конструктор по умолчанию  
    Vector();

    // конструктор изменяющий длину Vector
    Vector(int length);

    // добавление элемента в конец
    void push_back(double value);

    // вывод первого элемента 
    void front();

    // сортировка
    void swap();

    // удаление элемента в конце Vector
    void pop_back();

    // очищение Vector
    void clear();

    // перезагрузка []
    double& operator[](int index);

    // вывод Vector
    friend std::ostream& operator<< (std::ostream& out, Vector& object);

    ~Vector();
};

#endif VEKTOR_H