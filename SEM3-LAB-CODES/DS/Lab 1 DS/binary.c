#include<stdio.h>
int main()
{
    int a[100],n,i,low,mid,high,ele;
    printf("Enter the number of elements \n ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be found:\n");
    scanf("%d",&ele);
    low=0;
    high=n-1;
    do{
        mid=(low+high)/2;
        if (ele<a[mid])
            high=mid-1;
        else if (ele>a[mid])
            low=mid+1;
    }while(ele!=a[mid]&&low<=high);
    if(ele==a[mid])
        printf("Element is found in position %d\n",mid+1);
    else
        printf("NOt found\n");
    return 0;
}
