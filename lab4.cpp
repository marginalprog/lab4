// Лабораторная работа №4 <24.11.2020; 19:09>

#include <math.h>
#include <iostream>
#include <cassert>

class vektor {
private:
    int m_length;
    double* m_data;

public:
    vektor() : m_length(0), m_data(nullptr) {};

    vektor(int length) : m_length(length) {
        assert(length >= 0);
        if (length > 0) {
            m_data = new double[length];
            for (int i = 0; i < length; i++)
                m_data[i]=0;
        }
        else
            m_data = nullptr;
    }

    void push_back(double value) {
        double* data = new double[m_length + 1];

        for (int i = 0; i < m_length; i++)
            data[i] = m_data[i];

        data[m_length] = value;

        m_data = data;

        delete[] data;
    }

    void front() { 
        std::cout << m_data[0] << std::endl; 
    }

    double& operator[](int index) {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    ~vektor() {
        delete[] m_data;
    }
};

int main() {
    
    return(0);
}