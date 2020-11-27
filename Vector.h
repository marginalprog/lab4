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

    // последний элемент текущего вектора
    void back();

    // очищение Vector
    void clear();

    // удаляет элемент вектора
    void erase(int index);

    // проверка вектора на пустоту
    void empty();

    // вывод первого элемента 
    void front();

    // добавляет элемент в начало вектора
    void insert(double value);

    // добавляет n элементов, начиная с it, со знач. value
    void insert(int it, int n, double value);

    // удаление элемента в конце Vector
    void pop_back();

    // добавление элемента в конец
    void push_back(double value);

    // изменение размеров вектора
    void resize(int n,const double value = rand()% 9 + 0);

    // сортировка
    void swap();

    // размерность текущего вектора
    int size();

    // перегрузка []
    double& operator[](int index);

    // вывод Vector
    friend std::ostream& operator<< (std::ostream& out, Vector& object);

    ~Vector();

private:

    // сортировка кучи 
    void heap(int length);

};

#endif VEKTOR_H