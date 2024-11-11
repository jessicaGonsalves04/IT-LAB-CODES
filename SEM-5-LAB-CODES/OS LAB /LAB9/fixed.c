#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void sortHoles(int holes[], int nh) {
    // Simple bubble sort for sorting the holes array
    for (int i = 0; i < nh - 1; i++) {
        for (int j = 0; j < nh - i - 1; j++) {
            if (holes[j] > holes[j + 1]) {
                int temp = holes[j];
                holes[j] = holes[j + 1];
                holes[j + 1] = temp;
            }
        }
    }
}
void firstfit(int holes[],int nh,int process[],int np){
    bool completed[nh];
    for(int i=0;i<nh;i++){
        completed[i]=false;
    }
    printf("\nProcess Size\tHole Size\tIF\n");
    int IF;
    int check;
    for(int i=0;i<np;i++){
        check=0;
        for(int j=0;j<nh;j++){
            if(process[i]<=holes[j] && !completed[j]){
                IF=holes[j]-process[i];
                completed[j]=true;
                check=1;
                printf("%d\t\t%d\t\t%d\n",process[i],holes[j],IF);
                break;
            }
        }
        if(check==0){
            printf("%d\t\t-\t\t-\n",process[i]);
        }
    }
}
void bestfit(int holes[],int nh,int process[],int np){
   bool completed[nh];
   for(int i=0;i<nh;i++){
    completed[i]=false;
   } 
   sortHoles(holes, nh);
   printf("\nProcess Size\tHole Size\tIIF\n");
   for (int i = 0; i < np; i++) {
        int found = -1;
        // Find the first available hole that fits the process
        for (int j = 0; j < nh; j++) {
            if (process[i] <= holes[j] && !completed[j]) {
                found = j;
                break;
            }
        }
        if (found != -1) {  // Found a suitable hole
            int IF = holes[found] - process[i];
            completed[found] = true;  // Mark the hole as used
            printf("%d\t\t%d\t\t%d\n", process[i], holes[found], IF);
        } 
        else {  // No suitable hole found
            printf("%d\t\t-\t\t-\n", process[i]);
        }
    }
}
void worstfit(int holes[],int nh,int process[],int np){
   bool completed[nh];
   for(int i=0;i<nh;i++){
    completed[i]=false;
   } 
   sortHoles(holes, nh);
   printf("\nProcess Size\tHole Size\tIIF\n");
   for (int i = 0; i < np; i++) {
        int found = -1;
        // Find the first available hole that fits the process
        for (int j = nh-1; j>=0; j--) {
            if (process[i] <= holes[j] && !completed[j]) {
                found = j;
                break;
            }
        }
        if (found != -1) {  // Found a suitable hole
            int IF = holes[found] - process[i];
            completed[found] = true;  // Mark the hole as used
            printf("%d\t\t%d\t\t%d\n", process[i], holes[found], IF);
        } 
        else {  // No suitable hole found
            printf("%d\t\t-\t\t-\n", process[i]);
        }
    }
}
int main(){
    int nh;//no of holes
    int np;//no of processes
    printf("Enter number of holes: ");
    scanf("%d",&nh);
    int holes[nh];
    printf("Enter the size of the available holes:\n");
    for(int i=0;i<nh;i++){
        scanf("%d",&holes[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d",&np);
    int process[np];
    printf("Enter the size of each process:\n");
    for(int i=0;i<np;i++){
        scanf("%d",&process[i]);
    }
    printf("\nFirst Fit:");
    firstfit(holes,nh,process,np);
    printf("\nBest Fit:\n");
    bestfit(holes,nh,process,np);
    printf("\nWorst Fit:\n");
    worstfit(holes,nh,process,np);

    

}