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

Node *createTree(list<int> &l)
{
    Node *newnode = new Node(l.front());
    if (newnode->data == -1)
    {
        return 0; 
    }
    l.pop_front();
    newnode->left = createTree(l);

    l.pop_front();
    newnode->right = createTree(l);

    return newnode;
}

void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int main()
{
    list<int> l = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};

    Node *root = NULL;
    root = createTree(l);
    cout << "Preorder Travesal : ";
    PreorderTraversal(root);

    return 0;
}