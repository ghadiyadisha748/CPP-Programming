#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
public:
    float temp;

    Celsius(float t = 0)
    {
        temp = t;
    }

    operator Fahrenheit();

    bool operator==(Celsius c)
    {
        return temp == c.temp;
    }
};

class Fahrenheit
{
public:
    float temp;

    Fahrenheit(float t = 0)
    {
        temp = t;
    }

    operator Celsius()
    {
        return Celsius((temp - 32) * 5 / 9);
    }
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main()
{

    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;
    cout << "25 Celsius in Fahrenheit = " << f1.temp << endl;

    Celsius c2;
    c2 = f1;
    cout << "Back to Celsius = " << c2.temp << endl;

    Celsius c3(25);

    if (c1 == c3)
        cout << "Both temperatures are equal\n";

    Celsius arr[3] = {10, 20, 30};

    cout << "\nCelsius to Fahrenheit (Array):\n";
    for (int i = 0; i < 3; i++)
    {
        Fahrenheit f = arr[i];
        cout << arr[i].temp << "C = " << f.temp << "F\n";
    }

    return 0;
}