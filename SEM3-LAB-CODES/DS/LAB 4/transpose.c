#include<stdio.h>
struct spm{
int r,c,v;
};
struct spm a[20],T[20];
void read(){
    int m,n,i,j,k=0,ele;
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
void transpose(struct spm a[],struct spm T[]){
int k=0;
{
    T[0].r=a[0].c;
    T[0].c=a[0].r;
    T[0].v=a[0].v;
    for(int i=0;i<a[0].c;i++){
        for(int j=1;j<=a[0].v;j++){
            if(a[j].c==i){
                k++;
                T[k].r=a[j].c;
                T[k].c=a[j].r;
                T[k].v=a[j].v;

            }
        }
    }
}
}
void print(struct spm T[]){
for(int i=0;i<=T[0].v;i++){
    printf("%d\t%d\t%d",T[i].r,T[i].c,T[i].v);
    printf("\n");
}
}
int main(){

read();
transpose(a,T);
print(T);
return 0;
}
