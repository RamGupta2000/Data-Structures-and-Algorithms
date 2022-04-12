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

void PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = createTree();

    cout << "\nPostorder Travesal : ";
    PostorderTraversal(root);

    return 0;
}