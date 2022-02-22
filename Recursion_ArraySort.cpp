#include <bits/stdc++.h>
using namespace std;

void insert(int arr[], int n, int val)
{
    if (n == 1 || arr[n - 2] < val)
    {
        arr[n - 1] = val;
        return;
    }
    // cout << "isne" << endl;
    int last_val = arr[n - 2];
    insert(arr, n - 1, val);
    arr[n - 1] = last_val;
}

void sortArray(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    sortArray(arr, n - 1);
    // cout << "sor" << endl;
    int val = arr[n - 1];
    insert(arr, n, val);
}

int main()
{
    int arr[] = { 2, 5, 1, 4, 3, 1, 4, 5, 2, 5, 2, 6, 77, 8, 7, 68,};

    int size = sizeof(arr)/sizeof(arr[0]);
    sortArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}