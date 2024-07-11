#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} stack;

stack s;

void push(char c[]) {
    strcpy(s.arr[++s.top],c);
    }
   

void  pop() {
    if (s.top == -1) {
        printf("Stack underflow.");
        return '\0'; 
    }
    s.top--;
}
int main(){
    char str [MAX],sym[2],tag[100;
    int flag=1;
    s.top=-1;
    printf("Enter expression(#to end)\n");
    fflush(stdin);
    gets(str);
    puts(str);
    for(i=0;i<strlen(str);i++){
        ch[0]=str[i];
        ch[1]='\0';
        strcpy(tag,"");
        if(ch[0]=='#'){
            break;
        }
        switch (ch[0])
        {
            case '<':
            i++;
            ch[0]=str[i];
            ch[1]='\0';
            if(ch[0]=='/'){
                i++;
               while(str[i]!='>'){
                ch[0]=str[1z]
               }
            }
        }
    }
}