#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *lcl;
    struct node *rcl;
}node;

typedef struct stack{
node* arr[100];
int top;
}stack;
stack s;

 void push(node* root){
 if(s.top==99){
    printf("Stack Overflow");
    return;
    }
    s.arr[++s.top]=root;
 }

 node* pop(){
 if(s.top==-1){

    return NULL;
     }
     return s.arr[s.top--];
 }
node* createbt(node *root){
    node *temp=(node*)malloc(sizeof(node));
    printf("Enter the info of the node: ");
    scanf("%d",&temp->info);
    temp->lcl=NULL;
    temp->rcl=NULL;
    node *cur,*prev;
    int i;
    if(root==NULL){
        return temp;
    }
    cur=root;
    prev=NULL;
    printf("Enter the direction: ");
    fflush(stdin);
    char d[10];
    gets(d);
    printf("Direction:%s Length:%d",d,strlen(d));
    for( i=0;i<strlen(d);i++){
        if(cur==NULL){
            break;
        }
        prev=cur;
        printf(" %d ",cur->info);
        if(d[i]=='l'){
            cur=cur->lcl;
        }
        else
            cur=cur->rcl;
    }
    if(cur!=NULL || i!=strlen(d)){
        printf("Invalid\n");
        free(temp);
        return root;
    }
    if(d[i-1]=='l'){
        prev->lcl=temp;
    }
    else
        prev->rcl=temp;
return root;
}
//inorder iterative traversal
void inorder(node *root){
for(;;){
    for(;root;root=root->lcl){
        push(root);
    }
    root=pop();
    if(!root)
        break;
    printf(" %d ",root->info);
    root=root->rcl;
}
}
//inorder recurrsive traversal
void in_order(node*root){
if(root){
    in_order(root->lcl);
    printf("%d ",root->info);
    in_order(root->rcl);
}
}
//iterative preorder
void preorder(node *root){
   // s.top=-1;
for(;;){
    for(;root;root=root->lcl){
        printf("%d ",root->info);
        push(root);
    }
    root=pop();
    if(!root){
        break;
    }
    root=root->rcl;
}
}
//recursive traversal preorder
void pre_order(node *root){
if(root){
    printf("%d ",root->info);
    pre_order(root->lcl);
    pre_order(root->rcl);
}
}
//iterative post order
void postorder(node *root){
for(;;){
    for(;root;root=root->lcl){
        if(root->rcl){
            push(root->rcl);
        }
        push(root);
    }
    root=pop();
    if((root->rcl!=NULL) && (s.top>=0)&&(root->rcl==s.arr[s.top])){
        node *p;
        p=pop();
        push(root);
        root=root->rcl;
    }
    else{
        printf("%d ",root->info);
        root=NULL;
    }
    if(s.top==-1){
        break;
    }
}
}
//recursive post order
void post_order(node *root){
if(root){
    post_order(root->lcl);
    post_order(root->rcl);
    printf("%d ",root->info);
}
}

void levelorder(node *root){
    node *cur=root;
    node *q[20];
    int front=-1,rear=-1;
    q[++rear]=cur;
    while(front!=rear){
        cur=q[++front];
        printf("%d ",cur->info);
        if(cur->lcl){
            q[++rear]=cur->lcl;
        }
        if(cur->rcl){
            q[++rear]=cur->rcl;
        }
    }


}

void display(node *root,int level){
if(root==NULL){
    return;
    }
display(root->rcl,level+1);
for(int i=0;i<level;i++)
    printf("      ");
printf("%d\n",root->info);
display(root->lcl,level+1);
}


int main(){
    node *root=NULL;
    char c;
    s.top=-1;
printf("Create a Binary Tree\n");
do{
    root=createbt(root);
    printf("\nDo you want to continue?(y/n)");
    fflush(stdin);
    scanf("%c",&c);
}while(c=='y');

int level;
printf("\nEnter the level of the tree: ");
scanf("%d",&level);

display(root,level);

printf("\nInorder Traversal:\n");
inorder(root);
printf("\nRecursive Inorder Traversal\n");
in_order(root);
printf("\nPre-order Traversal:\n");
preorder(root);
printf("\nRecursive Pre-order Traversal\n");
pre_order(root);
printf("Iterative post-order:\n");
postorder(root);
printf("\nRecursive Postorder Traversal\n");
post_order(root);
printf("\n Level Order Traversal:\n");
levelorder(root);


return 0;
}
