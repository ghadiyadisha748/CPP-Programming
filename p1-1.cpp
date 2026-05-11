#include <iostream>
#include <string>
using namespace std;

class Wallet
{
private:
    int walletID;
    string userName;
    double balance;
    string history[5];
    int count = 0;
    double cashbackPercent;
    bool isFrozen;

public:
    Wallet(int id, string name, double initialBalance = 0.0, double cashback = 0.0)
    {
        walletID = id;
        userName = name;
        balance = initialBalance;
        cashbackPercent = cashback;
        isFrozen = false;
    }

    void loadMoney(double amount)
    {
        if (isFrozen)
        {
            cout << "Wallet is frozen! Cannot load money.\n";
            addTransaction("Load Failed (Frozen)");
            return;
        }

        if (amount <= 0)
        {
            cout << " Invalid amount! Please enter a positive value.\n";
            return;
        }

        double cashback = (amount * cashbackPercent) / 100;
        balance += (amount + cashback);

        cout << "Money Loaded Successfully!\n";
        cout << "Cashback Applied: " << cashback << " (" << cashbackPercent << "%)\n";

        addTransaction("Loaded: " + to_string(amount) +
                       " | Cashback: " + to_string(cashback));
    }

    void transferMoney(Wallet &receiver, double amount)
    {
        if (isFrozen)
        {
            cout << "Your wallet is frozen! Cannot transfer money.\n";
            addTransaction("Transfer Failed (Frozen)");
            return;
        }

        if (receiver.isFrozen)
        {
            cout << "Receiver wallet is frozen! Transfer not allowed.\n";
            addTransaction("Transfer Failed (Receiver Frozen)");
            return;
        }

        if (amount <= 0)
        {
            cout << " Invalid transfer amount!\n";
            return;
        }

        if (amount > balance)
        {
            cout << " Transfer Failed! Insufficient balance.\n";
            addTransaction("Failed Transfer: " + to_string(amount));
        }
        else
        {
            balance -= amount;
            receiver.balance += amount;

            cout << " Transfer Successful!\n";

            addTransaction("Sent: " + to_string(amount) + " to " + receiver.userName);
            receiver.addTransaction("Received: " + to_string(amount) + " from " + userName);
        }
    }

    void displayDetails() const
    {
        cout << "\n--- Wallet Details ---\n";
        cout << "Wallet ID : " << walletID << endl;
        cout << "User Name : " << userName << endl;
        cout << "Balance   : " << balance << endl;
        cout << "----------------------\n";
    }

    int getWalletID() const
    {
        return walletID;
    }

    void addTransaction(string msg)
    {
        if (count < 5)
        {
            history[count] = msg;
            count++;
        }
        else
        {

            for (int i = 0; i < 4; i++)
            {
                history[i] = history[i + 1];
            }
            history[4] = msg;
        }
    }
    void showHistory()
    {
        cout << "\n--- Last Transactions of " << userName << " ---\n";

        if (count == 0)
        {
            cout << "No transactions yet.\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }

    void freezeWallet()
    {
        isFrozen = true;
        cout << "Wallet is now FROZEN.\n";
        addTransaction("Wallet Frozen");
    }

    void unfreezeWallet()
    {
        isFrozen = false;
        cout << "Wallet is now ACTIVE.\n";
        addTransaction("Wallet Unfrozen");
    }
};

int main()
{
    int id1, id2;
    string name1, name2;
    double bal1, bal2;
    double cashback1, cashback2;

    cout << "Enter Wallet 1 ID: ";
    cin >> id1;
    cout << "Enter Wallet 1 User Name: ";
    cin >> name1;
    cout << "Enter Wallet 1 Initial Balance: ";
    cin >> bal1;
    cout << "Enter Wallet 1 Cashback Percentage: ";
    cin >> cashback1;

    cout << "\nEnter Wallet 2 ID: ";
    cin >> id2;
    cout << "Enter Wallet 2 User Name: ";
    cin >> name2;
    cout << "Enter Wallet 2 Initial Balance: ";
    cin >> bal2;
    cout << "Enter Wallet 2 Cashback Percentage: ";
    cin >> cashback2;

    Wallet w1(id1, name1, bal1, cashback1);
    Wallet w2(id2, name2, bal2, cashback2);

    int choice;
    do
    {
        cout << "\n===== Digital Wallet Menu =====\n";
        cout << "1. Load Money\n";
        cout << "2. Transfer Money\n";
        cout << "3. Display Wallet Details\n";
        cout << "4. Show Transaction History\n";
        cout << "5. Freeze Wallet\n";
        cout << "6. Unfreeze Wallet\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int walletChoice;
            double amount;
            cout << "Load money into:\n1. Wallet 1\n2. Wallet 2\nChoose wallet: ";
            cin >> walletChoice;

            cout << "Enter amount to load: ";
            cin >> amount;

            if (walletChoice == 1)
                w1.loadMoney(amount);
            else if (walletChoice == 2)
                w2.loadMoney(amount);
            else
                cout << " Invalid wallet selection!\n";
            break;
        }

        case 2:
        {
            int senderChoice;
            double amount;
            cout << "Transfer from:\n1. Wallet 1 to Wallet 2\n2. Wallet 2 to Wallet 1\nChoose option: ";
            cin >> senderChoice;

            cout << "Enter amount to transfer: ";
            cin >> amount;

            if (senderChoice == 1)
                w1.transferMoney(w2, amount);
            else if (senderChoice == 2)
                w2.transferMoney(w1, amount);
            else
                cout << " Invalid option!\n";
            break;
        }

        case 3:
            cout << "\nWallet 1 Details:";
            w1.displayDetails();
            cout << "\nWallet 2 Details:";
            w2.displayDetails();
            break;

        case 4:
            cout << "\nWallet 1 Transaction History:";
            w1.showHistory();
            cout << "\nWallet 2 Transaction History:";
            w2.showHistory();
            break;

        case 5:
        {
            int w;
            cout << "Freeze which wallet? (1 or 2): ";
            cin >> w;

            if (w == 1)
                w1.freezeWallet();
            else if (w == 2)
                w2.freezeWallet();
            else
                cout << "Invalid choice!\n";
            break;
        }
        case 6:
        {
            int w;
            cout << "Unfreeze which wallet? (1 or 2): ";
            cin >> w;

            if (w == 1)
                w1.unfreezeWallet();
            else if (w == 2)
                w2.unfreezeWallet();
            else
                cout << "Invalid choice!\n";
            break;
        }
        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << " Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
