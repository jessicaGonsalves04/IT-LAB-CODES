#include<stdio.h>
void reset_hole_processHole(int holes[],int nh,int rem[],int process[],int np,int processHole[]){

    for (int i = 0; i < nh; i++) 
        rem[i] = holes[i];
    for (int i = 0; i < np; i++) 
        processHole[i] = -1;

}
void firstfit(int holes[],int nh,int rem[],int process[],int np,int processHole[]){
    for(int i=0;i<np;i++){
        processHole[i]=-1;
    }
    for(int i=0;i<np;i++){
        for(int j=0;j<nh;j++){
            if(rem[j]>=process[i]){
                //Allocate the hole to the process
                rem[j]-=process[i];
                processHole[i]=j+1;
                break;
            }
        }
    }
    printf("\nFirst Fit\n");
    printf("Process No\tPSize\tHoleNo\tRemHoleSize\n");
    for(int i=0;i<np;i++){
        if(processHole[i]!=-1){
            printf("P%d\t\t%d\tH%d\t%d\n",i+1,process[i],processHole[i],rem[processHole[i]-1]);
        }
        else{
            printf("P%d\t\t%d\t--\t--\n",i+1,process[i],processHole[i]);
        }
    }

}
void bestfit(int holes[], int nh, int rem[], int process[], int np, int processHole[]) {
    // Initialize processHole[] to -1 (no hole allocated)
    for (int i = 0; i < np; i++) {
        processHole[i] = -1;
    }

    // Allocate holes using Best Fit
    for (int i = 0; i < np; i++) {
        int bestHole = -1;
        for (int j = 0; j < nh; j++) {
            if (rem[j] >= process[i]) {
                // If no hole has been found or this hole is better
                if (bestHole == -1 || rem[j] < rem[bestHole]) {
                    bestHole = j;
                }
            }
        }
        // If a suitable hole is found, allocate it
        if (bestHole != -1) {
            rem[bestHole] -= process[i];  // Update remaining hole size
            processHole[i] = bestHole + 1;  // Store hole number (1-based index)
        }
    }

    // Print Best Fit results
    printf("\nBest Fit\n");
    printf("Process No\tPSize\tHoleNo\tRemHoleSize\n");
    for (int i = 0; i < np; i++) {
        if (processHole[i] != -1) {
            printf("P%d\t\t%d\tH%d\t%d\n", i + 1, process[i], processHole[i], rem[processHole[i] - 1]);
        } else {
            printf("P%d\t\t%d\t--\t--\n", i + 1, process[i], processHole[i]);
        }
    }
}
void worstfit(int holes[], int nh, int rem[], int process[], int np, int processHole[]) {
    // Initialize processHole[] to -1 (no hole allocated)
    for (int i = 0; i < np; i++) {
        processHole[i] = -1;
    }

    // Allocate holes using Worst Fit
    for (int i = 0; i < np; i++) {
        int worstHole = -1;
        for (int j = 0; j < nh; j++) {
            if (rem[j] >= process[i]) {
                // Find the hole with the largest remaining size
                if (worstHole == -1 || rem[j] > rem[worstHole]) {
                    worstHole = j;
                }
            }
        }
        // If a suitable hole is found, allocate it
        if (worstHole != -1) {
            rem[worstHole] -= process[i];  // Update remaining hole size
            processHole[i] = worstHole + 1;  // Store hole number (1-based index)
        }
    }

    // Print Worst Fit results
    printf("\nWorst Fit\n");
    printf("Process No\tPSize\tHoleNo\tRemHoleSize\n");
    for (int i = 0; i < np; i++) {
        if (processHole[i] != -1) {
            printf("P%d\t\t%d\tH%d\t%d\n", i + 1, process[i], processHole[i], rem[processHole[i] - 1]);
        } else {
            printf("P%d\t\t%d\t--\t--\n", i + 1, process[i]);
        }
    }
}

int main(){
int nh,np;
printf("Enter the number of holes: ");
scanf("%d",&nh);
int holes[nh];
int remaining[nh];
printf("Enter the hole size of each hole:\n");
for(int i=0;i<nh;i++){
    printf("Hole %d: ",i+1);
    scanf("%d",&holes[i]);
    remaining[i]=holes[i];
}
printf("Enter the numeber of processes: ");
scanf("%d",&np);
int process[np],processHole[np];
printf("Enter the size of each process:\n");
for(int i=0;i<np;i++){
    printf("P%d: ",i+1);
    scanf("%d",&process[i]);
}
printf("Hole Sizes are:\n");
printf("HoleNo\t HoleSize\n");
for(int i=0;i<nh;i++){
    printf("Hole%d\t\t%d\n",i+1,holes[i]);
}
firstfit(holes,nh,remaining,process,np,processHole);
reset_hole_processHole(holes,nh,remaining,process,np,processHole);
bestfit(holes,nh,remaining,process,np,processHole);
reset_hole_processHole(holes,nh,remaining,process,np,processHole);
worstfit(holes,nh,remaining,process,np,processHole);

return 0;
}