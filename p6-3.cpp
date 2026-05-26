#include <iostream>
#include <string>
using namespace std;

class Fuel
{
public:
    string FuelType;

    void inputFuel()
    {
        cout << "ENTER THE TYPE OF FUEL : ";
        cin >> FuelType;
    }
};

class Brand
{
public:
    string BrandName;

    void inputBrand()
    {
        cout << "ENTER THE BRAND NAME : ";
        cin >> BrandName;
    }
};

class Car : public Fuel, public Brand
{
public:
    void display()
    {
        cout << "\n===CAR DETAILS=== " << endl;
        cout << "FUEL TYPE : " << FuelType << endl;
        cout << "BRAND NAME : " << BrandName << endl;
    }
};

int main()
{
    int n;
    cout << "ENTER THE NUMBER OF CARS : ";
    cin >> n;
    Car c[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nFOR CAR " << i + 1 << endl;
        c[i].inputFuel();
        c[i].inputBrand();
        c[i].display();
    }
    return 0;
}