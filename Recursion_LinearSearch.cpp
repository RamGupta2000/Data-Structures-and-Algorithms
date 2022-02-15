#include <bits/stdc++.h>
using namespace std;

// void print(int arr[], int n)
// {
//     cout << "size of array is : " << n << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

bool linearSearch(int arr[], int n, int key)
{
    // print(arr, n);
    if (n == 0)
        return 0;

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return linearSearch(arr + 1, n - 1, key);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (linearSearch(arr, size, 6))
    {
        cout << endl
             << "Found";
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}