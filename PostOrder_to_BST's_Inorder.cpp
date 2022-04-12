
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *constructTree(int[], int);

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int post[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);

        Node *root = constructTree(post, n);

        printInorder(root);
        printf("\n");
    }
    return 0;
}

Node *solve(int post[], int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    Node *root = new Node(post[mid]);

    root->left = solve(post, s, mid - 1);
    root->right = solve(post, mid + 1, e);

    return root;
}

Node *constructTree(int post[], int size)
{
    int r = post[size - 1];

    sort(post, post + size);
    Node *root = solve(post, 0, size - 1);
    return root;
}