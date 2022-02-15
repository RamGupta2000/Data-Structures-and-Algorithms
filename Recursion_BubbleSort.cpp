#include <bits/stdc++.h>
using namespace std;

// IN FIRST ITERATION SMALLEST ELEMENT WILL COME AT FIRST INDEX
// IN SECOND ITERATION 2ND SMALLEST ELEMENT WILL COME AT SECOND INDEX and so on....

// If the array gets sorted before the all the iterations i.e. no swapping is done, then the function
// terminates

void bubblesort(vector<int> &v,int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
            swap(v[i], v[i + 1]);
    }

    bubblesort(v,n-1);
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

    bubblesort(v,v.size());

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}