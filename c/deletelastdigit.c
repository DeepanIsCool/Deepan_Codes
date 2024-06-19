#include<stdio.h>
 int main(){
    int n;
    printf("Enter a num: ");
    scanf("%d",&n);
    int ld = n - ((n/10) * 10);
    printf("Last Digit: %d\n",ld);
    printf("New Numer: %d\n", (n-ld)/10 );
    return 0;
 }