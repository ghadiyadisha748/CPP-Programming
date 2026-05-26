#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string text, word, temp;

    cout << "Enter paragraph : ";
    getline(cin, text);

    cout << "Enter word to count : ";
    cin >> word;

    int ocr = 0;

    stringstream ss(text);

    while (ss >> temp)
    {
        if (temp == word)
        {
            ocr++;
        }
    }

    cout << "Word repeated : " << ocr;

    return 0;
}
