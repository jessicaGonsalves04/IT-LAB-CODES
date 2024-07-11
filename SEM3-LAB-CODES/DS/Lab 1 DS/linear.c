#include<stdio.h>
int main()
{
    int a[100], n , ele , pos ,i,found=0;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("Enter the element to be found:\n");
        scanf("%d",&ele);
        for(i=0;i<n;i++)
        {
            if(a[i]==ele)
                {
                    found=1;
                    pos=i;
                    break;

        }
        }
        if(found==1)
            printf("The element is found in position %d\n",pos+1);
        else
            printf("Element not found\n");
        return 0;


}
