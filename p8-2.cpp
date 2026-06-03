#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    float a, b;

    cout << "Enter value of a :";
    cin >> a;

    try
    {
        if (a > 0)
        {
            b = sqrt(a);
            cout << "square root is : " << b << endl;
        }
        else
        {
            throw(a);
        }
    }
    catch (float a)
    {
        cout << " Exception caught : Invalid input as square root of negative number or zero is not valid. " << endl;
    }
    return 0;
}