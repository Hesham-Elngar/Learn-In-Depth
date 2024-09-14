#include <stdio.h>
void postive_or_negative(int x)
{
    if(x>0) printf("Postive");
    else if(x<0) printf("Negative");
    else printf("you entered zero");

}
int main()
{
    int a,b,c;
    printf("Enter Number1:");
    scanf("%d",&a);
    postive_or_negative(a);

    return 0;
}
