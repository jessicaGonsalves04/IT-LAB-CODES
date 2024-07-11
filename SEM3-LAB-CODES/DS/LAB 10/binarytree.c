#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct node
{
    int info;
    struct node *lcl, *rcl;
}node;

typedef struct stac
{
    int top;
    node * arr[MAX];
}stac;
stac S;

node * createbt(node *root)
{
    node *temp=(node*)malloc(sizeof(node));
    printf("Enter element: ");
    scanf("%d",&temp->info);
    temp->lcl=temp->rcl=NULL;
    if(root==NULL){
        return temp;
    }
    char d[MAX];
    printf("enter path: ");
    scanf("%s", &d);
    printf("path : %s len: %d",d, strlen(d));
    node *c, *p; int i;
    c=root; p=NULL;
    for( i=0; i<strlen(d); i++){
        if(c==NULL)
            break;
        printf("\n%d\n",c->info);
        p=c;
        if(d[i]=='l')
             c=c->lcl;
        else
            c=c->rcl;
    }
    if(c!=NULL || i!=strlen(d)){
        printf("i: %d len: %d Invalid path.",i, strlen(d));
        free(temp);
        return root;
    }
    if(d[i-1]=='l') p->lcl=temp;
    else p->rcl=temp;
    return root;
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

void inorder(node *root)
{
    if(root)
    {
        inorder(root->lcl);
        printf("%d", root->info);
        inorder(root->rcl);
    }
}

void postorder(node *root)
{
    if(root)
    {
        postorder(root->lcl);
        postorder(root->rcl);
        printf("%d", root->info);
    }
}

void preorder(node *root)
{
    if(root)
    {
        printf("%d", root->info);
        preorder(root->lcl);
        preorder(root->rcl);
    }
}

void push(node *root){
    S.arr[++S.top]=root;
}

node * pop()
{
    if(S.top==-1) return NULL;
    return S.arr[S.top--];
}

void iter_in(node *root)
{
    for(;;){
        for(; root; root=root->lcl)
            push(root);
        root=pop();
        if(!root) break;
        printf("%d", root->info);
        root=root->rcl;
    }
}

void iter_pre(node *root)
{
    for(;;){
        for(; root; root=root->lcl){
            printf("%d", root->info);
            push(root);
        }
        root=pop();
        if(!root) break;
        root=root->rcl;
    }
}

void iter_post(node *r)
{
    for(;;){
        for(; r; r=r->lcl){
            if(r->rcl){
                push(r->rcl);
            }
            push(r);
        }
        r=pop();
        if((r->rcl!=NULL)&& (S.top >= 0) && ((r->rcl)==(S.arr[S.top]))){
            node *p; p=pop();
            push(r);
            r=r->rcl;
        }
        else
        {
            printf("%d", r->info);
            r=NULL;
        }
        if(S.top==-1) break;
    }

}

void parent(node *root, int ele)
{
    int flag=0, f=0,r=-1;
    node *q[MAX];
    node *curr;
    q[++r]=root;
    if(root->info == ele){
        printf("element is root");
        return;
    }
    while(f<=r){
        curr=q[f++];
        //printf("%d ", curr->info);
        if(( curr->lcl!=NULL && curr->lcl->info==ele) || (curr->rcl!=NULL && curr->rcl->info==ele)){
            printf("parent: %d", curr->info);
            flag=1;
            return;
        }
        if(curr->lcl!=NULL) q[++r]=curr->lcl;
        if(curr->rcl!=NULL) q[++r]=curr->rcl;
    }
    if(!flag){
        printf("element not found.");
    }

}

int max(int a, int b)
{
    int m=(a>b)?a:b;
    return m;
}

int depth(node *root)
{
    if(root==NULL) return 0;
    return(max(depth(root->lcl),depth(root->rcl))+1);
}

int ancestor(node *root, int ele)
{
    if(root==NULL) return 0;
    if(root->info==ele) return 1;
    if(ancestor(root->rcl,ele) || ancestor(root->lcl,ele))
    {
        printf("%d ",root->info);
        return 1;
    }
    return 0;
}

void leaf(node *root) {
    if (root == NULL) {
        printf("Tree empty\n");
        return;
    }
    int f = 0, r = -1, count = 0;
    node *q[MAX];
    node *curr;
    q[++r] = root;
    while (f <= r) {
        curr = q[f++];
        printf("%d ", curr->info);  // Add this line to print the info of each node
        if (curr->lcl == NULL && curr->rcl == NULL) {
            count++;
        }
        if (curr->lcl != NULL)
            q[++r] = curr->lcl;
        if (curr->rcl != NULL)
            q[++r] = curr->rcl;
    }
    printf("\nLeaf nodes: %d\n", count);
}


int main()
{
    node *root=NULL;
    char ch;
    int d;
    printf("Create binary tree:\n");
    do{
        root=createbt(root);
        //printf("%d", root->info);
        printf("add another node(y/n)?");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch=='y');

    int level;
    printf("enter level of tree: "); scanf("%d", &level);
    display(root, level);

    /*printf("\ninorder: ");
    inorder(root);
    printf("\npostorder: ");
    postorder(root);
    printf("\npreorder: ");
    preorder(root);

    node *temp=root;
    S.top=-1;
    printf("\niterartive inorder: ");
    iter_in(root);
    S.top=-1;
    printf("\niterartive postorder: ");
    iter_post(temp);
    S.top=-1;
    printf("\niterartive preorder: ");
    iter_pre(root);*/

    int cha;
    printf("\n1.in order 2.post order 3.pre order 4.parent of ele 5.depth of tree 6.ancestors 7.count leaf nodes 8.exit \n");

    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &cha);
        if(cha==8) break;
        switch(cha){
            case 1: S.top=-1; iter_in(root); break;
            case 2: S.top=-1; iter_post(root); break;
            case 3: S.top=-1; iter_pre(root); break;
            case 4: {
                int x;
                printf("Enter ele: ");
                scanf("%d", &x);
                parent(root, x);
            }break;
            case 5:  d=depth(root); printf("depth of tree is: %d", d); break;
            case 6: {
                int x;
                printf("Enter ele: ");
                scanf("%d", &x);
                int a=ancestor(root, x);
                if(!a){printf("root");}
            }break;
            case 7: leaf(root); break;
            default: break;
        }
    }
    return 0;
}
