#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter value you want to check:");
    scanf("%d",&a);
    if(0==a%2) printf("Even\n");
    else printf("Odd\n");

    return 0;
}