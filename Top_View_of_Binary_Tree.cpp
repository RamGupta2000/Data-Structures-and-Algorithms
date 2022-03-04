

#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        map<int, int> mp;
        while (!q.empty())
        {
            Node *temp = q.front().first;
            int d = q.front().second;
            q.pop();

            if (mp.find(d) == mp.end())
            {
                mp[d] = temp->data;
            }

            if (temp->left)
                q.push({temp->left, d - 1});

            if (temp->right)
                q.push({temp->right, d + 1});
        }
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second);
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(256, '\n');
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}