#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    string customerName;
    int accountID;
    float balance;

public:
    SavingsAccount()
    {
        customerName = "";
        accountID = 0;
        balance = 0;
    }

    void createAccount(string name, int id, float initialBalance)
    {
        customerName = name;
        accountID = id;

        if (initialBalance < 0)
            balance = 0;
        else
            balance = initialBalance;

        cout << " Account created successfully!\n";
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << " Invalid deposit amount!\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful! New Balance = " << balance << "\n";
    }

    void withdraw(float amount)
    {
        if (amount <= 0)
        {
            cout << " Invalid withdrawal amount!\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Withdrawal denied! Insufficient balance.\n";
            return;
        }
        if (amount > 1000)
        {
            cout << "Withdrawal denied! you can not withdraw amount more than 1000.\n";
            return;
        }

        balance -= amount;
        cout << " Withdrawal successful! New Balance = " << balance << "\n";
    }

    void displaySummary()
    {
        cout << "\n========== ACCOUNT SUMMARY ==========\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Account ID    : " << accountID << endl;
        cout << "Balance       : " << balance << endl;
        cout << "=====================================\n";
    }

    int getAccountID()
    {
        return accountID;
    }
};

int main()
{
    SavingsAccount accounts[50];
    int totalAccounts = 0;
    int choice;

    while (true)
    {
        cout << "\n===== DIGITAL SAVINGS ACCOUNT SYSTEM =====\n";
        cout << "1. Create Account (Zero Balance)\n";
        cout << "2. Create Account (Custom Initial Balance)\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Display Account Summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6)
        {
            cout << " Exiting system... Thank you!\n";
            break;
        }

        if (choice == 1 || choice == 2)
        {
            if (totalAccounts >= 50)
            {
                cout << " Cannot create more accounts (limit reached).\n";
                continue;
            }

            string name;
            int id;
            float initialBalance = 0;

            cout << "Enter Customer Name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter Unique Account ID: ";
            cin >> id;

            if (choice == 2)
            {
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;
            }

            accounts[totalAccounts].createAccount(name, id, initialBalance);
            totalAccounts++;
        }

        else if (choice == 3)
        {
            int id;
            float amount;

            cout << "Enter Account ID: ";
            cin >> id;

            int found = -1;
            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountID() == id)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                cout << "Account not found!\n";
                continue;
            }

            cout << "Enter Deposit Amount: ";
            cin >> amount;

            accounts[found].deposit(amount);
        }

        else if (choice == 4)
        {
            int id;
            float amount;

            cout << "Enter Account ID: ";
            cin >> id;

            int found = -1;
            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountID() == id)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                cout << " Account not found!\n";
                continue;
            }

            cout << "Enter Withdrawal Amount: ";
            cin >> amount;

            accounts[found].withdraw(amount);
        }

        else if (choice == 5)
        {
            int id;
            cout << "Enter Account ID: ";
            cin >> id;

            int found = -1;
            for (int i = 0; i < totalAccounts; i++)
            {
                if (accounts[i].getAccountID() == id)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                cout << "Account not found!\n";
                continue;
            }

            accounts[found].displaySummary();
        }

        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
