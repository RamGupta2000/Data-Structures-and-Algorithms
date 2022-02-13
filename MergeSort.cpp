#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &v, int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    vector<int> arr(v.size());

    while (i <= mid && j <= ub)
    {
        if (v[i] <= v[j])
        {
            arr[k++] = v[i++];
        }
        else
        {
            arr[k++] = v[j++];
        }
    }
    while (i <= mid)
    {
        arr[k++] = v[i++];
    }

    while (j <= ub)
    {
        arr[k++] = v[j++];
    }

    for (int i = lb; i < k; i++)
    {
        v[i] = arr[i];
    }
}

void MergeSort(vector<int> &v, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + (ub - lb) / 2);

        MergeSort(v, lb, mid);
        MergeSort(v, mid + 1, ub);
        Merge(v, lb, mid, ub);
    }
}

int main()
{
    vector<int> v;
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    cout << "Enter the Elements of array : ";

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    MergeSort(v, 0, v.size() - 1);

    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
