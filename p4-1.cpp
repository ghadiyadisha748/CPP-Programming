#include <iostream>
using namespace std;

int main()
{
    int *arr = nullptr; // pointer for array
    int size = 0;       // current size

    int choice, value, pos;

    while (true)
    {
        cout << "\n1. Insert at end";
        cout << "\n2. Delete from position";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // INSERT
            cout << "Enter value: ";
            cin >> value;

            int *newArr = new int[size + 1]; // new bigger array

            // copy old data
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }

            newArr[size] = value; // add new element

            delete[] arr; // free old memory
            arr = newArr;

            size++;

            cout << "Inserted!\n";
        }

        else if (choice == 2)
        {
            // DELETE
            if (size == 0)
            {
                cout << "Array is empty!\n";
                continue;
            }

            cout << "Enter position (0 to " << size - 1 << "): ";
            cin >> pos;

            if (pos < 0 || pos >= size)
            {
                cout << "Invalid position!\n";
                continue;
            }

            int *newArr = new int[size - 1];

            int j = 0;
            for (int i = 0; i < size; i++)
            {
                if (i != pos)
                {
                    newArr[j] = arr[i];
                    j++;
                }
            }

            delete[] arr;
            arr = newArr;

            size--;

            cout << "Deleted!\n";
        }

        else if (choice == 3)
        {
            // DISPLAY
            if (size == 0)
            {
                cout << "Array is empty!\n";
            }
            else
            {
                cout << "Array: ";
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }

        else if (choice == 4)
        {
            delete[] arr;
            break;
        }

        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}