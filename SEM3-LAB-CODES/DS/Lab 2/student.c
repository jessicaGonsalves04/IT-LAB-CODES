#include<stdio.h>
struct student{
    char name[100];
    int rollNo;
    char grade;
};
void read(struct student s[],int num)
{
    for(int i=0;i<num;i++)
    {
    printf("Enter the information of Student %d:\n",i+1);
    printf("Name: ");
    scanf("%s",&s[i].name);
    printf("Roll No: ");
    scanf("%d",&s[i].rollNo);
    printf("Grade: ");
    scanf(" %c",&s[i].grade);
    printf("\n");
}
}
void display(struct student s[],int num)
{
    for(int i=0;i<num;i++)
    {
        printf("Detail of student %d:\n",i+1);
        printf("Name: %s",s[i].name);
        printf("\nRoll No: %d",s[i].rollNo);
        printf("\nGrade: %c",s[i].grade);
        printf("\n");

    }
}
void sort(struct student s[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            if(s[j].rollNo>s[j+1].rollNo)
            {
                struct student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student s[n];
    printf("Enter the student information:\n");
    read(s,n);
    sort(s,n);
    printf("\nThe Sorted student information:\n");
    display(s,n);
    return 0;


}


