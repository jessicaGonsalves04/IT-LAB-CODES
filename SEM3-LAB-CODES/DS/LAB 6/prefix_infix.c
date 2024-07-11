#include <stdio.h>
#include<string.h>
#define MAX 50

typedef struct {
    char stk[50][50];
    int top;
} stack;

stack s;

char pfix[MAX];

void push(char str[]){
++s.top;
strcpy(s.stk[s.top],str);
}

char* pop()
{
    return s.stk[s.top--];
}

void prefix_infix(){
    char op1[20],op2[20],sym[2],res[20];
    printf("Enter a valid prefix expression:");
    fflush(stdin);
    gets(pfix);
    int l= strlen(pfix);
    for(int i=l-1 ; i>= 0;i--){
        sym[0]=pfix[i];
        sym[1]='\0';//pass as a string
        if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/')
        {
            strcpy(op2,pop());
            strcpy(op1,pop());
            strcpy(res,")");
            strcat(res,op1);
            strcat(res,sym);
            strcat(res,op2);
            strcat(res,"(");
            push (res);
        }
        else
        push(sym);
    }

if(s.top!=0){
    printf("Not a proper prefix expression.");
    return;
}
printf("Infix expression is:");
int l2 =strlen(res);
for(int i=l2-1;i>=0;i--){
    printf("%c",res[i]);
}

}
int main() {
    char ch;
    do{
    s.top=-1;
        prefix_infix();
        printf("\nDo you want to continue(y/n)?");
        scanf("%c",&ch);
    }while(ch=='y');
    return 0;
}