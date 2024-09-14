#include <stdio.h>
int is_prime(int x)
{
    int is_primee=1;
    for(int i=2;i<x;++i)
    {
        if(x%i==0)
        {
           is_primee = 0;
           break;
        }
    }
    return is_primee;
}
int main()
{
    int num1,num2;
    printf("Enter two numbers:");
    scanf("%d",&num1);
    scanf("%d",&num2);
    for(int i=num1;i<=num2;++i)
    {
        if(is_prime(i)) printf("%d ",i);
    }

    return 0;
}
