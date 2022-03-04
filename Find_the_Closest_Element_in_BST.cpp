
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/*
        1
        8 1 9 N 4 N 10 3
        9

        0
*/
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    void InorderTraversal(Node *root, int k, int &ans)
    {
        if (root == NULL)
        {
            return;
        }
        ans = min(ans, abs(k - root->data));
        if (ans == 0)
            return;

        if (root->data > k)
            InorderTraversal(root->left, k, ans);

        if (root->data < k)
            InorderTraversal(root->right, k, ans);
    }
    int minDiff(Node *root, int K)
    {
        int ans = INT_MAX;
        InorderTraversal(root, K, ans);
        return ans;
    }
};

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        int k = stoi(s);

        Solution ob;
        cout << ob.minDiff(root1, k);
        cout << endl;
    }
    return 0;
}
