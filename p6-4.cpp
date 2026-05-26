#include <iostream>
using namespace std;

class account
{
public:
    int accNo;
    float balance;

    void getData()
    {
        cout << "Enter Account Number = ";
        cin >> accNo;

        cout << "Enter Initial Balance = ";
        cin >> balance;
    }

    void deposit()
    {
        float amount;
        cout << "Enter amount to deposit = ";
        cin >> amount;

        balance = balance + amount;
    }

    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw = ";
        cin >> amount;

        if (amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient Balance\n";
        }
    }

    void display()
    {
        cout << "Account Number = " << accNo << endl;
        cout << "Balance = " << balance << endl;
    }
};

class savings : public account
{
public:
    float interestRate;

    void getInterest()
    {
        cout << "Enter Interest Rate = ";
        cin >> interestRate;
    }

    void addInterest()
    {
        balance = balance + (balance * interestRate / 100);
    }
};

class current : public account
{
public:
    float overdraft;

    void getOverdraft()
    {
        cout << "Enter Overdraft Limit = ";
        cin >> overdraft;
    }

    void withdraw()
    {
        float amount;
        cout << "Enter amount to withdraw = ";
        cin >> amount;

        if (amount <= balance + overdraft)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Overdraft Limit Exceeded\n";
        }
    }
};

int main()
{
    savings s;
    current c;

    cout << "------ SAVINGS ACCOUNT ------\n";
    s.getData();
    s.getInterest();
    s.deposit();
    s.addInterest();
    s.withdraw();
    s.display();

    cout << "\n------ CURRENT ACCOUNT ------\n";
    c.getData();
    c.getOverdraft();
    c.deposit();
    c.withdraw();
    c.display();

    return 0;
}