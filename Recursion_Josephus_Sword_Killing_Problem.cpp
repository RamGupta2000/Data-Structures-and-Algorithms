#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, int index, int k)
{
    if (v.size() == 1)
    {
        cout << v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase( v.begin() + index );

    solve(v, index, k);
}

int main()
{
    int n, k;

    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    cin >> k;
    k = k - 1;

    int index = 0;

    solve(v, index, k);
    return 0;
}