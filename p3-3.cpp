#include <string>
#include <iostream>
using namespace std;

class Account
{
public:
    int accountNumber;
    string holderName;
    double balance;

    Account()
    {
        accountNumber = 0;
        holderName = "";
        balance = 0.0;
    }

    Account(int accNum, string name, double bal)
    {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
    }

    void display()
    {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Bank
{
private:
    Account accounts[100];
    static int totalAccounts;

public:
    void createAccount()
    {
        int accNum;
        string name;
        double balance;

        cout << "\nEnter Account Number: ";
        cin >> accNum;
        cin.ignore();
        cout << "Enter Holder Name: ";
        getline(cin, name);
        cout << "Enter Initial Balance: $";
        cin >> balance;

        accounts[totalAccounts] = Account(accNum, name, balance);
        totalAccounts++;

        cout << "\nAccount created successfully!" << endl;
        cout << "Total Accounts: " << totalAccounts << endl;
    }

    int findAccount(int accNum)
    {
        for (int i = 0; i < totalAccounts; i++)
        {
            if (accounts[i].accountNumber == accNum)
            {
                return i;
            }
        }
        return -1;
    }

    void viewAccount()
    {
        int accNum;
        cout << "\nEnter Account Number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index != -1)
        {
            accounts[index].display();
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    void transferMoney()
    {
        int fromAcc, toAcc;
        double amount;

        cout << "\nEnter Source Account Number: ";
        cin >> fromAcc;
        cout << "Enter Destination Account Number: ";
        cin >> toAcc;
        cout << "Enter Amount to Transfer: $";
        cin >> amount;

        int fromIndex = findAccount(fromAcc);
        int toIndex = findAccount(toAcc);

        if (fromIndex == -1)
        {
            cout << "Source account not found!" << endl;
            return;
        }
        if (toIndex == -1)
        {
            cout << "Destination account not found!" << endl;
            return;
        }
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }
        if (accounts[fromIndex].balance < amount)
        {
            cout << "Insufficient balance!" << endl;
            return;
        }

        accounts[fromIndex].balance -= amount;
        accounts[toIndex].balance += amount;

        cout << "\nTransfer successful!" << endl;
        cout << "New balance in Account " << fromAcc << ": " << accounts[fromIndex].balance << endl;
        cout << "New balance in Account " << toAcc << ": " << accounts[toIndex].balance << endl;
    }

    void showTotalAccounts()
    {
        cout << "\nTotal Accounts Created: " << totalAccounts << endl;
    }

    void displayAll()
    {
        if (totalAccounts == 0)
        {
            cout << "\nNo accounts in the system!" << endl;
            return;
        }

        cout << "\n=== All Accounts ===" << endl;
        for (int i = 0; i < totalAccounts; i++)
        {
            accounts[i].display();
        }
    }
};

int Bank::totalAccounts = 0;

int main()
{
    Bank bank;
    int choice;

    while (true)
    {
        cout << "\n======= BANK SYSTEM =======";
        cout << "\n1. Create Account";
        cout << "\n2. View Account";
        cout << "\n3. Transfer Money";
        cout << "\n4. Show Total Accounts";
        cout << "\n5. Display All Accounts";
        cout << "\n6. Exit";
        cout << "\n===========================";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.viewAccount();
            break;
        case 3:
            bank.transferMoney();
            break;
        case 4:
            bank.showTotalAccounts();
            break;
        case 5:
            bank.displayAll();
            break;
        case 6:
            cout << "\nThank you for using Bank System!" << endl;
            return 0;
        default:
            cout << "\nInvalid choice! Try again." << endl;
        }
    }

    return 0;
}