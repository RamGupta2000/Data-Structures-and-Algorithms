#include <bits/stdc++.h>
using namespace std;

// Aditya verma - DP'series
// gfg 
//INCOMPLETE
// free ka tree - striver

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
    int maxpath(Node *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }
        // checking zero with returned value to avoid negative values...
        int L = maxpath(root->left, maxi);
        int R = maxpath(root->right, maxi);

        int temp = max(L, R) + root->data;
        if (!root->left && !root->right)
        {
            temp = max(temp, root->data);
        }
        int ans = max(temp, L + R + root->data);
        maxi = max(ans, maxi);
        return ans;
    }

    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        maxpath(root, maxi);
        return maxi;
    }
};

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}