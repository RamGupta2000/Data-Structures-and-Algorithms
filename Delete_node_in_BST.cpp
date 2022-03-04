
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

struct Node *deleteNode(struct Node *root, int key);

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

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
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
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
Node *findInorderSuccessor(Node *root)
{
    while( root && root->left )
    {
        root=root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data < X)
    {
        root->right = deleteNode(root->right, X);
    }
    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
    }
    else
    {
        if (root->data == X && !root->left && !root->right)
        {
            return NULL;
        }

        else if (root->data == X && root->left && !root->right)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }

        else if (root->data == X && !root->left && root->right)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }

        if (root->data == X && root->left && root->right)
        {
            Node *temp = findInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
