#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

//function protoypes
void insert(int n,int x);
int list_size();
void traverse_list();
void free_list();
void delete_element(int n);

//global variables
int i;
node* head=NULL;
node* temp;

int main()
{
    int ch,val,index;
    while(1)
    {
        printf("\n1.Insert a new node after a node\n");
        printf("2.Delete a specified non terminal node from list having at least 3 nodes\n");
        printf("3.Print the list\n");
        printf("4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter data to insert in list : ");
                scanf("%d",&val);
                printf("Enter index after which you want to insert : ");
                scanf("%d",&index);
                insert(val,index);
                break;
            case 2:printf("Enter node(index) to delete from list : ");
                scanf("%d",&index);
                delete_element(index);
                break;
            case 3:traverse_list();
                break;
            case 4:exit(0);
                break;
            default:printf("Wrong choice \n");
                break;
        }
    }
    free_list();
    return 0;
}

//inserts a new node
void insert(int n,int x)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->next=NULL;
        head->prev=NULL;
        head->data=n;
        printf("\nSuccessfully inserted at head\n ");
    }
    else if(x>list_size()-1)
    {
        printf("\nNode %d doesn't exist in list\n",x);
        return;
    }
    else
    {
        for(i=0,temp=head;i<x;i++,temp=temp->next);
        node* newnode=(node *)malloc(sizeof(node));
        newnode->data=n;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\nSuccessfully inserted node\n");
    }
}

//delete a node from the list(at least size 3) except terminal ones
void delete_element(int n)
{
    int size=list_size();
    if(head==NULL)
        printf("\nCan't delete list is empty\n");
    else if(size<3)
        printf("\nCan't delete : list size is less than 3\n");
    else if(n==(size-1)||n==0)
        printf("\nCan't delete terminal nodes\n");
    else if(size<n)
        printf("\nNode %d doesn't exist in list\n",n);
    else
    {
        for(i=0,temp=head;i<n;temp=temp->next,i++);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("\nSuccessfully deleted node %d from the list\n ",i);
    }
}

//returns size of list
int list_size()
{
    int count=0;
    for(temp=head;temp!=NULL;temp=temp->next)
        count++;
    return count;
}

//frees the list nodes
void free_list()
{
    while(head!=NULL)
    {
        temp=head->next;
        free(head);
        head=temp;
    }
}

//traverses through the list
void traverse_list()
{
    if(head==NULL)
        printf("\nList is empty \n");
    else
    {
        for(temp=head;temp!=NULL;temp=temp->next)
            printf("%-2d",temp->data);
        printf("\n");
    }
}