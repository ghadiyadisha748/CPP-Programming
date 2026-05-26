#include <iostream>
#include <fstream>
using namespace std;

// Add Item
void addItem()
{
    ofstream file("inventory.txt", ios::app);

    string name;
    int qty;
    float price;

    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << qty << " " << price << endl;
    file.close();

    cout << "Item added successfully!\n";
}

// View All Items
void viewItems()
{
    ifstream file("inventory.txt");

    string name;
    int qty;
    float price;

    cout << "\nInventory List:\n";

    while (file >> name >> qty >> price)
    {
        cout << "Name: " << name
             << ", Qty: " << qty
             << ", Price: " << price << endl;
    }

    file.close();
}

// Search Item
void searchItem()
{
    ifstream file("inventory.txt");

    string searchName, name;
    int qty;
    float price;
    bool found = false;

    cout << "Enter item name to search: ";
    cin >> searchName;

    while (file >> name >> qty >> price)
    {
        if (name == searchName)
        {
            cout << "Item Found!\n";
            cout << "Name: " << name
                 << ", Qty: " << qty
                 << ", Price: " << price << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found!\n";
    }

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Item\n2. View Items\n3. Search Item\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            viewItems();
            break;
        case 3:
            searchItem();
            break;
        }

    } while (choice != 4);

    return 0;
}
