#include <bits/stdc++.h>
using namespace std;

void ShellSort(vector<int> &v)
{
    int n = v.size();

    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j += gap)
        {
            for (int i = j - gap; i >= 0; i-=gap)
            {
                if (v.at(i + gap) > v.at(i))
                {
                    break;
                }
                else
                {
                    swap(v.at(i + gap), v.at(i));
                }
            }
        }
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

    ShellSort(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
