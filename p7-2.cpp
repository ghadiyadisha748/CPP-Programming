
#include <iostream>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    Complex operator-(Complex c2)
    {
        int result_real = real - c2.real;
        int result_img = img - c2.img;
        return Complex(result_real, result_img);
    }

    void show()
    {
        cout << real << "+" << img << "i" << endl;
    }
};

int main()
{
    // Write C++ code here
    Complex c1(5, 3);
    Complex c2(2, 2);
    Complex c3 = c1 - c2;
    c3.show();

    return 0;
}