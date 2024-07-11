#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
}node;
node* insert(node* start){
    node *cur;
    //int ele;
    node*temp=(node*)malloc(sizeof(node));
    printf("Enter the element ");
    scanf("%d",&temp->info);
    temp->prev=temp->next=NULL;
    if(start==NULL){
        return temp;
    }
    cur=start;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return start;

}
node*insertUnion(node* start,int data){
    node *cur;
    //int ele;
    node*temp=(node*)malloc(sizeof(node));
    temp->info=data;
    temp->prev=temp->next=NULL;
    if(start==NULL){
        return temp;
    }
    cur=start;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return start;

}

void display(node *start){
if(start==NULL){
    printf("list is Empty:");
    return;
}
node *cur=start;
while(cur->next!=NULL){
printf("%d ",cur->info);
cur=cur->next;
}
printf("%d",cur->info);
return;
}
int search (node* result,int data){
    node*cur=result;
while(cur!=NULL){
    if(cur->info==data){
        return 1;

    }  cur=cur->next;
}
return 0;
}

node* unionList(node* s1,node *s2){
node *result=NULL;
if(s1==NULL && s2==NULL){
        return NULL;
    }
if(s1==NULL){
    return s2;
}
if(s2==NULL)
return s1;
node* cur1=s1;
node* cur2=s2;
while(cur1!=NULL){
        result=insertUnion(result,cur1->info);
        cur1=cur1->next;
}
while(cur2!=NULL){
    if(!search(result,cur2->info)){
        result=insertUnion(result,cur2->info);
    }
    cur2=cur2->next;
}
return result;
}
int main()
{
    node *start1,*start2,*u;
    start1=NULL;
    start2=NULL;
    u=NULL;
    int c,d;

    int choice;
    while(1)
    {
       printf("\n1.Insert end\n2.Print\n3.Union\n4.Exit");
       scanf("%d",&choice);
       switch(choice){
   case 1:
    printf("Enter List Number(1/2):");
    scanf("%d",&c);
    switch(c){
        case 1:
            start1=insert(start1);
            break;
        case 2:
            start2=insert(start2);
            break;
        default:
            printf("Invalid List Number");
    }
    break;
    case 2:
    printf("Enter List Number(1/2):");
    scanf("%d",&d);
    switch(d){
        case 1:
            printf("\nList 1: ");
            display(start1);
            break;
        case 2:
            printf("\nList 2: ");
            display(start2);
            break;
        default:
            printf("\nInvalid List Number");
    }
    break;
        case 3:
            printf("Union of the Two Lists:");
            u=unionList(start1,start2);
            display(u);
            break;

        case 4:
            exit(0);
        default:
                printf("Invalid");

}
}

}
