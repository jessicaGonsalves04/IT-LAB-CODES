#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff, exp;
    struct node *next, *prev;
}node;

node * attach(int c, int e, node *p)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->coeff=c;
    temp->exp=e;
    temp->next=temp->prev=NULL;
    if(p==NULL){
        temp->next=temp->prev=temp;
        p=temp;
        return p;
    }
    node *curr=p;
    while(curr->next!=p){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    temp->next=p;
    p->prev=temp;
    return p;
}


node * read(node *p)
{
    while(1)
    {
        int coeff, exp;
        printf("Enter another coeffecient(else -999): ");
        scanf("%d", &coeff);
        if(coeff==-999){
            break;
        }
        printf("Enter exponent: ");
        scanf("%d", &exp);
        p=attach(coeff, exp, p);
    }
    return p;
}


node * add_poly(node *a, node *b)
{
    node *x=a, *y=b;
    int c, coeff, exp; node *q=NULL;
   
    int d=0,f=0;
    while((a!=NULL && (a!=x || d==0)) && (b!=NULL && (b!=y || f==0))){
        if(a->exp > b->exp) {
            c=1; d=1;
        }
        else if(a->exp == b->exp){
            c=0; d=1; f=1;
        }
        else {c=-1; f=1;}
     
        switch(c){
            case 0: coeff=a->coeff + b->coeff;
                    if(coeff!=0){
                        q=attach(coeff, a->exp, q);
                        a=a->next; b=b->next;
                    }break;
            case 1: q=attach(a->coeff, a->exp, q);
                    a=a->next;
                    break;
            case -1: q=attach(b->coeff, b->exp, q);
                    b=b->next;
                    break;
        }

    }
    while(d!=0 && a!=x){
        q=attach(a->coeff, a->exp, q);
        a=a->next;
    }

    while (f!=0 && b!=y)
    {
        q=attach(b->coeff, b->exp, q);
        b=b->next;
    }
    return q;
}

void display(node *p)
{
    node *t = p;
    if(p==NULL) return;
    while(t->next!=p){
        printf("(%d)x^%d + ", t->coeff, t->exp);
        t=t->next;
    }printf("(%d)x^%d ", t->coeff, t->exp);
}

int main()
{
    node *p1=NULL, *p2=NULL, *p3=NULL;
     printf("Enter first polynomial: \n");
    p1=read(p1);
     printf("Enter second polynomial: \n");
    p2=read(p2);
    printf("[");
    display(p1);
    printf("] + [");
    //printf("\n");
    display(p2);
    printf("] = ");
    p3=add_poly(p1, p2);
    //printf("\n");
    display(p3);

}
