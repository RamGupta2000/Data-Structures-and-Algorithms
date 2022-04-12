#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*newnode,*head,*temp;

int main()
{
    head==NULL;
    // cout<<newnode->data;
    int n;
    cout<<"Enter the No. of nodes you wanna insert : ";
    cin>>n;
    while (n)
    {
        if( head==NULL )
        {
            newnode = new node();
            cout<<"Enter Node data : ";
            int x;
            cin>>x;
            newnode->data=x;
            newnode->next=0;
            head=temp=newnode;
        }
        else
        {
            newnode = new node();
            cout<<"Enter Node data : ";
            int x;
            cin>>x;
            newnode->data=x;
            newnode->next=0;
            temp->next=newnode;
            temp=newnode;
        }

        n--;
    }
        temp=head;
        while( temp != 0 )
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    cout<<endl<<"Enter 1 to insert at beginning, 2 for end and 3 for position : ";
    int a;
    cin>>a;

    if( a==1 )
    {
        // Insertion at beginning

            cout<<endl<<"Enter Node data for insertion at beginning : ";
            int x;
            cin>>x;
            newnode = new node();
            newnode->data=x;
            newnode->next=0;
            temp=head;
            head=newnode;
            newnode->next=temp;

            temp=head;

            temp=head;
            while( temp !=0 )
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
    }

    if( a==2 )
    {
        // Insertion at end

            temp=head;
            while( temp->next != 0 )
            {
                temp=temp->next;
            }

            cout<<endl<<"Enter Node data for insertion at end : ";
            int x;
            cin>>x;
            newnode = new node();
            newnode->data=x;
            newnode->next=0;

            temp->next=newnode;

            temp=head;
            while( temp != 0 )
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
    }

    if( a==3 )
    {
        // Insertion at pos

            cout<<endl<<"Enter the position you wanna insert the node : ";
            int pos;
            cin>>pos;

            temp=head;
            for( int i=1; i<pos-1;i++ )
            {
                temp=temp->next;
            }

            cout<<endl<<"Enter Node data for insertion at end : ";
            int x;
            cin>>x;
            newnode = new node();
            newnode->data=x;
            newnode->next=0;

            newnode->next=temp->next;
            temp->next=newnode;

            temp=head;
            while( temp != 0 )
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
    }

    return 0;
}