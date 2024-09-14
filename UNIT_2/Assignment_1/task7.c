#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y)
{
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}
int main()
{
    float a,b;
    printf("Enter value of a:");
    scanf("%f",&a);
    printf("Enter value of b:");
    scanf("%f",&b);
    swap(&a,&b);
    printf("After swapping, value of a = %f\n",a);
    printf("After swapping, value of b = %f\n",b);
    return 0;
}
/*
EX7:
it is an interview trick
Write Source Code to Swap Two Numbers without temp variable.*/
