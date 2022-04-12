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

int Height_of_Binary_Tree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSubtreeHeight = Height_of_Binary_Tree(root->left);
    int rightSubtreeHeight = Height_of_Binary_Tree(root->right);

    int height = (max(leftSubtreeHeight, rightSubtreeHeight) + 1);

    return height;
}

int main()
{
    Node *root = NULL;
    root = createTree();
    cout << "Height of Binary Tree is : " <<Height_of_Binary_Tree(root);
    return 0;
}