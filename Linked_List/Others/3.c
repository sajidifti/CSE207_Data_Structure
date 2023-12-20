#include <stdio.h>
#include <stdlib.h>
#define bool int

bool isMatchingPair(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')')
        return 1;
    else if (ch1 == '{' && ch2 == '}')
        return 1;
    else if (ch1 == '[' && ch2 == ']')
        return 1;
    else
        return 0;
}

void bracket(char exp[])
{
    int i = 0;

    struct Node *newNode = NULL;

    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&newNode, exp[i]);

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {

            if (newNode == NULL)
                printf("false");

            else
            {

                if (pop(&newNode) == '(' && exp[i]) == ')')
                    printf("true");
                else if (pop(&newNode) == '{' && exp[i]) == '}')
                    printf("true");
                else if (pop(&newNode) == '[' && exp[i]) == ']')
                    printf("true");
                else
                    printf("false");
            }
        }
        i++;
    }

    if (newNode == NULL)
        printf("true");
    else
        printf("false");
}