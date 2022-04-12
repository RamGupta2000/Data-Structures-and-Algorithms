#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution
{
public:
    Node *solve(int in[], int inStart, int inEnd, int pre[], int preSatrt, int preEnd, map<int, int> &m)
    {
        if (preSatrt > preEnd || inStart > inEnd)
            return NULL;

        Node *root = new Node(pre[preSatrt]);

        int inRoot = m[root->data];
        int numsLeft = inRoot - inStart;

        root->left = solve(in, inStart, inRoot - 1, pre, preSatrt + 1, preSatrt + numsLeft, m);
        root->right = solve(in, inRoot + 1, inEnd, pre, preSatrt + numsLeft + 1, preEnd, m);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[in[i]] = i;
        }
        Node *root = solve(in, 0, n - 1, pre, 0, n - 1, m);
        return root;
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

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
