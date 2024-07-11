#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *lcl, *rcl;
}node;

node * insert(node *root)
{
    node *temp=(node *)malloc(sizeof(node));
    int ele;
    printf("enter ele: "); scanf("%d", &ele);
    temp->info=ele;
    temp->lcl=temp->rcl=NULL;
    if(root==NULL) return temp;
    node *cur=root, *prev=NULL;
    while(cur!=NULL){
        if(temp->info==cur->info){
            printf("ele already exists.");
            free(temp);
            return root;
        }
        else{
            prev=cur;
            if(temp->info < cur->info)
                cur=cur->lcl;
            else cur=cur->rcl;
        }
    }
    if(temp->info < prev->info){
        prev->lcl=temp;
    }else prev->rcl=temp;
    return root;
}

void display(node *r)
{
    if(r)
    {
        display(r->lcl);
        printf("%d ", r->info);
        display(r->rcl);
    }
}

void search(node *root, int ele)
{
    if(root==NULL){
        printf("bst empty");
        return;
    }

    node *cur=root;

    while(cur!=NULL)
    {
        if(cur->info==ele){
            printf("ele found.");
            return;
        }
        else if(cur->info > ele){
            cur=cur->lcl;
        }
        else cur=cur->rcl;
    }
    printf("ele not found");
}

node * delbst(node *root, int ele)
{
    node *p, *c, *s;
    if(root==NULL) {
        printf("bst empty");
        return NULL;;
    }
     node *q=root; p=c=s=NULL;

    if(root->info==ele && root->rcl==NULL && root->lcl==NULL){
        free(q);
        return NULL;
    }
   

    while(q!=NULL)
    {
        if(q->info==ele){ c=q; break;}
        p=q;
        if(q->info>ele) q=q->lcl;
        else q=q->rcl;
    }

    if(q==NULL){printf("ele not found."); return root;}

    if(c->lcl!=NULL && c->rcl!=NULL){
        p=c; s=c->rcl;
        while(s->lcl!=NULL){
            p=s;
            s=s->lcl;
        }
        c->info=s->info;
        c=s;
    }

    if(c->lcl==NULL && c->rcl==NULL)
    {
        if(p->rcl==c){
            p->rcl=NULL;
        }
        else p->lcl=NULL;
        free(c);
        return root;
    }

    if(c->lcl==NULL && c->rcl!=NULL)
    {
        if(p->lcl==c) p->lcl=c->lcl;
        else p->rcl=c->rcl;
        free(c);
        return root;
    }
    if(c->lcl!=NULL && c->rcl==NULL)
    {
        if(p->lcl==c) p->lcl=c->lcl;
        else p->rcl=c->rcl;
        free(c);
        return root;
    }
}

int main()
{
    node *root=NULL;
    printf("1.insert 2.delete 3.search 4.traverse 5.exit\n");
    int ch, ele;
    while(1){
         printf("\n1.insert 2.delete 3.search 4.traverse 5.exit");
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        if(ch==5) break;
        switch(ch){
            case 1: root=insert(root); break;
            case 2:{
                printf("enter ele: "); scanf("%d", &ele);
                root=delbst(root, ele);
            }break;
            case 4: display(root); break;
            case 3: {
                printf("enter ele: "); scanf("%d", &ele);
                search(root, ele);
            }break;
            default: break;
        }
    }
    return 0;
}