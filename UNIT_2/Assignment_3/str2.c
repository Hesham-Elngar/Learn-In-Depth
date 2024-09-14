#include <stdio.h>
int main()
{
    char str[50];
    int length=0;
    printf("Enter String:");
    scanf("%[^\n]s",str);
    for(int i=0;str[i]!='\0';i++)
    {
        ++length;
    }
    printf("length of string: %d",length);
    return 0;
}
