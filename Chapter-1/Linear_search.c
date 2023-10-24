#include<stdio.h>
#include<stdlib.h>
int Linear_Search(int *arr,int element,int n)
{
    int i ,index = -1;
    for(i = 0; i < n; i++) 
    {
        if(arr[i] == element)
        {
           index = i;
           break;
        }
    }
    return index ;
}
int main()
{
    int n,i,element;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int * arr = (int *) malloc(sizeof(int) * n);
    for(i = 0;i<n;i++)
    {
        printf("Element :");
        scanf("%d",&arr[i]);
    }
    printf("Enter Search Element: ");
    scanf("%d",&element);
    int result = Linear_Search(arr,element,n);
    if(result != -1)
    {
        printf("The search element is found at the %d th position in the array",result);
    }
    else
    {
        printf("The element search was not found");
    }
}