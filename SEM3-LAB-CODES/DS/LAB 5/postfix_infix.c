#include <stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
    char stk[50][50];
    int top;
} stack;

stack s;
char pfix[50];

void push(char str[]){
++s.top;
strcpy(s.stk[s.top],str);
}
char* pop()//we use *to return a string
{
    return s.stk[s.top--];
}

void post_infix(){
    char op1[20],op2[20],sym[2],res[20];
    printf("Enter a valid postfix expression:");
    gets(pfix);
    //fflush(stdin);
    for(int i=0;pfix[i]!='\0';i++){
        sym[0]=pfix[i];
        sym[1]='\0';//pass as a string
        if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/')
        {
            strcpy(op2,pop());
            strcpy(op1,pop());
            strcpy(res,"(");
            strcat(res,op1);
            strcat(res,sym);
            strcat(res,op2);
            strcat(res,")");
            push (res);
        }
        else
        push(sym);
    }


if(s.top!=0){
    printf("Not a proper postfix expression.");
    return;
}
printf("Infix expression is:");
puts(s.stk[s.top]);

}
int main() {
    char ch;
    s.top=-1;
        post_infix();
    return 0;
}
