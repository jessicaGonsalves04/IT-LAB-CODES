#include<stdio.h>
#define MAX 20
typedef struct{
int f;
int r;
int q[MAX];
}queue;
queue q1;
void enq()
{
    int ele;
    if(q1.r==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d",&ele);
    q1.q[++q1.r]=ele;
}
void deq()
{
    if(q1.f==q1.r){
        printf("Queue is empty.\n");
        return ;
    }
    printf("The element deleted is: ");
    printf("%d",q1.q[++q1.f]);
}
void display()
{
    if(q1.f==q1.r){
        printf("Queue is empty.\n");
        return ;
    }
    for(int i=q1.f+1;i<=q1.r;i++)
        printf("%d\n",q1.q[i]);
}

int main()
{
    q1.f=q1.r=-1;
    int choice;
    while(1){
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    scanf("%d",&choice);
    if(choice==4){
        exit(0);
    }
    switch(choice)
    {
case 1:
    {
        enq();
        break;
    }
case 2:
    {
        deq();
        break;
    }
case 3:
    {
        display();
        break;
    }
default:
    printf("Invalid");

}
    }
    return 0;

}

