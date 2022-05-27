#include<stdio.h>
#include<ctype.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top=-1;

void push(int n);
int pop();
void eval_postfix(char postfix[]);

int main()
{
    char arr[POSTFIXSIZE];
    printf("Enter postfix expression : ");
    scanf("%s",arr);
    eval_postfix(arr);
    return 0;
}

void push(int n)
{
    if(top>=MAXSTACK-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

int pop()
{
    if(top==-1)
        printf("Stack underflow\n");
    else
        return stack[top--];
}

void eval_postfix(char postfix[])
{
    int A,B,val;
    char ch;

    for(int i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];

        //if it is a digit then push it to integer stack
        if(isdigit(ch))
            push(ch-'0');//Subtracting '0' to convert it to integer
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
        {
            B=pop();
            A=pop();
            switch(ch)
            {
                case '*':val=A*B;
                         break;
                case '+':val=A+B;
                         break;
                case '-':val=A-B;
                         break;
                case '/':val=A/B;
                         break;
                case '%':val=A%B;
                         break;
            }
            push(val);
        }
        else
        {
            printf("Invalid Operator or Operand\n");
            return;
        }
    }
    printf("Result of expression evaluation : %d\n",pop());
}