#include <iostream>
using namespace std;

class Item
{
    int id, qty;
    string name;
    float price;

public:
    Item()
    {
        id = 0;
        name = "None";
        price = 0;
        qty = 0;
    }

    Item(int i, string n, float p, int q)
    {
        id = i;
        name = n;
        price = p;
        qty = q;
    }

    void addStock(int x)
    {
        qty += x;
    }

    void sell(int x)
    {
        if (qty >= x)
            qty -= x;
        else
            cout << "Not enough stock!\n";
    }

    void show()
    {
        cout << "ID: " << id << " Name: " << name
             << " Price: " << price << " Stock: " << qty << endl;
    }

    int getID()
    {
        return id;
    }
};

int main()
{

    Item items[3] =
        {
            Item(101, "Laptop", 750, 10),
            Item(102, "Mouse", 15, 50),
            Item(103, "Keyboard", 25, 30)};

    int choice, id, q;

    while (true)
    {
        cout << "\n1.Show \n 2.Add Stock \n 3.Sell \n 4.Exit\n Enter your choice : ";
        cin >> choice;

        if (choice == 4)
            break;

        if (choice == 1)
        {
            for (int i = 0; i < 3; i++)
                items[i].show();
        }

        else if (choice == 2 || choice == 3)
        {
            cout << "Enter Item ID: ";
            cin >> id;
            cout << "Enter Quantity: ";
            cin >> q;

            for (int i = 0; i < 3; i++)
            {
                if (items[i].getID() == id)
                {
                    if (choice == 2)
                        items[i].addStock(q);
                    else
                        items[i].sell(q);
                }
            }
        }
    }
    return 0;
}
