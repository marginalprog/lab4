#include "Vector.h"

Vector::Vector() : m_length(0), m_data(nullptr) {};

Vector::Vector(int length) : m_length(length) {
    assert(length >= 0);
    if (length > 0) {
        m_data = new double[length];
        for (int i = 0; i < length; i++)
            m_data[i] = 0;
    }
    else
        m_data = nullptr;
}

void Vector::push_back(double value) {
    double* data = new double[m_length + 1];

    for (int i = 0; i < m_length; i++)
        data[i] = m_data[i];

    data[m_length] = value;

    m_data = data;

    m_length++;
    delete[] data;
}

void Vector::front() {
    std::cout << m_data[0] << std::endl;
}

double& Vector::operator[](int index) {
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

void Vector::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

void Vector::pop_back() {
    double* data = new double[m_length - 1];

    for (int i = 0; i < m_length; i++)
        data[i] = m_data[i];

    m_data = data;

    delete[] data;
}

void Vector::swap() {
    double max;
    int position;
    for (int i = 0; i < m_length - 1; i++) {
        max = m_data[0];
        position = 0;
        for (int j = 1; j < m_length - i; j++) {
            if (m_data[j] > max) {
                max = m_data[j];
                position = j;
            }
        }
        m_data[position] = m_data[0];
        m_data[0] = m_data[m_length - 1];
        m_data[m_length - 1] = max;
    }
}

Vector::~Vector() {
    delete[] m_data;
}