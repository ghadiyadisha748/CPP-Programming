#include <iostream>
#include <math.h>
using namespace std;

const float pi = 3.1415;

class shape
{
public:
    float r;

    void radius()
    {

        cout << "Enter the value of radius for circle  =";
        cin >> r;
    }
};

class circle1 : public shape
{
public:
    float area()

    {
        cout
            << "area of circle 1 =";
        return pi * r * r;
    }
};
class circle2 : public shape
{
public:
    float area()
    {
        cout
            << "area of circle 2 =";
        return pi * r * r;
    }
};
class circle3 : public shape
{
public:
    float area()
    {
        cout
            << "area of circle 3 =";
        return pi * r * r;
    }
};

int main()
{

    circle1 c1;
    circle2 c2;
    circle3 c3;
    c1.radius();
    cout << c1.area() << endl;
    c2.radius();
    cout << c2.area() << endl;
    c3.radius();
    cout << c3.area() << endl;
}