#include <bits/stdc++.h>
using namespace std;

// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 7 -1 -1

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
    // cout << "Enter the Node data : ";
    int x;
    cin >> x;
    Node *newnode = new Node(x);

    if (newnode->data == -1)
    {
        return 0;
    }
    // cout << "Enter the left child of " << x << ": ";
    newnode->left = createTree();

    // cout << "Enter the right child of " << x << ": ";
    newnode->right = createTree();

    return newnode;
}

void Iterative_PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();

        cout << temp->data << " ";
        if (temp->right)
        {
            s.push(temp->right);
        }
        if (temp->left)
        {
            s.push(temp->left);
        }
    }
}
void Iterative_InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s;
    Node *temp = root;

    while (1)
    {
        if (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

void Iterative_PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);
        if( temp->left )
        {
            s1.push(temp->left);
        }
        if( temp->right )
        {
            s1.push(temp->right);
        }
    }
    while( !s2.empty() )
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = createTree();

    cout << "\nPreorder Travesal  : ";
    Iterative_PreorderTraversal(root);

    cout << "\nInorder Travesal   : ";
    Iterative_InorderTraversal(root);

    cout << "\nPostorder Travesal : ";
    Iterative_PostorderTraversal(root);

    return 0;
}