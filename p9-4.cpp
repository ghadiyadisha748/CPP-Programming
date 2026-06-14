#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string>> directory;
    int choice;
    string folder, file;

    do
    {
        cout << "\n1. Add Folder\n";
        cout << "2. Add File\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter folder name: ";
            cin >> folder;

            directory[folder]; // Create folder
        }
        else if (choice == 2)
        {
            cout << "Enter folder name: ";
            cin >> folder;

            cout << "Enter file name: ";
            cin >> file;

            // Add file to folder
            directory[folder].insert(directory[folder].end(), file);
        }
        else if (choice == 3)
        {
            cout << "\nDirectory Contents:\n";

            for (auto it = directory.begin(); it != directory.end(); it++)
            {
                cout << it->first << ":\n";

                for (auto f : it->second)
                {
                    cout << " - " << f << endl;
                }
            }
        }

    } while (choice != 4);

    return 0;
}