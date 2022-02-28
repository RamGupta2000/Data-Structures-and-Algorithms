
#include <bits/stdc++.h>
using namespace std;

/*
    INPUT   1
            3 1 2
            
    OUTPUT  1
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

class Solution
{
public:
    pair<bool, int> Sum_IsSumTree(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> left = Sum_IsSumTree(root->left);
        pair<bool, int> right = Sum_IsSumTree(root->right);

        bool isleftSumTree = left.first;
        bool isrightSumTree = right.first;

        bool isSum = ( root->data == left.second + right.second );

        pair<bool, int> ans;

        if (isleftSumTree && isrightSumTree && isSum)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first=false;
        }
        return ans;
    }

    bool isSumTree(Node *root)
    {
        return Sum_IsSumTree(root).first;
    }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.isSumTree(root) << endl;
    }
    return 1;
}