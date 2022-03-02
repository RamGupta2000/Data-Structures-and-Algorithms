
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/*
    1
    4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8

    4 10 5 6 8 11 3 5 8 8 6 11 11   
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

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

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    void leftpart(Node *root, vector<int> &ans)
    {
        if ( (root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left)
            leftpart(root->left, ans);
        else
            leftpart(root->right, ans);
    }

    void leafNodes(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }

    void rightpart(Node *root, vector<int> &ans)
    {
        if ( (root == NULL) || (root->left == NULL && root->right == NULL))
        {
            return;
        }
        
        if (root->right)
            rightpart(root->right, ans);
        else
            rightpart(root->left, ans);

        ans.push_back(root->data); 
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if( root==NULL )
        {
            return ans;
        }
        ans.push_back(root->data);
        leftpart(root->left, ans);
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
        rightpart(root->right, ans);
        return ans;
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
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundary(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}