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

void LevelOrderTraversal(Node* &root)
{
    queue<Node *> q;
    int data;
    cout << "Enter Root data : " << endl;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {   
        Node *temp=q.front();
        q.pop();

        cout << "Enter left child of "<< temp->data<<" : ";
        int leftchild;
        cin>>leftchild;
        
        if (leftchild!=-1)
        {
            temp->left=new Node(leftchild);
            q.push(temp->left);
        }
        
        cout << "Enter right child of "<< temp->data<<" : ";
        int rightchild;
        cin>>rightchild;
        
        if (rightchild!=-1)
        {
            temp->right=new Node(rightchild);
            q.push(temp->right);
        }
        
    }
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
    LevelOrderTraversal(root);
    cout<<endl;
    InorderTraversal(root);

    return 0;
}
