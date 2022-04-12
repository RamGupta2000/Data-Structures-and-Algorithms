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

float findMedian(struct Node *node);

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
        Node *root = buildTree(s);

        cout << findMedian(root) << endl;
    }
    return 0;
}

void InorderTraversal(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left, v);
    v.push_back(root->data);
    InorderTraversal(root->right, v);
}

float findMedian(struct Node *root)
{
    vector<int> v;
    InorderTraversal(root, v);

    if (v.size() % 2 != 0)
    {
        return (float)v[v.size() / 2];
    }
    else
    {
        int mid = v.size() / 2;
        float ans = v[mid] + v[mid - 1];
        return ans;
    }
}