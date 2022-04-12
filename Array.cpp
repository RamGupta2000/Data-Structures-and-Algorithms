#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int main()
{
    int arr[MAX];

    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    cout << endl
         << "Enter the elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << endl
         << "Elements of array are : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    char a;
    cout << endl
         << "Press i to insert or d to delete element from array : ";
    cin >> a;

    if (a == 'i')
    {
        cout << endl
             << "Enter 1 to insert at beginning, 2 for end and 3 for position : ";
        int a;
        cin >> a;

        if (a == 1)
        {
            // Insertion at beginning
            size = size + 1;
            for (int i = size - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            cout << "Enter the element you wanna insert at beginning : ";
            int e;
            cin >> e;
            arr[0] = e;
            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }

        if (a == 2)
        {
            // Insertion at end
            cout << "Enter the element you wanna insert at end : ";
            int e;
            cin >> e;
            size++;
            arr[size - 1] = e;
            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }

        if (a == 3)
        {
            // Insertion at pos
            cout << "Enter the position at which you wanna insert the element : ";
            int pos;
            cin >> pos;
            size++;

            int i;
            for (i = size - 1; i > pos - 1; i--)
            {
                arr[i] = arr[i - 1];
            }
            cout << "Enter the element to be inserted at position " << pos << " : ";
            int x;
            cin >> x;
            arr[i] = x;

            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }
    }

    if (a == 'd')
    {
        cout << endl
             << "Enter 1 to delete at beginning, 2 for end and 3 for position : ";
        int a;
        cin >> a;

        if (a == 1)
        {
            // Deletion at beginning
            for (int i = 0; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }

        if (a == 2)
        {
            // Deletion at end
            size--;
            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }

        if (a == 3)
        {
            // Deletion at pos
            cout << "Enter the position from which you wanna delete the element : ";
            int pos;
            cin >> pos;

            size--;
            for (int i = pos - 1; i < size; i++)
            {
                arr[i] = arr[i + 1];
            }

            for (int i = 0; i < size; i++)
            {
                cout << endl
                     << arr[i] << " ";
            }
        }
    }

    return 0;
}