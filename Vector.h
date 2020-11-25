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

    // ����������� �� ���������  
    Vector();

    // ����������� ���������� ����� Vector
    Vector(int length);

    // �������� Vector
    void clear();

    // ������� ������� �������
    void erase(int index);

    // ����� ������� �������� 
    void front();

    // ��������� ������� � ������ �������
    void insert(double value);

    // �������� �������� � ����� Vector
    void pop_back();

    // ���������� �������� � �����
    void push_back(double value);

    // ����������
    void swap();

    // ���������� []
    double& operator[](int index);

    // ����� Vector
    friend std::ostream& operator<< (std::ostream& out, Vector& object);

    ~Vector();
};

#endif VEKTOR_H