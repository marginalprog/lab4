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

    // очищение Vector
    void clear();

    // удаляет элемент вектора
    void erase(int index);

    // вывод первого элемента 
    void front();

    // добавляет элемент в начало вектора
    void insert(double value);

    // удаление элемента в конце Vector
    void pop_back();

    // добавление элемента в конец
    void push_back(double value);

    // сортировка
    void swap();

    void resize(int n, int value);

    void back();

    int size();

    bool empty();

    // перегрузка []
    double& operator[](int index);

    // вывод Vector
    friend std::ostream& operator<< (std::ostream& out, Vector& object);

    ~Vector();
};

#endif VEKTOR_H