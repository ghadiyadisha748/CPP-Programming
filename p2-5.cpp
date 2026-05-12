#include <iostream>
using namespace std;

class Loan
{
    int loanID, months;
    string name;
    double amount, rate;

public:
    Loan()
    {
        loanID = 0;
        name = "None";
        amount = 0;
        rate = 0;
        months = 0;
    }

    Loan(int id, string n, double a, double r, int m)
    {
        loanID = id;
        name = n;
        amount = a;
        rate = r;
        months = m;
    }

    double power(double base, int exp)
    {
        double result = 1;
        for (int i = 1; i <= exp; i++)
            result *= base;
        return result;
    }

    double EMI()
    {
        double R = (rate / 12) / 100;
        double x = power(1 + R, months);
        return (amount * R * x) / (x - 1);
    }

    void show()
    {
        cout << "\nLoan ID: " << loanID
             << "\nName: " << name
             << "\nAmount: " << amount
             << "\nRate: " << rate << "%"
             << "\nTenure: " << months << " months"
             << "\nMonthly EMI: " << EMI() << endl;
    }
};

int main()
{
    Loan L1;
    Loan L2(101, "Disha", 500000, 12, 24);

    cout << "Default Loan Details:";
    L1.show();

    cout << "\nParameterized Loan Details:";
    L2.show();

    return 0;
}
