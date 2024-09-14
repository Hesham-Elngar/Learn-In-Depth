#include <stdio.h>
int get_max(int x,int y,int z)
{
    if(x>y)
    {
        if(x>z) return x;
        else return z;
    }
    return y;

}
int main()
{
    int a,b,c;
    printf("Enter Number1:");
    scanf("%d",&a);
    printf("Enter Number2:");
    scanf("%d",&b);
    printf("Enter Number3:");
    scanf("%d",&c);
    int x = get_max(a,b,c);
    printf("%d",x);

    return 0;
}
