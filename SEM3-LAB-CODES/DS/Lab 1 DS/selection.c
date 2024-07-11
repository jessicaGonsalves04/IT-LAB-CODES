#include<stdio.h>
int main()
{
    int a[100],pos,small,i,j,n,temp;
    printf("Enter the number of elements in the array ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
        {
            pos=i;
            small=a[i];
            for(j=i+1;j<n;j++)
            {
                if(a[j]<small)
                 pos=j;
            }
            temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;

        }
        printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;



}
