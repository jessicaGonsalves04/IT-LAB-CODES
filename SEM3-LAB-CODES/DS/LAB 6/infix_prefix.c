#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct{
    int arr[MAX];
    int top;
}stack;

stack s;

char pfix[40],infix[MAX];
void push(char symbol){
    if(s.top==MAX-1){
        printf("Stack is full.\n");
        return;
    }
    else
    s.arr[++s.top]=symbol;
}
char pop(){
    if(s.top==-1){
        printf("Stack Underflow\n");
        return'#';
    }
    else return s.arr[s.top--];
}


void read (){
    printf("Enter the infix expression:  ");
    fflush(stdin);
    gets(infix);
}

int isNotEmpty(){
    if(s.top==-1)
    return 0;
    else
    return 1;
}
int prec(char symbol){
    switch (symbol){
        case'/':
        case'*':
            return 3;
        case'+':
        case'-':
            return 2;
        case')':
            return 0;
        default:
            return-1;
         }
}
void convert(){
    char temp;
    int i,p;
    p=0;
    s.top=-1;
    char e1,e2;
    int l =strlen(infix);
    for(i=0;i<=l/2;i++)
    {
        temp=infix[i];
        infix[i]=infix[l-i-1];
        infix[l-i-1]=temp;
    }
    for(i=0;infix[i]!='\0';i++)
    {
        e1=infix[i];
        switch(e1){
            case ')':
            push(e1);
            break;
            case'(':
            while((e2=pop())!=')')
            pfix[p++]=e2;
            break;
        case'+':
        case'-':
        case'*':
        case'/':
        while(isNotEmpty()&& prec(e1)<prec(s.arr[s.top]))
          { e2= pop();
           pfix[p++]=e2;
           }
           push(e1);
        break;
        default:
        pfix[p++]=e1;
        break;
        }

    }
    while(isNotEmpty()){
        pfix[p++]=pop();
        }
        pfix[p]='\0';
        int l2=strlen(pfix);
        printf("The prefix expression is:");
        for(i=l2-1;pfix[i]>=0;i--)
        printf("%c",pfix[i]);
}

int main(){
    char ch;
    do{
        read();
        convert();
        printf("\nDo you want to continue(y/n)?\n");
        scanf("%c",&ch);

    }while(ch=='y');
    return 0;
}