
#include <iostream>
using namespace std;

class Calculator
{
    int a, b;

public:
    int add(int a, int b)
    {
        int ans = a + b;
        return ans;
    }

    int add(int a, float b)
    {
        int ans = a + b;
        return ans;
    }

    int add(float a, float b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }

    int minus(int a, int b)
    {
        return a - b;
    }

    int minus(int a, float b)
    {
        return a - b;
    }
    int minus(float a, float b)
    {
        return a - b;
    }
};

int main()
{
    Calculator cal;
    cout << "Addition of two int = " << cal.add(2, 3) << endl;
    cout << "Addition of int + float = " << cal.add(2, 3.3f) << endl;
    cout << "Addition of two float = " << cal.add(2.f, 3.5f) << endl;
    cout << "Addition of three int = " << cal.add(1, 2, 3) << endl;

    cout << "Subtraction of two int = " << cal.minus(5, 3) << endl;
    cout << "Subtraction of two int = " << cal.minus(5, 3) << endl;
}