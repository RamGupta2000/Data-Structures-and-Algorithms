#include <bits/stdc++.h>
using namespace std;

int Kth_Symbol(int n, int k, int size)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int mid = size / 2;
    if (k <= mid)
    {
        return Kth_Symbol(n - 1, k, size / 2);
    }
    else
    {
        return !(Kth_Symbol(n - 1, k - mid, size / 2));
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int size = pow(2, n - 1);
    // cout<<size<<" ";
    if (k > size)
    {
        cout << "Invalid value of K";
        return 0;
    }
    cout << Kth_Symbol(n, k, size);
    return 0;
}