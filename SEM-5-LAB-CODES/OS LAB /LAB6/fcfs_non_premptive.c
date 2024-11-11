#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int process[n],bt[n],ct[n],wt[n],tat[n];
    float avg_tat,avg_wt;
    //taking input
    for(int i=0;i<n;i++){
        process[i]=i+1;
        printf("Enter the burst time of P%d: ",i+1);
        scanf("%d",&bt[i]);
    }
    //Calculate completion time
    int sum=0;//since arrival time is 0 for all processes
    for(int i=0;i<n;i++){
        sum+=bt[i];
        ct[i]=sum;
    }
    //Total TAT
    int total_tat=0;
    //Turnaround time of each process: Completion time -arrival time(==0 in this case)
    for(int i=0;i<n;i++){
        tat[i]=ct[i];
        total_tat+=tat[i];

    }
    //average tat
    avg_tat=total_tat/n;
    //Total wt
    int total_wt=0;
    //Waiting time = turnaround time(TAT) - burst time(BT)
    for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
    }
    avg_wt=total_wt/n;
    //Printing the output
    printf("PID\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average Waiting Time = %f\n",avg_wt);
    printf("Average Turn Around Time = %f",avg_tat);
}