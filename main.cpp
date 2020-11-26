// Лабораторная работа №4 <24.11.2020; 19:09>

#include "Vector.h"

int main() {
    Vector vector(5);
    std::cout << vector;
    vector.insert(7.3);
    std::cout << vector;
    vector.erase(2);
    std::cout << vector;
    return(0);

}
class Vector {
private:
	int length;
	int* vector;
	int b;

public:
	Vector() {
		std::cout << "Введите длину вектора" << std::endl;
		std::cin >> length;
		if (length == 0)
			empty();
		else {
			std::cout << "Введите элементы вектора:" << std::endl;
			vector = new int[length];
			for (int i = 0; i < length; i++) {
				std::cin >> vector[i];
			}
		}
	}
	void resize(int n, int value) {
		if (length > n) {
			length = n;
			std::cout << "Новый вектор:" << std::endl;
			for (int i = 0; i < length; i++) {
				std::cout << vector[i] << " ";
			}
			for (int i = n; i < length; i++) {
				delete[i] vector;
			}
		}
		else {
			b = length;
			length = n;
			std::cout << "Новый вектор:" << std::endl;
			for (int i = 0; i < b; i++) {
				std::cout << vector[i] << " ";
			}
			for (int i = b + 1; i < length + 1; i++) {
				vector = new int[i];
			}
			for (int i = b + 1; i < length + 1; i++) {
				vector[i] = value;
				std::cout << vector[i] << " ";
			}
		}
	}
	void back() {
		std::cout << "Содержимое последней ячейки вектора = " << vector[length];
	}
	void size() {
		std::cout << std::endl << "Размерность текущего вектора = " << length << std::endl;
	}
	void empty() {
		if (length == 0)
			std::cout << "Вектор Геннадиевич пустой" << std::endl;
		else
			std::cout << "Всё путем, идем дальше" << std::endl;
	}
	~Vector() {
		delete[] vector;
	}

};