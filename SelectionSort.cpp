#include <bits/stdc++.h>
using namespace std;

/*
1. WE WILL DEVIDE THE ARRAY IN TWO SORTED SUBARRAY ( INITIALLY EMPTY ) and UNSORTED SUBARRAY ( from 0th index to LAST index)
2. NOW WE WILL PICK THE SMALLEST ELEMENT OF UNSORTED SUBARRAY AND INSERT IT AT THE LAST INDEX OF SORTED SUBARRAY 
3. INCREMENT SS AND US BY 1 AFTER EVERY ITERATION OF THEIR RESPECTIVE LOOPS 
*/

void SelectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min_index = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v.at(min_index) > v.at(j))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(v.at(i), v.at(min_index));
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

    SelectionSort(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}