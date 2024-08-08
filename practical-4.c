#include<stdio.h>
#include<conio.h>
#include<ctype.h>
//Above the ctype.h header file will be used for the header file declares a set of functions to classify (and transform) individual characters.
//For example, isupper() checks whether a character is uppercase or not.

char stack[100];
int top = -1;

//Here, I have create mainly 3 functions PUSH,POP,Priority.
//Push function will be check that if the Stack is empty or not.
//If the stack will empty then one element will be insert in the stack. Else message shows that Stack is Overflow.
void push(char x)
{
    stack[++top] = x;
}

//Pop fucntion will be check that is their any element available in the Stack or not.
//If is their any elemnet in the stack then that element will be delete and insert the symbol of any expression sign in the stack. Else message shows that Stack is Underflow.
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

//Priority will be check that which elements priority has high or low as per Data Sturcture 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
