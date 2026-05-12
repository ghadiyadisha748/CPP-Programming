#include <iostream>
using namespace std;

class student
{
private:
    int rollnumber;
    string name;
    float a, b, c;

public:
    float calculatemarks(int i)
    {
        cout << "\nenter marks for subject 1 for student " << i << "=";
        cin >> a;
        cout << "\nenter marks for subject 2 for student " << i << "=";
        cin >> b;
        cout << "\nenter marks for subject 3 for student " << i << "=";
        cin >> c;

        float avg = (a + b + c) / 3;

        cout << "Average marks for student" << i << " = ";
        return avg;
    }
};

int main()
{

    int rollnumber;
    string name;
    int n;

    cout << "enter no of students =";
    cin >> n;
    student s[50];

    for (int i = 0; i < n; i++)
    {
        {
            cout << "\nenter roll number for student" << i + 1 << " = ";
            cin >> rollnumber;
            cout << "\nenter name for student" << i + 1 << "=";
            cin >> name;
            cout << s[i].calculatemarks(i + 1);
        }
    }
    return 0;
}
