#include <iostream>
#include <Iomanip>
#include <string>
using namespace std;

ostream &currency(ostream &cout)
{
    cout << "Rs.";
    return cout;
}

void printfees(double amount)
{
    cout << "Rs." << fixed << setprecision(2) << amount << endl;
}

int main()
{
    string name[3] = {"Disha", "Man", "Dharmi"};
    double fees[3] = {12000.00, 15000.00, 20000.00};
    int math[3] = {100, 99, 67};
    int science[3] = {90, 95, 80};

    cout << setfill('=') << setw(55) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(12) << "NAME"
         << right << setw(8) << "SCIENCE"
         << right << setw(10) << "MATHS"
         << right << setw(10) << "PERCENTAGE"
         << right << setw(12) << "FEES" << endl;

    cout << setfill('=') << setw(55) << "" << endl;
    cout << setfill(' ');
    for (int i = 0; i < 3; i++)
    {
        double percentage = (math[i] + science[i]) / 2.0;
        cout << left << setw(12) << name[i]
             << right << setw(8) << science[i]
             << right << setw(10) << math[i]
             << right << setw(10) << fixed << setprecision(2) << percentage
             << right << setw(10);
        printfees(fees[i]);
        cout << endl;

        cout << setfill('=') << setw(55) << "" << endl;

        cout << endl;
        cout << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');
        cout << "             FEE RECIEPT" << endl;
        cout << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');

        double total = 0;
        for (int i = 0; i < 3; i++)
        {
            total += fees[i];
        }
        cout << left << setw(10) << name[i]
             << "  Fees :";
        cout << currency
             << fixed << setprecision(2) << fees[i] << endl;

        cout << setfill('-') << setw(40) << "" << setfill(' ') << endl;
        cout << left << setw(10) << "Total"
             << "  Fees :";
        cout << currency
             << fixed << setprecision(2) << total << endl;

        cout << setfill('=') << setw(40) << "" << endl;

        return 0;
    }
}