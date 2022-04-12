#include <bits/stdc++.h>
using namespace std;

/*  When given no's from range  1 to N than use Cyclic Sort :
    i.e, continuos no. should be present

    Eg: {1,4,5,3,2} , { 3,5,4,7,6 }, { 9,5,8,7,6,3,4,2,1 }
*/

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int i = 0;
    while (i < n)
    {
        if (i == arr[i] - 1)
        {
            i++;
            // cout<<" compared "<<endl;
        }
        else
        {
            swap(arr[i], arr[arr[i] - 1]);
            // cout<<" swapped "<<endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}