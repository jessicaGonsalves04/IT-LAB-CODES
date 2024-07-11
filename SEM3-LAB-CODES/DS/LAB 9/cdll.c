#include<stdio.h>
#include<stdlib.h>

 typedef struct node{
 int info;
 struct node *prev;
 struct node *next;
 }node;

 node* ins_at_end(node *start){
 node *temp=(node*)malloc(sizeof(node));
 printf("Enter the element:");
 scanf("%d",&temp->info);
 temp->prev=temp;
 temp->next=temp;
 if(start==NULL){
    start=temp;
    return start;
 }
 node *cur=start;
 while(cur->next!=start){
    cur=cur->next;
 }
 temp->next=cur->next;
 temp->prev=cur;
 cur->next=temp;
 start->prev=temp;
 return start;
 }

 node* del_at_end(node *start){
 if(start==NULL){
    printf("Nothing to delete");
    return start;
 }
 node *cur=start;
 while(cur->next!=start){
    cur=cur->next;
 }
 if(cur==start){
    printf("Deleted element is:%d\n",cur->info);
    free(cur);
    return NULL;
 }

 cur->prev->next=cur->next;
 start->prev=cur->prev;
 printf("Deleted element is:%d\n",cur->info);
 free(cur);
 return start;

 }


 void display(node *start){
 if(start==NULL){
    printf("List is Empty");
    return;
 }
 node *cur=start;
  while(cur->next!=start){
    printf("%d->",cur->info);
    cur=cur->next;
  }
  printf("%d",cur->info);
  return start;
 }

 int main(){
 int choice;
 node *start=NULL;
 while(1){
 printf("\n1.Insert an element\n2.Delete an element\n3.Display\n4.Exit\n");
 scanf("%d",&choice);
 switch(choice){
 case 1:
     start=ins_at_end(start);
     break;
 case 2:
    start=del_at_end(start);
    break;
 case 3:
    display(start);
    break;
 case 4:
    exit(0);
 default:
    printf("INVALID");
 }
 }
 return 0;
}

