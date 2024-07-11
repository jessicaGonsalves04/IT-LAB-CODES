#include<stdio.h>
#define MAX 100
typedef struct{
int r,c,v;
}spm;
spm a[MAX],T[MAX];
void read(){
    int m,n,i,j,k,ele;
    printf("Enter the dimensions of the matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&ele);
            if(ele==0)
                continue;
            else{
                k++;
                a[k].r=i;
                a[k].c=j;
                a[k].v=ele;
            }
        }
    }
    a[0].r=m;
    a[0].c=n;
    a[0].v=k;
}
void fasttranspose(spm a[],spm T[]){
    int rt[50]={0},sp[50],k=0;
    T[0].r=a[0].c;
    T[0].c=a[0].r;
    T[0].v=a[0].v;
    for(int i=1;i<=a[0].v;i++)
        rt[a[i].c]++;
    sp[0]=1;
    for(int i=1;i<a[0].c;i++)
        sp[i]=sp[i-1]+rt[i-1];
    for(int i=1;i<=a[0].v;i++){
       int k=sp[a[i].c]++;
                T[k].r=a[i].c;
                T[k].c=a[i].r;
                T[k].v=a[i].v;
}
}
void display(spm s[]){
for(int i=0;i<=s[0].v;i++){
    printf("%d\t%d\t%d",s[i].r,s[i].c,s[i].v);
    printf("\n");
}
}
int main(){

read();
printf("The Sparse matrix is:\n");
display(a);
fasttranspose(a,T);
printf("The Transpose of the matrix:\n");
display(T);
return 0;
}

