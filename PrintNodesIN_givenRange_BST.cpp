

#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    void solve(vector<int> &ans, Node *root, int low, int high)
    {
        if( root==NULL )
        {
            return;
        }
        if (root->data > low)
        {
            solve(ans, root->left, low, high);
        }
        if (root->data >= low && root->data <= high)
        {
            ans.push_back(root->data);
        }
        if (root->data < high)
        {
            solve(ans, root->right, low, high);
        }
        // solve(ans, root->left, low, high);
    }
    vector<int> printNearNodes(Node *root, int low, int high)
    {
        vector<int> ans;
        solve(ans, root, low, high);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int k1, k2;
        string s;
        getline(cin, s);
        scanf("%d ", &k1);
        scanf("%d ", &k2);
        Solution ob;
        Node *root = buildTree(s);
        vector<int> res = ob.printNearNodes(root, k1, k2);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 1;
}
