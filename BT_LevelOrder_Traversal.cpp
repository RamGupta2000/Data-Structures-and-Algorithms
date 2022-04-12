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

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *newnode = q.front();
        q.pop();
        if (newnode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << newnode->data << " ";

            if (newnode->left != NULL)
            {
                q.push(newnode->left);
            }
            if (newnode->right != NULL)
            {
                q.push(newnode->right);
            }
        }
    }
}

int main()
{
    // list<int> l = {5, 7, 1, -1, -1, 3, 5, -1, -1, -1, 6, 7, -1, -1, -1};
    list<int> l = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};

    Node *root = NULL;
    root = createTree(l);
    cout << "Level Order Travesal : \n";
    LevelOrderTraversal(root);

    return 0;
}