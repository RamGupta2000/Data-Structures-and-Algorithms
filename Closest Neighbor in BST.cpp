
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->key = val;
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

int findMaxForN(Node *root, int N);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;

        Node *root = buildTree(s);
        cout << findMaxForN(root, x) << endl;
    }
    return 1;
}

void solve(Node *root, int n, int &ans)
{
    if (!root)
        return;
    if (root->key <= n)
        ans = max(ans, root->key);
    if (n < root->key)
        solve(root->left, n, ans);
    if (n > root->key)
        solve(root->right, n, ans);
        cout<<"abv\n";
}

int findMaxForN(Node *root, int n)
{
    int ans = 0;
    solve(root, n, ans);
    return ans;
}