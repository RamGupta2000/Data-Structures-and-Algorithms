#include <bits/stdc++.h>
using namespace std;

void Countsort(vector<int> &v, int k)
{
    int n = v.size();
    vector<int> count(k + 1);
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        count[v[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        arr[--count[v[i]]] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = arr[i];
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

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (v.at(i) > max)
        {
            max = v.at(i);
        }
    }

    Countsort(v, max);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}