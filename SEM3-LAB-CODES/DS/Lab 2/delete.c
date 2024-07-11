#include<stdio.h>
int main(){
    int i=0,j=0,k=0,mcnt=0,scnt=0,n=0,flag=0;
    char mainstr[100],substr[20],newstr[100];
    printf("Enter the main string:\n");
    gets(mainstr);
    while(mainstr[mcnt]!='\0')
    mcnt++;
printf("Enter the substring to be deleted:\n");
    gets(substr);
    while (substr[scnt]!='\0')
scnt++;
    for(i=0;mainstr[i]!='\0';i++){
        k=i;
        while(mainstr[i]==substr[j]){
            i++,j++;
            if(j==scnt)
            {
                flag=1;
                break;
            }

        }
        j=0;
    if(flag==0)
        i=k;
    else
    flag=0;
newstr[n]=mainstr[i];
n++;
}
newstr[n]='\0';
if(n!=mcnt)
puts(newstr);
else printf("The substring was not found\n");
return 0;
}
