#include<stdio.h>
#include<string.h>
#define MAX 100

typedef struct
{
    char stk[MAX][MAX];
    int top;
}stack;

stack s;
char pfix[MAX];

void push(char str[])
{
    s.top++;
    strcpy(s.stk[s.top], str);
}

char* pop()
{
    return (s.stk[s.top--]);
}

void conv()
{
    char op1[MAX], op2[MAX], sym[2], res[MAX];
    int i;
    printf("Enter valid prefix expression: ");
    scanf("%s",pfix);
    int len=strlen(pfix);

    for(i=len-1; i>=0; i--)
    {
        sym[0]=pfix[i]; sym[1]='\0';
        if(sym[0]=='+' || sym[0]=='-' || sym[0]=='*' || sym[0]=='/')
        {
            strcpy(op1, pop());
            strcpy(op2, pop());

            strcpy(res,op1);
            strcat(res,op2);
            strcat(res,sym);

            push(res);
        }
        else
            push(sym);
    }
    printf("%s", pop());


}

int main()
{
    char ch;
    do{
        s.top=-1;
        conv();
        printf("\nDo another one(y/n): ");
        scanf("%s", &ch);
    }while(ch=='y');
    return 0;
}
