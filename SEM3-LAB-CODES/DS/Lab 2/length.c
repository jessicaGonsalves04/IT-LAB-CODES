#include<stdio.h>
int main()
{
    char str[100];
    int length,i;
    printf("Enter the string;\n");
    gets(str);
    i=0;
    length=0;
    while(str[i]!='\0')
    {
        length++;
        i++;
    }
    printf("The length is %d",length);
    return 0;


}
