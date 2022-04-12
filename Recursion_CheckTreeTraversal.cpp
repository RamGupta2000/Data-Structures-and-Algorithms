

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int preorder[], int inorder[], int postorder[], int N)
    {
        if (N == 0)
        {
            return 1;
        }
        if (N == 1)
        {
            return ((preorder[0] == inorder[0]) && (postorder[0] == inorder[0]));
        }
        int root = preorder[0];
        int idx = -1;
        for (int i = 0; i < N; i++)
        {
            if (root == inorder[i])
            {
                idx = i;
                break;
            }
        }
        int flag = 0;
        if (idx != -1)
        {
            for (int i=0; i < N; i++)
            {
                if (root == postorder[i])
                {
                    flag=1;
                    break;
                }
            }
        }
        if (idx == -1 || flag == 0)
        {
            return 0;
        }

        bool res1 = solve(preorder + 1, inorder, postorder, idx);
        bool res2 = solve(preorder + idx + 1, inorder + idx + 1, postorder + idx, N - idx - 1);

        return (res1 && res2);
    }

    bool checktree(int preorder[], int inorder[], int postorder[], int N)
    {

        return solve(preorder, inorder, postorder, N);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int preorder[n];
        int inorder[n];
        int postorder[n];

        for (int i = 0; i < n; ++i)
            cin >> preorder[i];

        for (int i = 0; i < n; ++i)
            cin >> inorder[i];

        for (int i = 0; i < n; ++i)
            cin >> postorder[i];

        Solution obj;
        if (obj.checktree(preorder, inorder, postorder, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
