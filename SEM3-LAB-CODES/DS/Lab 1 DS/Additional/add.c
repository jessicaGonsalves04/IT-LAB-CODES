#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],i,j,m,n,p,q;
    printf("Enter the dimensions of the first matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the second matrix:\n");
    scanf("%d%d",&p,&q);
     if(m!=p ||n!=q)
    {
        printf("Cannot add.\n");
        exit(0);
    }
    printf("Enter elements of matrix 1:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Enter the elements of matrix 2:\n");

    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);

    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];
    }
    printf("The sum of matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",c[i][j]);
            printf("\n");

    }


}
