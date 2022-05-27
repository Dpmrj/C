#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;

//function protoypes
void insert(int n,int x);
int list_size();
int search_element(int n);
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
    printf("\n1.Search in a given data item in the list\n");
    printf("2.Insert a new node after a node\n");
    printf("3.Delete a node\n");
    printf("4.Print the list\n");
    printf("5.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter data to search in list : ");
               scanf("%d",&val);
               index=search_element(val);
               if(index==-1)
                    printf("%d not found in list\n",val);
               else
                    printf("%d found at index %d\n",val,index);
                break;
        case 2:printf("Enter data to insert in list : ");
               scanf("%d",&val);
               printf("Enter index after which you want to insert : ");
               scanf("%d",&index);
               insert(val,index);
               break;
        case 3:printf("Enter data to delete from list : ");
               scanf("%d",&val);
               delete_element(val);
               break;
        case 4:traverse_list();
               break;
        case 5:exit(0);
               break;
        default:printf("Wrong choice \n");
               break;
    }
  }
  free_list();
  return 0;
}

//inserts a new node after a node x
void insert(int n,int x)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->next=NULL;
        head->data=n;
        printf("\nSuccessfully inserted at head \n ");
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
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\nSuccessfully inserted node\n");
    }
}

//searches for an element in list
int search_element(int n)
{
    for(i=0,temp=head;temp!=NULL;temp=temp->next,i++)
    {
        if(temp->data ==n)
            return i;
    }
    return -1;
}

//delete a node from the list
void delete_element(int n)
{
    if(head==NULL)
        printf("\nCan't delete list is empty\n");
    else
    {
        int curr_node=search_element(n);
        if(curr_node==-1)
        {
            printf("\nDidn't found a node having data %d\n",n);
            return;
        }
        else if(curr_node==0)
        {
            temp=head;
            head=head->next;
            free(temp);
            printf("\nSuccessfully deleted node having data %d from the list\n ",n);
        }
        else
        {
            for(temp=head;temp->next->data!=n;temp=temp->next);
            node *curr=temp->next;
            temp->next=curr->next;
            free(curr);
            printf("\nSuccessfully deleted node having data %d from the list\n ",n);
        }
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
            printf("%-6d",temp->data);
        printf("\n");
    }
}