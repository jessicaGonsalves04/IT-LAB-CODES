#include<stdio.h>
#define MAX 5
struct stack{
    int arr[MAX];
    int top;
};
struct stack s;
void push()
{
    if(s.top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    int ele;
    printf("Enter the element:");
    scanf("%d",&ele);
    s.arr[++s.top]=ele;
}
void pop()
{
    if(s.top==-1)
    {
        printf("Stack underflow");
        return;
    }
    printf("Element popped is %d",s.arr[s.top--]);
}
void display()
{
    if(s.top==-1){
        printf("Stack underflow");
        return;
    }
    for(int i=s.top;i>=0;i--)
    printf("%d\n",s.arr[i]);
}
int main()
{
    s.top=-1;
    int op;
    while(1)
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit  ");
        scanf("%d",&op);
        if(op==4)
        break;
    else{
        switch(op){
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
return 0;
}