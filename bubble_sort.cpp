#include <bits/stdc++.h>
using namespace std;

// IN FIRST ITERATION SMALLEST ELEMENT WILL COME AT FIRST INDEX
// IN SECOND ITERATION 2ND SMALLEST ELEMENT WILL COME AT SECOND INDEX and so on....

// If the array gets sorted before the all the iterations i.e. no swapping is done, then the function
// terminates

void bubblesort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v.at(j) > v.at(j + 1))
            {
                swap(v.at(j), v.at(j + 1));
                flag = false;
            }
        }

        if (flag)
        {
            return;
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

    bubblesort(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}