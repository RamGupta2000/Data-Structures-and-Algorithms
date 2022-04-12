#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void create(node *&head, node *&temp, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void insert_beg(node *&head)
{
    int data;
    cout << "Enter the data you wanna insert at beginning : ";
    cin >> data;
    node *newnode = new node(data);

    newnode->next = head;
    head = newnode;
}

void delete_beg(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void insert_end(node *&head)
{
    int data;
    cout << "Enter the data you wanna insert at end : ";
    cin >> data;
    node *newnode = new node(data);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at_pos(node *&head)
{
    int data, pos;
    cout << "Enter the pos at whcih you wanna insert : ";
    cin >> pos;
    cout<< "Enter the data you wanna insert at pos " << pos << ": ";
    cin >> data;
    node *newnode = new node(data);

    node *temp = head;
    node *prev = temp;

    for (int i = 0; i < pos - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
}

void delete_end(node *&head)
{
    node *temp = head;
    node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = 0;
    delete temp;
}

void displaylist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void delete_at_pos(node *&head)
{
    int pos;
    cout << "Enter the pos from whcih you wanna delete : ";
    cin >> pos;

    node *temp = head;
    node *prev = temp;

    for (int i = 0; i < pos - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
}

int main()
{
    node *head = NULL;
    node *temp = NULL;

    cout << "Enter the no. of nodes you wanna create in LL : ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter node data :";
        cin >> data;
        create(head, temp, data);
    }

    displaylist(head);

    // // Insertion
    // insert_beg(head);
    // insert_end(head);
    insert_at_pos(head);

    // //Deletion
    // delete_beg(head);
    // delete_end(head);
    // delete_at_pos(head);

    displaylist(head);
    
    return 0;
}