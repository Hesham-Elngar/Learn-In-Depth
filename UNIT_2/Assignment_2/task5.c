#include <stdio.h>
void Alphapet_or_not(char x)
{
    if((x>='A'&&x<='Z')||(x>='a'&&x<='z')) printf("%c is Alphapet\n",x);
    else printf("%c is not Alphapet\n",x);
}
int main()
{
    char a;
    printf("Enter character:");
    scanf("%c",&a);
    Alphapet_or_not(a);

    return 0;
}
