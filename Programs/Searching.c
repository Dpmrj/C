#include<stdio.h>

//function prototypes
int bSearch(int arr[],int l,int r,int num);
int lSearch(int arr[],int size,int num);
void input(int arr[],int size);

int main()
{
    int size,ch,index,num;
    printf("Enter size of array :");
    scanf("%d",&size);
    int arr[size];
    input(arr,size);
    printf("Enter any no. to search :");
    scanf("%d",&num);
    printf("\nSelect searching algorithm  \n");
    printf("\n1.Linear Search\n");
    printf("2.Binary Search\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:index=lSearch(arr,size,num);
               break;
        case 2:index=bSearch(arr,0,size,num);
               break;
        default:printf("Wrong choice \n");
                return 1;
    }
    if(index==-1)
        printf("\n%d is not found..\n",num);
    else
        printf("\n%d is found at index :%d\n",num,index);
    return 0;
}

//
int bSearch(int arr[],int l,int r,int num)
{
        if(r>=l)               //Condition to quit
        {
            int mid=l+(r-l)/2;
            if(arr[mid]==num)
                return mid;
            else if(arr[mid]>num)
                return bSearch(arr,l,mid-1,num);
            else
                return bSearch(arr,mid+1,r,num);
        }
        return -1;
}

int lSearch(int arr[],int size,int num)
{
    for(int i=0;i<size;i++)
        if(arr[i]==num)
            return i;
    return -1;
}

//grants user to enter array elements
void input(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
      printf("Enter %d element :",i+1);
      scanf("%d",&arr[i]);
    }
}