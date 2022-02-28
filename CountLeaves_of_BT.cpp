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

void leafCount(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
        return;
    }
    leafCount(root->left, count);
    leafCount(root->right, count);
}

int main()
{
    // list<int> l = {5, 7, 1, -1, -1, 3, 5, -1, -1, -1, 6, 7, -1, -1, -1};
    // list<int> l = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, -1};
    list<int> l = {1, 2, -1, -1, 4, -1, -1};

    Node *root = NULL;
    root = createTree(l);
    int count = 0;
    leafCount(root, count);
    cout << count;

    return 0;
}