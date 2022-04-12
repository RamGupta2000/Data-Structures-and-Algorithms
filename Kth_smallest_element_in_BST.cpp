
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
    void InorderTraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        InorderTraversal(root->left, ans);
        ans.push_back(root->data);
        InorderTraversal(root->right, ans);
    }
    int KthSmallestElement(Node *root, int K)
    {
        vector<int> ans;
        InorderTraversal(root, ans);
        sort(ans.begin(), ans.end());
        
        if (K > ans.size())
            return -1;
        
        return ans[K-1];
    }
};

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
        Node *root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);

        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
    }
    return 0;
}