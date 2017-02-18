
/*Sagar Gujarati*/
#include<stdio.h>
#include<conio.h>
#define max 25
int stc[max];
int top=-1;
void push(char symbol)
{
    top=top+1;
    stc[top]=symbol;
}
char pop()
{
    char k;
    k=stc[top];
    top=top-1;
    return k;
}
int isoperand(char symbol)
{
    if(symbol>='a' && symbol<='z')
        return 1;
    else
        return 0;
}
int isoperator(char symbol)
{
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/'  )
        return 1;
    else
        return 0;
}
int priority(char symbol)
{
    int result;
    switch(symbol)
    {
        case '(': result=0;break;
        case '+':
        case '-':result=1;break;
        case '*':
        case '/':result=2;break;
    }
    return result;
}
int main()
{
char infix[max],postfix[max];
int i,j,temp;
i=j=0;
char symbol;
printf("\nEnter infix notation:");
scanf("%s",&infix);
push('(');
while(infix[i]!='\0')
{symbol=infix[i];
    if(isoperand(symbol))
    {
        postfix[j]=symbol;
        j=j+1;

    }
    if(symbol=='(')
    {
        push(symbol);
    }
    if(isoperator(symbol))
    {
        while(priority(stc[top])>=priority(symbol))
        {
            temp=pop();
            postfix[j]=temp;
            j=j+1;
        }
        push(symbol);
    }
    if(symbol==')')
    {
        while(stc[top]!='(')
        {
            temp=pop();
            postfix[j]=temp;
            j=j+1;
        }
        temp=pop();
    }
    i=i+1;
}
while(stc[top]!='(')
{
    temp=pop();
    postfix[j]=temp;
    j=j+1;
}
postfix[j]='\0';
printf("\nPostfix is: %s\n",postfix);
getch();
return 0;
}
