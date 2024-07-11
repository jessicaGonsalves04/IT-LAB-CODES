#include<stdio.h>
#include<stdlib.h>
 typedef struct {
    int top1,top2;
    int arr[10];

 }stack;
 stack s;

 
void push1(int ele){
    if(s.top1+1==s.top2){
        printf("Oveerflow");
        return;
    }
    s.arr[++s.top1]=ele;
} 
void push2(int ele){
    if(s.top2-1==s.top1){
        printf("Oveerflow");
        return;
    }
    s.arr[--s.top2]=ele;
} 
int pop1(){
    if(s.top1==-1){
        printf("Stack underflow");
        return 999;
    }
    return s.arr[s.top1--];
}
int pop2(){
    if(s.top2==10){
        printf("Stack underflow");
        return 999;
    }
    return s.arr[s.top2++];
}
void display1(){
      if(s.top1==-1){
        printf("Stack underflow\n");
        return;
    }
    for(int i=s.top1;i>=0;i--){
        printf("%d\n",s.arr[i]);
    } 
}
void display2(){
      if(s.top2==10){
        printf("Stack underflow\n");
        return;
    }
    for(int i=s.top2;i<=10-1;i++){
        printf("%d\n",s.arr[i]);
    } 
}
int main(){
s.top1=-1;
int c,ele,n;
s.top2=10;
while(1){
printf("\n1.2.3.4.5.6.7\n");
scanf("%d",&c);
switch(c){
    case 1:
      printf("Enter ele:");
      scanf("%d",&ele);
      push1(ele);
      break;
    case 2:
      n=pop1();
      printf("Popped %d",n);
      break;
    case 3:
      display1();
      break;
    case 4:
      printf("Enter ele:");
      scanf("%d",&ele);
      push2(ele);
      break;
    case 5:
      n=pop2();
      printf("Popped %d",n);
      break;
    case 6:
      display2();
      break;
    case 7: 
      exit(0);
    default:
    printf("Invalid");
    
}
}
}


