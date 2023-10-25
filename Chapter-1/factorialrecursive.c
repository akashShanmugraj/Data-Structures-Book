#include<stdio.h>
int find_actorial(int n){
    if(n==1){
        //base case
        return 1;
    }
    else{
        //general or recursive case
        return n*find_factorial(n-1);
    }
}
int main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("%d",find_factorial(n));  
}