#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],m,n,p,q,i,j;
    printf("Enter the row size of A \n ");
     scanf("%d",&m);
      printf("Enter the column size of A \n ");
     scanf("%d",&n);
     printf("Enter the row size of B \n ");
     scanf("%d",&p);
      printf("Enter the column size of B\n ");
     scanf("%d",&q);
     if(m!=p || n!=q)
        exit(0);
      printf("Enter the elements of A \n ");
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             scanf("%d",&a[i][j]);
         }
     }
     printf("Enter the elements of B \n ");

     for(i=0;i<p;i++)
     {
         for(j=0;j<q;j++)
         {
             scanf("%d",&b[i][j]);
         }
     }
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[i][j]>=b[i][j])
                c[i][j]=a[i][j];
                else if (a[i][j]<=b[i][j])
                c[i][j]=b[i][j];


         }
     }
      for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             printf("%d\t",c[i][j]);
         }
        printf("\n");
     }
     return 0;


}
