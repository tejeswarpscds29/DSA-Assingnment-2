// 2. Balanced Parentheses

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char exp[MAX];
    int i;
    char ch;

    printf("Enter Expression: ");
    scanf("%s", exp);

    for(i = 0; i < strlen(exp); i++)
    {
        ch = exp[i];

        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == -1)
            {
                printf("Not Balanced");
                return 0;
            }

            char temp = pop();

            if((ch == ')' && temp != '(') ||
               (ch == '}' && temp != '{') ||
               (ch == ']' && temp != '['))
            {
                printf("Not Balanced");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}