#include<stdio.h>
#include<stdlib.h>
int binary(int *arr,int low,int high,int value)
{
    if(low>high)
    {
        printf("Element not found");
        return -1;
    }
    int mid = (low+high)/2;
    if( arr[mid] == value)
    {
        printf("Element found in the array");
        return mid;
    }
    else if(arr[mid] > value)
    {
        binary(arr,low,mid-1,value);
    }
    else
    {
        binary(arr,mid+1,high,value);

    }
    
}

int main()
{
    int n,value;
    printf("Enter number of array elements:");
    scanf("%d",&n);
    int *arr =(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        printf("Enter elements %d " ,i);
        scanf("%d",&arr[i]);
    }
    printf("Enter search value:");
    scanf("%d",&value);
    int result =  binary(arr,0 ,n-1,value);
    printf("the position: %d",result);
    
}