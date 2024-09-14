#include <stdio.h>
int power(int base,int _power)
{
   if (_power == 0) return 1;
    return (base * power(base,_power-1));
}
int main()
{
    int x,_power;
    scanf("%d",&x);
    scanf("%d",&_power);
    int w= power(x,_power);
    printf("%d",w);

    return 0;
}
