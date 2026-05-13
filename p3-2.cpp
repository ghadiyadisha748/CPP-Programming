#include <iostream>
#include <ctime>
using namespace std;

int recursiveSum(int arr[], int n)
{
    if (n == 0)
        return arr[0];
    return arr[n] + recursiveSum(arr, n - 1);
}

int iterativeSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int recursiveMax(int arr[], int n)
{
    if (n == 0)
        return arr[0];

    int m = recursiveMax(arr, n - 1);
    return (arr[n] > m) ? arr[n] : m;
}

int iterativeMax(int arr[], int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    clock_t start1 = clock();
    int rsum = recursiveSum(arr, n - 1);
    clock_t end1 = clock();

    clock_t start2 = clock();
    int isum = iterativeSum(arr, n);
    clock_t end2 = clock();

    cout << "\nRecursive Sum = " << rsum;
    cout << "\nIterative Sum = " << isum;

    cout << "\nRecursive Max = " << recursiveMax(arr, n - 1);
    cout << "\nIterative Max = " << iterativeMax(arr, n);

    double recTime = double(end1 - start1) / CLOCKS_PER_SEC;
    double iteTime = double(end2 - start2) / CLOCKS_PER_SEC;

    cout << "\n\nExecution Time:";
    cout << "\nRecursive: " << recTime << " sec";
    cout << "\nIterative: " << iteTime << " sec";

    delete[] arr;
    return 0;
}
