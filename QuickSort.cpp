#include <bits/stdc++.h>
using namespace std;

/*
    lb = lower bound
    ub = upper bound
*/

int partition(vector<int> &v, int lb, int ub)
{
    int pivot = v.at(lb);
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (v.at(start) <= pivot)
        {
            start++;
        }
        while (v.at(end) > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(v.at(start), v.at(end));
        }
    }
    swap(v.at(lb), v.at(end));
    return end;
}

void QuickSort(vector<int> &v, int lb, int ub)
{
    if (lb < ub)
    {
        int location = partition(v, lb, ub);
        QuickSort(v, lb, location - 1);
        QuickSort(v, location + 1, ub);
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

    int start = 0;
    int end = v.size() - 1;

    QuickSort(v, start, end);

    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}