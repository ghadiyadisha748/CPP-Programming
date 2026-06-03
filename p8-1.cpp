#include <iostream>
using namespace std;
int main()
{
    int a, b, c;

    cout << "Enter values of a and b :";
    cin >> a >> b;

    try
    {
        if (b != 0)
        {
            c = a / b;
            cout << "Answer is :" << c << endl;
        }
        else
        {
            throw(b);
        }
    }
    catch (int b)
    {
        cout << " Exception caught : Invalid output as denominator cannot be zero." << endl;
    }
    return 0;
}