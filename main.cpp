// Лабораторная работа №4 <24.11.2020; 19:09>

#include "Vector.h"
#include <ctime>

int main() {
    setlocale(LC_ALL, "");

    Vector vector(10);
    std::cout << "Начальный массив: " << vector << "\n";

    {
        double start = clock();
        std::cout << "Работа метода сортировки swap():" << std::endl;
        vector.swap();
        std::cout << vector;
        int end = clock();
        double t = (end - start) / CLOCKS_PER_SEC;
        std::cout << "Время: " << t << "\n\n";
    }

    {
        std::cout << "Работа метода удаления одного элемента erase():" << std::endl;
        vector.erase(1);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода вывода последнего элемента back():" << std::endl;
        std::cout << vector.back() << "\n\n";
    }

    {
        std::cout << "Работа метода вывода первого элемента front():" << std::endl;
        std::cout << vector.front() << "\n\n";
    }
    
    {
        std::cout << "Работа метода добавления элемента в начало вектора insert():" << std::endl;
        vector.insert(6);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода добавления элементов, начиная с определенной позиции insert(it,n,value):" << std::endl;
        vector.insert(5, 6, 7);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода удаления последнего элемента pop_back():" << std::endl;
        vector.pop_back();
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода добавления элемента в конец вектора push_back():" << std::endl;
        vector.push_back(9);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода определение пустоты контейнера empty():" << std::endl;
        if (vector.empty())
            std::cout << "Контейнер пустой!" << "\n\n";
        else
            std::cout << "Контейнер полный!" << "\n\n";
    }

    {
        std::cout << "Работа метода по изменению размерности вектора resize(n):" << std::endl;
        vector.resize(10);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода по изменению размерности вектора resize(n, value):" << std::endl;
        vector.resize(35, 1);
        std::cout << vector << "\n";
    }

    {
        std::cout << "Работа метода очистки clear():" << std::endl;
        vector.clear();
        if (vector.empty())
            std::cout << "Контейнер пустой!" << "\n";
        else
            std::cout << "Контейнер полный!" << "\n";
    }

    return(0);
}
