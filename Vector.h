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

    // ��������� ������� �������� �������
    void back();

    // �������� Vector
    void clear();

    // ������� ������� �������
    void erase(int index);

    // �������� ������� �� �������
    void empty();

    // ����� ������� �������� 
    void front();

    // ��������� ������� � ������ �������
    void insert(double value);

    // ��������� n ���������, ������� � it, �� ����. value
    void insert(int it, int n, double value);

    // �������� �������� � ����� Vector
    void pop_back();

    // ���������� �������� � �����
    void push_back(double value);

    // ��������� �������� �������
    void resize(int n,const double value = rand()% 9 + 0);

    // ����������
    void swap();

    // ����������� �������� �������
    int size();

    // ���������� []
    double& operator[](int index);

    // ����� Vector
    friend std::ostream& operator<< (std::ostream& out, Vector& object);

    ~Vector();

private:

    // ���������� ���� 
    void heap(int length);

};

#endif VEKTOR_H