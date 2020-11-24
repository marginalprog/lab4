
#include <math.h>
#include <iostream>

class vektor {
private:
    int length;
    double* data;
public:
    vektor() :length(0), data(nullptr) {};

    vektor(int leng) :
        length(leng)
    {
        if (leng > 0) {
            data = new double[leng];
            for (int i = 0; i < leng; i++)
                data[i]=0;
        }
        else
            data = nullptr;
    }

    void push_back(double push) {
        int newlen = length + 1;
        double* newdata = new double[newlen];

        for (int i = 0; i < length; i++)
            newdata[i] = data[i];

        delete[] data;
        data = new double[newlen];

        for (int i = 0; i < length; i++)
            data[i] = newdata[i];
        data[length] = push;  

        delete[] newdata;
    }

    void front() { std::cout << data[0] << std::endl; }

    void get(int x) {
        for (int i = 0; i < length+x; i++)
            data[i] = i + 1;
        for (int i = 0; i < length+x; i++)
            std::cout << data[i] << " ";
    }

    ~vektor() {
        delete[] data;
    }
};

int main()
{
    vektor line(5);
    line.get(0);
    std::cout << std::endl;
    line.front();
    line.push_back(5);
    line.get(1);
    std::cout << std::endl;
    return(0);
    // ХУЙ
}