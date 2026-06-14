#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    vector<int> v;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    // Method 1: Using std::reverse()
    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    for (int i : v1)
        cout << i << " ";

    // Method 2: Manual reversal using iterators
    vector<int> v2 = v;
    auto start = v2.begin();
    auto end = v2.end() - 1;

    while (start < end)
    {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "\nReversed manually: ";
    for (int i : v2)
        cout << i << " ";

    return 0;
}