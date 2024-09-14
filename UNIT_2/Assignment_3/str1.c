#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[50];
    char char_freq[26]={};
    printf("Enter String:");
    scanf("%[^\n]s",str);
    int length = strlen(str);
    strupr(str);
    for(int i = 0; i < length; i++)
    {
        if (isalpha(str[i]))
        ++char_freq[str[i]-'A'];
    }
    char ch;
    printf("Enter character to find frequency:");
    scanf(" %c",&ch);
    ch = toupper(ch);
    printf("frequency of %c = %d:",ch,char_freq[ch-'A']);

    return 0;
}
