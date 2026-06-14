#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    set<int> s;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }

    cout << "\nUnique sorted elements (using set): ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    vector<int> v(s.begin(), s.end());

    cout << "\n\nElements in vector: ";
    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}