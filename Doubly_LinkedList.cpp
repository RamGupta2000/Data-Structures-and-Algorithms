#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void create(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev=tail;
        tail = newnode;
    }
}

void insert_beg(node *&head )
{
    int data;
    cout << "Enter the data you wanna insert at beginning : ";
    cin >> data;
    node *newnode = new node(data);

    newnode->next = head;
    head->prev=newnode;
    head = newnode;
}


void insert_end(node *&tail)
{
    int data;
    cout << "Enter the data you wanna insert at end : ";
    cin >> data;
    node *newnode = new node(data);

    
    tail->next = newnode;
    newnode->prev=tail;
    tail=newnode;
}

void insert_at_pos(node *&head)
{
    int data, pos;
    cout << "Enter the pos at which you wanna insert : ";
    cin >> pos;
    cout<< "Enter the data you wanna insert at pos " << pos << ": ";
    cin >> data;
    node *newnode = new node(data);

    node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->prev=temp->prev;
    newnode->next = temp;
    temp->prev->next=newnode;
    temp->prev=newnode;
}

void delete_beg(node *&head)
{
    node *temp = head;
    head = head->next;
    head->prev=NULL;
    delete temp;
}

void delete_end(node *&tail)
{
    node* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
}


void delete_at_pos(node *&head)
{
    int pos;
    cout << "Enter the pos from which you wanna delete : ";
    cin >> pos;

    node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    // node *del = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void displaylist(node *head, node *tail )
{
    node *temp = head;
    while (temp != tail ) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout << endl;
}

void reverse( node *&head, node *&tail )
{
    node* temp=head;
    node* pre=NULL;

    while( temp!=NULL )
    {
        temp->prev=temp->next;
        temp->next=pre;
        pre=temp;
        temp=temp->prev;
    }
    head=pre;

    temp=head;
    while( temp->next!=NULL )
    {
        temp=temp->next;
    }
    tail=temp;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    cout << "Enter the no. of nodes you wanna create in LL : ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter node data :";
        cin >> data;
        create(head, tail, data);
    }

    displaylist(head,tail);

    // // Insertion
    // insert_beg(head);
    // insert_end(tail);
    // insert_at_pos(head);

    // //Deletion
    // delete_beg(head);
    // delete_end(tail);
    // delete_at_pos(head);

    // displaylist(head,tail);
    reverse(head,tail);
    displaylist(head,tail);
    return 0;
}