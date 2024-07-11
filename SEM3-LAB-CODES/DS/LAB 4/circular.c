#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
int f;
int r;
int q[MAX];
}queue;
queue q1;
void enq()
{
    if((q1.r+1)%MAX==q1.f){
        printf("Queue is full.\n");
        return;
    }
    int ele;
    printf("Enter Element:\n");
    scanf("%d",&ele);
    q1.r=(q1.r+1)%MAX;
    q1.q[q1.r]=ele;
}
void deq(){
if(q1.r==q1.f){
    printf("Queue is empty.");
    return;
}
q1.f=(q1.f+1)%MAX;
printf("Element deleted is: %d",q1.q[q1.f]);
}
void display(){
if(q1.r == q1.f){
    printf("Queue is empty.\n");
    return;
}
 int i = (q1.f + 1) % MAX;
    do {
        printf("%d ", q1.q[i]);
        i = (i + 1) % MAX;
    } while (i != (q1.r + 1) % MAX);
    printf("\n");
}
int main()
{
    q1.f=q1.r=0;
    int choice;
    while(1){
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
