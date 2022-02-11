#include <bits/stdc++.h>
using namespace std;

/*
1. WE WILL DEVIDE THE ARRAY IN TWO SORTED SUBARRAY ( 0th index ) and UNSORTED SUBARRAY ( from 1st index to index) 
2. NOW WE WILL PICK THE FIST ELEMENT OF UNSORTED SUBARRAY AND INSERT IT IN SEORTED SUBARRAY IN SORTED MANNER
*/

void Insertionsort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int unsorted_SUBARRAY_element = v.at(i);
        int j=i-1;
        while( j>=0 && v.at(j) > unsorted_SUBARRAY_element )
        {
            v.at(j+1)=v.at(j);
            j--;
        }
        v.at(j+1)=unsorted_SUBARRAY_element;
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

    Insertionsort(v);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}