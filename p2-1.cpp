#include <iostream>
using namespace std;

class plots
{
private:
    float length;
    float width;
    float area;
    float perimeter;

public:
    float areavalue(float l, float b)
    {
        cout << "enter the value of length = ";
        cin >> length;
        cout << "enter the value of width = ";
        cin >> width;

        if (length <= 0 || width <= 0)
        {
            cout << "Invalid Input";
        }

        else
        {

            if (length == width)
            {
                cout << "rectangle is a square.\n";
            }

            cout << "Area=";

            return length * width;
        }
    }

    float perimetervalue(float l, float b)
    {
        cout << "enter the value of length = ";
        cin >> length;
        cout << "enter the value of width = ";
        cin >> width;

        if (length <= 0 || width <= 0)
        {
            cout << "Invalid Input";
        }
        else
        {
            if (length == width)
            {
                cout << "rectangle is a square.\n";
            }

            cout << "Perimeter=";

            return 2 * (length + width);
        }
    }
};

int main()
{
    int choice;
    plots p;

    do
    {
        cout << "=== welcome ===\n";
        cout << "1.area\n";
        cout << "2.perimeter\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << p.areavalue(0, 0) << endl;
            break;
        }
        case 2:
        {
            cout << p.perimetervalue(0, 0) << endl;
            break;
        }
        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << " Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}