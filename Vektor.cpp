#include "Vektor.h"

Vektor::Vektor() : m_length(0), m_data(nullptr) {};

Vektor::Vektor(int length) : m_length(length) {
    assert(length >= 0);
    if (length > 0) {
        m_data = new double[length];
        for (int i = 0; i < length; i++)
            m_data[i] = 0;
    }
    else
        m_data = nullptr;
}

void Vektor::push_back(double value) {
    double* data = new double[m_length + 1];

    for (int i = 0; i < m_length; i++)
        data[i] = m_data[i];

    data[m_length] = value;

    m_data = data;

    delete[] data;
}

void Vektor::front() {
    std::cout << m_data[0] << std::endl;
}

double& Vektor::operator[](int index) {
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

Vektor::~Vektor() {
    delete[] m_data;
}