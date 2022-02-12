#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mergeNsort(int a[], int b[], int n, int m, int answer[])
    {
        int hash_map[100000]={0};

        for(int i=0; i<n; i++)
        {
            hash_map[a[i]]=1;
        }
        for(int i=0; i<n; i++)
        {
            hash_map[b[i]]=1;
        }

        int k=0;
        for( int i=0; i<100000; i++ )
        {
            if( hash_map[i]==1 )
            {
                answer[k++]=i;
            }
        }
        return k;
    }
        
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        int b[m + 5];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        Solution ob;
        int answer[n + m + 5];
        int x = ob.mergeNsort(a, b, n, m, answer);

        for (int i = 0; i < x; i++)
            cout << answer[i] << " ";
        cout << endl;
    }

    return 0;
}