#include <iostream>
using namespace std;

class Employee
{
    int empID;
    string name;
    double basicSalary, bonus;

public:
    Employee()
    {
        empID = 0;
        name = "None";
        basicSalary = 0;
        bonus = 1000;
    }

    Employee(int id, string n, double salary, double b = 1000)
    {
        empID = id;
        name = n;

        if (salary < 0)
            salary = 0;
        if (b < 0)
            b = 0;

        basicSalary = salary;
        bonus = b;
    }

    inline double totalSalary()
    {
        return basicSalary + bonus;
    }

    void updateBonus(double b)
    {
        if (b >= 0)
            bonus = b;
    }
    string grade()
    {
        double total = totalSalary();
        if (total >= 80000)
            return "A";
        else if (total >= 50000)
            return "B";
        else
            return "C";
    }

    void show()
    {
        cout << "\nEmployee ID: " << empID
             << "\nName: " << name
             << "\nBasic Salary: " << basicSalary
             << "\nBonus: " << bonus
             << "\nTotal Salary: " << totalSalary()
             << "\nGrade: " << grade() << endl;
    }
};

int main()
{
    int n = 5;
    Employee *emp = new Employee[n];

    emp[0] = Employee(101, "Disha", 50000);
    emp[1] = Employee(102, "Rahul", 60000, 5000);
    emp[2] = Employee(103, "Asha", 45000);
    emp[3] = Employee(104, "Karan", 70000, 8000);
    emp[4] = Employee(105, "Neha", 30000);

    cout << "Payroll Details:\n";
    for (int i = 0; i < n; i++)
        emp[i].show();

    delete[] emp;
    return 0;
}
