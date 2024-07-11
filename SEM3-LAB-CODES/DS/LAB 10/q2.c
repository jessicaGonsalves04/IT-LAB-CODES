#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *lcl, *rcl;
}node;

node * create(node *r, int ele)
{
    if(r==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->info=ele;
        temp->lcl=temp->rcl=NULL;
        return temp;
    }
    fflush(stdin);
    char path;
    printf("enter path: ");
    scanf("%c", &path);
    if(path=='l'){
        if(r->lcl==NULL){
            node *temp=(node*)malloc(sizeof(node));
            temp->info=ele;
            temp->lcl=temp->rcl=NULL;
            r->lcl=temp;
            return r;
        }
        else{
            node *p=create(r->lcl, ele);
            //return p;
        }
    }
    else if(path=='r'){
        if(r->rcl==NULL){
            node *temp=(node*)malloc(sizeof(node));
            temp->info=ele;
            temp->lcl=temp->rcl=NULL;
            r->rcl=temp;
            return r;
        }
        else{
            node *p=create(r->rcl, ele);
            //return p;
        }
    }
    return r;
    
}

void display(node *root, int level)
{
    int i;
    if(root==NULL) return;
    display(root->rcl, level+1);
    for(i=0; i<level; i++){
        printf("    ");
    }printf("%d\n",root->info);
    display(root->lcl, level+1);
}

int main()
{
    node *root=NULL;
    char ch; int ele;
    do{
        fflush(stdin);
        printf("Enter ele: ");
        scanf("%d", &ele);
        root=create(root,ele);
        fflush(stdin);
        printf("add another ele: ");
        scanf("%c", &ch);
    }while(ch=='y');
    printf("%d", root->info);
    int l;
    printf("Enter level: ");
    scanf("%d",&l);
    display(root, l);

    return 0;
}