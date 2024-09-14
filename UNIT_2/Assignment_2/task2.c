#include <stdio.h>
#include <stdbool.h>
bool check_vowel_Or_Const(char ch)
{
    switch(ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("vowel");
        return;
    }
    printf("Constant");
}
int main()
{
    char a;
    printf("Enter character you want to check:");
    scanf("%c",&a);
    bool x = check_vowel_Or_Const(a);

    return 0;
}
