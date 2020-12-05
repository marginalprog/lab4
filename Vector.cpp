#include "Vector.h"

Vector::Vector() : m_length(0), m_data(nullptr), count(0), countif(0) {};

Vector::Vector(int length) : m_length(length) {
    assert(m_length >= 0);
    if (m_length > 0) {
        m_data = new double[m_length];
        for (int i = 0; i < m_length; i++)
            m_data[i] = rand() % 1000 +0;
    }
    else
        m_data = nullptr;
}

double Vector::back() {
    return m_data[m_length - 1];
}

void Vector::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

bool Vector::empty() {
    if (m_length == 0)
        return true;
    else
        return false;
}

void Vector::erase(int index) {
    assert(index >= 0 && index <= m_length);
    m_length--;
    double* data = new double[m_length];

    for (int i = 0; i < index; i++)
        data[i] = m_data[i];

    for (int i = index; i < m_length; i++)
        data[i] = m_data[i + 1];

    delete[] m_data;
    m_data = new double[m_length];

    for (int i = 0; i < m_length; i++)
        m_data[i] = data[i];   

    delete[] data;
}

double Vector::front() {
    return m_data[0];
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

void Vector::insert(int it, int n, double value) {
    assert(it >= 0 && it <= m_length);
    m_length+=n;
    double* data = new double[m_length];

    for (int i = 0; i < it; i++) 
        data[i] = m_data[i];

    for (int i = it; i < it + n; i++)
        data[i] = value;

    for (int i = it+n; i < m_length; i++)
        data[i] = m_data[i-n];

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

void Vector::resize(int n, const double value) {
    if (m_length > n) {
        m_length = n;
        double* data = new double[m_length];

        for (int i = 0; i < m_length; i++) {
            data[i] = m_data[i];
        }

        delete[] m_data;
        m_data = new double[m_length];

        for (int i = 0; i < m_length; i++) {
            m_data[i] = data[i];
        }

        delete[] data;
    }
    else {
        double* data = new double[n];

        for (int i = 0; i < m_length; i++) {
            data[i] = m_data[i];
        }

        for (int i = m_length; i < n; i++) {
            data[i] = value;
        }

        m_length = n;

        delete[] m_data;
        m_data = new double[m_length];

        for (int i = 0; i < m_length; i++) {
            m_data[i] = data[i];
        }

        delete[] data;
    }
}

int Vector::size() {
    return  m_length;
}

void Vector::swap() {
    double value;
    for (int i = 0; i < m_length - 1; i++) {
        heap(m_length - i);
        value = m_data[0];
        m_data[0] = m_data[m_length - i - 1];
        m_data[m_length - i - 1] = value;
    }
    std::cout << "Количство перестановок = " << count << std::endl;
    std::cout << "Количество сравнений = " << countif << std::endl;
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

void Vector::heap(int length) {
    double value;
    int position = 0;
    while (position * 2 + 2 <= length) {
        if (m_data[position] < m_data[position * 2 + 1] && position * 2 + 1 < length - 1) {
            value = m_data[position];
            m_data[position] = m_data[position * 2 + 1];
            m_data[position * 2 + 1] = value;
            position = 0;
            countif++;
        }
        if ((m_data[position] < m_data[position * 2 + 2]) && position * 2 + 1 < length - 1) {
            value = m_data[position];
            m_data[position] = m_data[position * 2 + 2];
            m_data[position * 2 + 2] = value;
            position = 0;
            countif++;
        }
        count++;
        position++;
    }
}