#include<stdio.h>
struct process
{   int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};
int main(){
    int i,j;
    float avg_tat=0,avg_wt=0;
    int sum=0;
    struct process p[10],temp;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter arrival time and burst time for P%d: ",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
    }
    //for sorting based on arrival time
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    sum+=p[0].at;//to keep track fo time where it starts
    for(i=0;i<n;i++){
        sum+=p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        //check for idle time
        if(sum<p[i+1].at){
            int t=p[i+1].at-sum;//if idle time exists then it should be added in order to obtain the completion time
            sum+=t;
        }
    }
    printf("PID\tAT\tBT\tTAT\tCT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].ct,p[i].wt);
     }


}
