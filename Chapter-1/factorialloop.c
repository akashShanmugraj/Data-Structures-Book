#include<stdio.h>
int find_factorial(int n){
    //n is the number for which the factorial is found
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial*=i;
    }
    return factorial;
}
int main(){
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("%d",find_factorial(n));  
}