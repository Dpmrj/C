#include<stdio.h>

//function prototypes
void input(int arr[],int size);
void insertionSort(int arr[],int size);
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
void print(int arr[],int size);

int main()
{
    int size,ch,index;
    printf("Enter size of array :");
    scanf("%d",&size);
    int arr[size];
    input(arr,size);
    printf("\nSelect sorting algorithm  \n");
    printf("\n1.Insertion Sort\n");
    printf("2.Quick Sort\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insertionSort(arr,size);
               break;
        case 2:quickSort(arr,0,size-1);
               break;
        default:printf("Wrong choice \n");
                return 1;
    }
    printf("\nAfter sorting \n");
    print(arr,size);
    return 0;
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

void insertionSort(int arr[],int size)
{
    int i,j,key;
    for(i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//performs partition on array
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//swap values of two variables
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//prints the array
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
      printf("%d  ",arr[i]);
    }
    printf("\n");
}