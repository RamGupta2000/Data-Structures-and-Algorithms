
#include <bits/stdc++.h>
using namespace std;

/*
    INPUT   1
            4 1 3 N N 3
    OUTPUT  7 4
*/


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

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

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

vector<int> diagonalSum(Node *root);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> res = diagonalSum(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 1;
}

vector<int> diagonalSum(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> v;

    while (!q.empty())
    {
        int sum = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            while (temp)
            {
                if (temp->left)
                    q.push(temp->left);
                sum += temp->data;
                temp = temp->right;
            }
        }
        v.push_back(sum);
    }
        return v;
}