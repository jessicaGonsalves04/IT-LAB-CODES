#include<stdio.h>
struct process{
    int pid;
    int pr;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
void find_Priority_non(struct process p[],int n){
   int remaining_time[n];
   for(int i=0;i<n;i++){
    remaining_time[i]=p[i].bt;
   }
    int current_time=0;
    int high_priority=9999;
    int index=-1;
    int complete=0;
    while(complete<n){
        high_priority=9999;
        index=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=current_time && remaining_time[i]>0 && p[i].pr<high_priority){
                high_priority=p[i].pr;
                index=i;
            }
        }
        if(index==-1){
            current_time++;
            continue;
        }
        remaining_time[index]--;
        if(remaining_time[index]==0){
            p[index].ct=current_time+1;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
            complete++;
        }
        current_time++;
    }
}
void display(struct process p[], int n) {
    printf("PID\tPrior\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,p[i].pr, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turn around time = %.2f\n", avg_tat);
}

int main(){
    int n;
    printf("Enter the number of prcesses: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter priority, arrival time and burst time of P%d: ", i + 1);
        scanf("%d%d%d",&p[i].pr, &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }
    find_Priority_non(p,n);
    display(p,n);
    
}