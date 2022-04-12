#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the Node data : ";
    int x;
    cin >> x;
    Node *newnode = new Node(x);

    if (newnode->data == 0)
    {
        return 0;
    }
    cout << "Enter the left child of " << x << ": ";
    newnode->left = createTree();

    cout << "Enter the right child of " << x << ": ";
    newnode->right = createTree();

    return newnode;
}

void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

int main()
{
    Node *root = NULL;
    root = createTree();

    cout << "\nInorder Travesal : ";
    InorderTraversal(root);

    return 0;
}