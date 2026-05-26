#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Employee : public Person
{
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a)
    {
        empID = id;
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "Employee ID : " << empID << endl;
    }
};

class Manager : public Employee
{
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id)
    {
        department = dept;
    }

    void displayManager()
    {
        displayEmployee();
        cout << "Department : " << department << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    string name, dept;
    int age, id;

    cout << "Enter details of Manager 1\n";
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Department: ";
    cin >> dept;

    Manager m1(name, age, id, dept);

    cout << "\nEnter details of Manager 2\n";
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Department: ";
    cin >> dept;

    Manager m2(name, age, id, dept);

    cout << "\nEnter details of Manager 3\n";
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Department: ";
    cin >> dept;

    Manager m3(name, age, id, dept);

    cout << "\nManager Details\n\n";
    m1.displayManager();
    m2.displayManager();
    m3.displayManager();

    return 0;
}
