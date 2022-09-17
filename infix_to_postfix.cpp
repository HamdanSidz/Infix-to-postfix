#include <iostream>
using namespace std;

int precedence(char val)
{
    if (val == '^')
    {
        return 3;
    }
    else if ((val == '*') || (val == '/') || (val == '%'))
    {
        return 2;
    }
    else if ((val == '+') || (val == '-'))
    {
        return 1;
    }
    return 0;
}

int isoperator(char val)
{
    if ((val == '+') || (val == '-') || (val == '*') || (val == '/') || (val == '%') || (val == '^'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix(char *infix, int a)
{

    char stack[a];
    char postfix[a];
    int top = -1;
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {

        if (isoperator(infix[i]) == 1)
        {
            if (stack[top] != -1)
            {
                while (precedence(infix[i]) <= precedence(stack[top]))
                {
                    postfix[j++] = stack[top];
                    top--;
                }

                top++;
                stack[top] = infix[i];
            }
            else
            {
                stack[++top] = infix[i];
            }
        }

        else if (isoperator(infix[i]) == 0)
        {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top];
                top--;
            }
            top--;
        }

        else if (infix[i] == '(')
        {
            top++;
            stack[top] = infix[i];
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j++] = stack[top];
        top--;
    }

    for (int i = 0; i < sizeof(postfix); i++)
    {
        cout << postfix[i];
    }
    cout << endl;
}

main()
{

    int a;
    cout << " enter no.of elements in your equation: " << endl;
    cin >> a;
    char infix[a];
    char b;

    for (int i = 0; i < a; i++)
    {
        cout << "Enter equation element: " << endl;
        cin >> b;
        infix[i] = b;
    }

    infix_to_postfix(infix, a);
}
