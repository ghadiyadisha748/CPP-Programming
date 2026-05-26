#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    cout << "Enter size of second array: ";
    cin >> m;

    // dynamic allocation
    int *A = new int[n];
    int *B = new int[m];
    int *C = new int[n + m];

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    // merge logic
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    // remaining elements
    while (i < n)
    {
        C[k++] = A[i++];
    }
    while (j < m)
    {
        C[k++] = B[j++];
    }
    // display result
    cout << "Merged Sorted Array:\n";
    for (int i = 0; i < n + m; i++)
    {
        cout << C[i] << " ";
    }
    // free memory
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
