#include <bits/stdc++.h>
using namespace std;
/*
        1
        1 2 3 4 5 6 7 N N N N N 8 N 9
        
        4 2 1 5 6 3 8 7 9
*/
struct Node
{
    int data;
    Node *left;
    Node *right;
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

void printInorder(Node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> p = q.front();
            q.pop();

            Node *temp = p.first;
            int HD = p.second.first; // HD : HorizontalDistance
            int level = p.second.second;

            nodes[HD][level].push_back(temp->data);

            if (temp->left)
                q.push(make_pair(temp->left, make_pair(HD - 1, level + 1)));

            if (temp->right)
                q.push(make_pair(temp->right, make_pair(HD + 1, level + 1)));
        }
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);

        Solution obj;
        Node *root = buildTree(s);

        vector<int> res = obj.verticalOrder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
