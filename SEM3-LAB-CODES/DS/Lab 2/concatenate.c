#include<stdio.h>
int main()
{
    char str1[100],str2[100];
    int i,len1=0,len2=0,j;
    printf("Enter the first string:\n");
    gets(str1);
    printf("Enter the second string:\n");
    gets(str2);
    i=0;
    while(str1[i]!='\0')
        {len1++;
        i++;
        }
    j=0;
    while(str2[j]!='\0')
        {
        len2++;
        j++;
        }
     for(j=0;j<=len2;j++)
     {
         str1[len1+j]=str2[j];
     }
     printf("The concatenated string is\n");
     puts(str1);
     return 0;


}
