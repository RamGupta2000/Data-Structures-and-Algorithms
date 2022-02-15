#include <bits/stdc++.h>
using namespace std;

bool IsSorted(int arr[], int n)
{
    if( n==0  || n==1 )
    {
        return true;
    }
    if( arr[0]>arr[1] )
    {
        return false;
    }
    else
    {
        return IsSorted(arr+1,n-1);
    }
}

int main()
{
    int arr[] = {1,2,3,44,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<IsSorted(arr, size);
    return 0;
}
