#pragma once
#ifndef VEKTOR_H 
#define VEKTOR_H

#include <cassert>
#include <iostream>
#include <math.h>
#include <iostream>

class Vector {
private:
    int m_length, count, countif;
    double* m_data;

public:

    // ����������� �� ���������  
    Vector();

    // ����������� ���������� ����� Vector
    Vector(int length);

    // ��������� ������� �������� �������
    double back();

    // �������� Vector
    void clear();

    // ������� ������� �������
    void erase(int index);

    // �������� ������� �� �������
    bool empty();

    // ����� ������� �������� 
    double front();

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

    // ����������� �������� �������
    int size();

    // ����������
    void swap();

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