#include <bits/stdc++.h>
using namespace std;

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

vector<int> Kdistance(struct Node *root, int k);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        int k;
        scanf("%d ", &k);
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = Kdistance(root, k);
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
vector<int> Level_at_Kdistance(Node *root, int k)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    int count = -1;
    while (!q.empty())
    {
        count++;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (count == k)
            {
                ans.push_back(temp->data);
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        if (count == k)
        {
            return ans;
        }
    }
}

vector<int> Kdistance(struct Node *root, int k)
{
    return Level_at_Kdistance(root, k);
}