#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
    int top;
    char arr[MAX];
}stack;
stack s;
void push(char ele)
{
    if(s.top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    s.arr[++s.top]=ele;
}
char pop()
{
    if(s.top==-1)
    {
        printf("Stack underflow");
        return;
        }
        return s.arr[s.top--];

}
int main()
{
    char ele,str[80];
    int length;
    s.top=-1;

    printf("Enter the string:\n");
    gets(str);
    length=strlen(str);
    for(int i=0;i<length;i++)
    {
        push(str[i]);
    }
    for(int i=0;i<length;i++)
    if(pop()!=str[i]){
        printf("String is not a palindrome");
        return 0;
    }

printf("String is a palindrome");
return 0;
}