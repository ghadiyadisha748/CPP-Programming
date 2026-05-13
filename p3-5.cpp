#include <iostream>
using namespace std;

long long superDigit(long long num)
{
    if (num < 10)
        return num;

    long long sum = 0;

    while (num > 0)
    {
        sum = sum + (num % 10);
        num = num / 10;
    }

    return superDigit(sum);
}

int main()
{
    string n;
    long long k;

    cout << "Enter number (as string) = ";
    cin >> n;

    cout << "Enter value of k = ";
    cin >> k;

    long long sum = 0;

    for (int i = 0; i < n.length(); i++)
    {
        sum = sum + (n[i] - '0');
    }

    sum = sum * k;

    cout << "Super Digit = " << superDigit(sum);

    return 0;
}