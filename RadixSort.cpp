#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &v, int pos)
{
    vector<int> count(10);
    int n = v.size();

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        ++count[(v[i] / pos) % 10];
    }
    for (int i = 1; i <= 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr[--count[((v[i] / pos) % 10)]] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = arr[i];
    }
}

void Radixsort(vector<int> &v, int max_element)
{
    for (int pos = 1; (max_element / pos) > 0; pos *= 10)
    {
        countSort(v, pos);
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

    int max_element = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v.at(i) > max_element)
        {
            max_element = v.at(i);
        }
    }

    Radixsort(v, max_element);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
