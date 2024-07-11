#include<stdio.h>
#define MAX 20
typedef struct{
int top[10];
int arr[MAX];
int b[10]
}stack;
stack s;
void createstack(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        s.top[i]=s.b[i]=(MAX/n)*i-1;
    }
    s.b[i]=MAX-1;
}
void push()
{
    int no,ele;
    printf("Enter the stack number:\n");
    scanf("%d",&no);
    if(s.top[no]==s.b[no+1])
    {
        printf("Stack overflow");
        return;
    }
    printf("Enter element:");
    scanf("%d",&ele);
    s.arr[++s.top[no]]=ele;
}
void pop()
{
    int no;
    printf("Enter the stack number:\n");
    scanf("%d",&no);
    if(s.top[no]==s.b[no])
    {
        printf("Stack underflow");
        return;
    }
    printf("%d",s.arr[s.top[no]--]);

}
void display()
{
    int no;
    printf("Enter the stack number:\n");
    scanf("%d",&no);
    if(s.top[no]==s.b[no])
    {
        printf("Stack underflow");
        return;
    }
    for(int i=s.top[no];i>s.b[no];i--)
        printf("%d\n",s.arr[i]);
}
int main()
{
    int n,choice;
    printf("Enter the number of stacks you want");
    scanf("%d",&n);
    createstack(n);
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        scanf("%d",&choice);
        if(choice==4)
        break;
    else{
        switch(choice){
            case 1:
           {
            push();
            break;
           }
            case 2:
            {
            pop();
            break;
            }
            case 3:
            {
            display();
            break;
            }
            default:
            printf("Invalid input\n");
        }
}
}
}

