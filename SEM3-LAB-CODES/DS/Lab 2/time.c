#include<stdio.h>
struct time{
    int hour;
    int min;
    int sec;
};
void read(struct time *t){
    printf("Hours: ");
    scanf("%d",&t->hour);
    printf("Minutes: ");
    scanf("%d",&t->min);
    printf("Seconds: ");
    scanf("%d",&t->sec);
}
void display(struct time t){
    printf("Hours: %d\n ",t.hour);
    printf("Minutes: %d\n ",t.min);
    printf("Seconds: %d\n ",t.sec);
}
struct time add(struct time t1,struct time t2){
    struct time result;
    result.sec=((t1.sec+t2.sec)%60);
    result.min=(((t1.min+t2.min)+(t1.sec+t2.sec)/60)%60);
    result.hour=((t1.min+t2.min)+(t1.sec+t2.sec)/60)/60+(t1.hour+t2.hour);
    return result;
}
struct time difference(struct time t1,struct time t2){
    struct time result1;
    int sec1,sec2,total;
    sec1=(t1.hour*3600+t1.min*60+t1.sec);
    sec2=(t2.hour*3600+t2.min*60+t2.sec);
    if(sec1>sec2)
    total=sec1-sec2;
else
total=sec2-sec1;
result1.hour=total/3600;
result1.min=(total-result1.hour*3600)/60;
result1.sec=(total-result1.hour*3600-result1.min*60);
return result1;


}

int main()
{
    struct time t1,t2,sum,diff;
    printf("Enter the details of Time 1:\n");
    read(&t1);
    printf("Enter the details of Time 2:\n");
    read(&t2);

    printf("Time 1:\n");
    display(t1);
    printf("Time 2:\n");
    display(t2);

    sum=add(t1,t2);
    printf("Sum of Time 1 and Time 2 is:\n");
    display(sum);
    diff=difference(t1,t2);
    printf("Difference of Time 1 and Time 2 is:\n");
    display(diff);

    return 0;
}
