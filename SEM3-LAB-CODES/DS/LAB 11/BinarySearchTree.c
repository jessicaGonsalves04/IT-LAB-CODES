#include<stdio.h>
typedef struct node
{
    int info;
    struct node *lcl;
    struct node *rcl;
} node;

node* createBST(node *root)
{
    node *cur,*prev;
    int i,n;
    printf("Enter the number of Nodes:  ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        node*temp=(node*)malloc(sizeof(node));
        temp->lcl=temp->rcl=NULL;
        printf("Enter the element:\n");
        scanf("%d",&temp->info);
        prev=NULL;
        cur=root;
        while(cur)
        {
            prev=cur;
            if(temp->info>cur->info)
            {
                cur=cur->rcl;
            }
            else if(temp->info<cur->info)
            {
                cur=cur->lcl;
            }
            else
            {
                printf("Duplicate key");
                break;
            }
        }
        if(prev==NULL)
        {
            root=temp;
        }
        else if(temp->info>prev->info)
        {
            prev->rcl=temp;
        }
        else
            prev->lcl=temp;

    }
    return root;
}
void display(node *root, int level)
{
    if (root == NULL)
        return;

    display(root->rcl, level + 1);
    for (int i = 0; i < level; i++)
    {
        printf("       ");
    }
    printf("%d\n", root->info);
    display(root->lcl, level + 1);
}
int bstsmall(node* root)
{
    node* cur=root;
    while(cur->lcl!=NULL)
    {
        cur=cur->lcl;
    }
    return cur->info;
}

int bstlarge(node* root)
{
    node* cur=root;
    while(cur->rcl!=NULL)
    {
        cur=cur->rcl;
    }
    return cur->info;

}
void search(node *root,int ele){
  node* cur=root;
  while(cur!=NULL){
    if(cur->info==ele){
        printf("Element found!!\n");
        return;
    }
    if(ele>cur->info){
        cur=cur->rcl;
    }
    else(cur=cur->lcl);
  }
  printf("Element not found!!\n");
  return;
}
node* inorder(node* root){
if(root){
    inorder(root->lcl);
    printf("%d ",root->info);
    inorder(root->rcl);
}
return root;
}


int main()
{
    int min,max,ele;
    node *root=NULL;
    root=createBST(root);
    display(root,0);
    printf("Enter the element you want to search:");
    scanf("%d",&ele);
    search(root,ele);
    printf("The Inorder sequence of The BST is:\n ");
    root=inorder(root);
    min=bstsmall(root);
    printf("Manimum term is : %d\n",min);
    max=bstlarge(root);
    printf("Maximum term is : %d",max);

}
