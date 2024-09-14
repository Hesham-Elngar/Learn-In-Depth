#include <stdio.h>

float calc(char operator,float op1,float op2)
{
    switch(operator)
    {
    case '-':
     return op1 - op2;
    case '+':
     return op1 + op2;
    case '*':
     return op1 * op2;
    case '/':
     return op1 / op2;
    }
}

int main()
{
    char ch;
    float num1,num2;
    printf("Enter operator either + or - or /:");
    scanf("%c",&ch);
    printf("Enter two operands:");
    scanf("%f",&num1);
    scanf("%f",&num2);
    float result = calc(ch,num1,num2);
    printf("%f",result);
    return 0;
}
