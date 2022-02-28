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

void ReverseLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {

            Node *newnode = q.front();
            q.pop();

            s.push(newnode);
            
            if (newnode == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if (newnode->right != NULL)
                {
                    q.push(newnode->right);
                }
                if (newnode->left != NULL)
                {
                    q.push(newnode->left);
                }
            }
        }
    }
    while (!s.empty())
    {
        if (s.top() == NULL)
        {
            s.pop();
            cout << endl;
        }
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{
    // list<int> l = {5, 7, 1, -1, -1, 3, 5, -1, -1, -1, 6, 7, -1, -1, -1};
    list<int> l = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};

    Node *root = NULL;
    root = createTree(l);
    cout << "Level Order Travesal : \n";
    ReverseLevelOrderTraversal(root);

    return 0;
}