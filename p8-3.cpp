#include <iostream>
using namespace std;

string log[20];
int i = 0;

void addLog(string s)
{
    log[i++] = s;
}

class BankException
{
};

void withdraw(int balance, int amount)
{
    addLog("Entered withdraw");

    if (amount > balance)
        throw BankException();

    addLog("Withdrawal successful");
    addLog("Exited withdraw");
}

void func1(int balance, int amount)
{
    addLog("func1 start");
    withdraw(balance, amount);
    addLog("func1 end"); // skipped if exception occurs
}

int main()
{
    int balance = 1000, amount = 2000;

    try
    {
        addLog("main start");
        func1(balance, amount);
        addLog("main end"); // skipped if exception occurs
    }
    catch (BankException)
    {
        addLog("Exception: Insufficient Balance");
    }

    cout << "--- Logs ---\n";
    for (int j = 0; j < i; j++)
        cout << log[j] << endl;

    return 0;
}