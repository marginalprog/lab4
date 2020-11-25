#include "Vector.h"

Vector::Vector() : m_length(0), m_data(nullptr) {};

Vector::Vector(int length) : m_length(length) {
    assert(m_length >= 0);
    if (m_length > 0) {
        m_data = new double[m_length];
        for (int i = 0; i < m_length; i++)
            m_data[i] = rand() % 9 +0;
    }
    else
        m_data = nullptr;
}

void Vector::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

void Vector::erase(int index) {
    m_length--;
    double* data = new double[m_length];

    for (int i = 0; i < index; i++) {
        data[i] = m_data[i];
    }

    for (int i = index ; i < m_length; i++)
        data[i] = m_data[i + 1];

    delete[] m_data;
    m_data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        m_data[i] = data[i];   

    delete[] data;
}

void Vector::front() {
    std::cout << m_data[0] << std::endl;
}

void Vector::insert(double value) {
    m_length++;
    double* data = new double[m_length];

    for (int i = 0; i < m_length - 1; i++)
        data[i + 1] = m_data[i];

    data[0] = value;

    delete[] m_data;
    m_data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        m_data[i] = data[i];

    delete[] data;
}

void Vector::pop_back() {
    m_length--;
    double* data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        data[i] = m_data[i];

    delete[] m_data;
    m_data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        m_data[i] = data[i];

    delete[] data;
}

void Vector::push_back(double value) {
    m_length++;
    double* data = new double[m_length];

    for (int i = 0; i < m_length - 1; i++)
        data[i] = m_data[i];

    data[m_length - 1] = value;

    delete[] m_data;
    m_data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        m_data[i] = data[i];

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
        m_data[0] = m_data[m_length - i - 1];
        m_data[m_length - i - 1] = max;
    }
}

double& Vector::operator[](int index) {
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

std::ostream& operator<< (std::ostream& out, Vector& object) {
    for (int i = 0; i < object.m_length; i++)
        out << object.m_data[i] << " ";
    out << "\n";
    return out;
}

Vector::~Vector() {
    delete[] m_data;
}