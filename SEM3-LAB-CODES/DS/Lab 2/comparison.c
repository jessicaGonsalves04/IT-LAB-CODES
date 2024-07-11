#include<stdio.h>
int main()
{
    char str1[100], str2[100];
    int flag=0,i;
    printf("Enter the first string:\n");
    gets(str1);
    printf("Enter the second string:\n");
    gets(str2);
    i=0;
    while(str1[i]!='\0'||str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            flag=1;
            break;
        }
        i++;
    }
    {
        if(flag==1)
        {
            printf("Not equal.\n");

        }
        else
            printf("Equal\n");
    }
return 0;
}
