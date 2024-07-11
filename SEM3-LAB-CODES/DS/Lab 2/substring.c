#include <stdio.h>

int main() {
    char mainString[100];
    char subString[50];
   int i,j,l1=0,l2=0,index;

    // Input the main string
    printf("Enter the main string: ");
    gets(mainString);
    // Input the substring to insert
    printf("Enter the substring to insert: ");
   gets(subString);
    printf("Enter the index in which the substring is to be inserted:\n");
    scanf("%d",&index);
    i=0;
    while(mainString[i] !='\0')
    {
        l1++;
        i++;
    }
    j=0;
    while(subString[j] !='\0')
    {
        l2++;
        j++;
    }
    if(index>l1)
    {
        printf("\nInvalid");
        exit(0);
    }
    //shifting elements
    for(i=l1;i>=index;i--)
    {
        mainString[l2+i]=mainString[i];
    }
    //transfer
    for(i=0;i<l2;i++)
    {
        mainString[index+i]=subString[i];
    }
    printf("After insertion\n");
    puts(mainString);
    return 0;
}






