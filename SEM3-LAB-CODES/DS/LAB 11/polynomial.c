#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int exp;
int coef;
struct node* next;
}node;

node* attach(node*p,int c,int e){
node* temp=(node*)malloc(sizeof(node));
temp->coef=c;
temp->exp=e;
temp->next=NULL;
if(p==NULL){
    return temp;
}
node*cur=p;
while(cur->next!=NULL){
    cur=cur->next;
}
cur->next=temp;
return p;
}

node*add(node*a,node*b){
int c,coeff,exp;
node*p=NULL;
while(a!=NULL && b!=NULL){
    if(a->exp>b->exp){
        c=1;
    }
    else if(a->exp==b->exp){
        c=0;
    }
    else c=-1;
    switch(c){
case 0:
    coeff=a->coef+b->coef;
    if(coeff!=0){
        p=attach(p,coeff,a->exp);
        a=a->next;
        b==b->next;
    }
    break;
case 1:
    p=attach(p,a->coef,a->exp);
    a=a->next;
    break;
case -1:
    p=attach(p,b->coef,b->exp);
    b=b->next;
    break;
    }
}
}

node* read(node*head){
int n,c,e;
printf("Enter the number of terms:");
scanf("%d",&n);
for(int i=0;i,n;i++){
    printf("Enter coef: ");
    scanf("%d",&c);
    printf("Enter exp: ");
    scanf("%d",&e);
    head=attach(head,c,e);
}
return head;
}
void display(node *p)
{
    node *t = p;
    while(t->next!=NULL){
        printf("(%d)x^%d + ", t->coef, t->exp);
        t=t->next;
    }printf("(%d)x^%d ", t->coef, t->exp);
}



int main(){
node *p1,*p2,*p3;
printf("Enter first polynomial:\n");
p1=read(p1);
printf("Enter Second poly:\n");
p2=read(p2);
 printf("[");
    display(p1);
    printf("] + [");
    //printf("\n");
    display(p2);
    printf("] = ");
    p3=add(p1, p2);
    //printf("\n");
    display(p3);
}

