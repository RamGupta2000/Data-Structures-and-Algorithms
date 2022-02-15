#include <bits/stdc++.h>
using namespace std;

// returns index of the key if present, else -1

int BinarySearch(int arr[], int s, int e, int key)
{
    if (s > e) 
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    // cout<<"mid : "<<arr[mid]<<endl;
    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
    {

        BinarySearch(arr, mid + 1, e, key);
    }
    else
    {
        BinarySearch(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = size - 1;
    cout << BinarySearch(arr, start, end,2);
    // if (BinarySearch(arr, start, end, 111))
    // {
    //     cout << "Found";
    // }
    // else
    // {
    //     cout << "Not found";
    // }

    return 0;
}