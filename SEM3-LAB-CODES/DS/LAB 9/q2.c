#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff, exp;
    struct node *next;
}node;

node * attach(int c, int e, node *p)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->coeff=c;
    temp->exp=e;
    temp->next=NULL;
    if(p==NULL){
        p=temp;
        return p;
    }
    node *curr=p;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
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
    int c, coeff, exp; node *p=NULL;
    while(a!=NULL && b!=NULL){
        if(a->exp > b->exp) {
            c=1;
        }
        else if(a->exp == b->exp){
            c=0;
        }
        else c=-1;

        switch(c){
            case 0: coeff=a->coeff + b->coeff;
                    if(coeff!=0){
                        p=attach(coeff, a->exp, p);
                        a=a->next; b=b->next;
                    }break;
            case 1: p=attach(a->coeff, a->exp, p);
                    a=a->next;
                    break;
            case -1: p=attach(b->coeff, b->exp, p);
                    b=b->next;
                    break;
        }

    }
    //printf("\nhere");
    while(a!=NULL){
        p=attach(a->coeff, a->exp, p);
        a=a->next;
    }
    //printf("\nhehe");
    while (b!=NULL)
    {
        p=attach(b->coeff, b->exp, p);
        b=b->next;
    }
    return p;
}

void display(node *p)
{
    node *t = p;
    while(t->next!=NULL){
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
