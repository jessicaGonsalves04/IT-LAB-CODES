#include<stdio.h>

void reset_hole_prochole(int nh, int np,int holes[], int rem[] , int prochole[]){
    for(int i=0; i<nh; i++) rem[i]=holes[i];
    for(int i=0; i<np; i++) prochole[i]=-1;
}

void firstfit(int nh, int np, int holes[], int rem[], int proc[], int prochole[]){

    for(int i=0; i<np; i++) prochole[i]=-1;

    for(int i=0; i<np ; i++){
        for(int j=0; j<nh; j++){
            if(rem[j]>=proc[i]){
                //alloc hole to proc
                rem[j]-=proc[i];
                prochole[i]=j;
                break;
            }
        }
    }
    printf("\nFirst Fit\n");
    for(int i=0; i<np; i++){
        if(prochole[i]!=-1)
            printf("proc%d: %d : %dhole\n", i, proc[i], prochole[i]);
        else 
            printf("proc%d: %d :unallocated \n", i, proc[i]);
    }
    printf("\n\tsize IF\n");
    for(int i=0; i<nh; i++){
        if(holes[i]==rem[i]){
            printf("hole%d : %d : unallocated\n", i, holes[i]);
            continue;
        }
        printf("hole%d : %d : %d\t", i, holes[i], rem[i]);
        for(int j=0; j<np; j++){
            if(prochole[j]==i) printf("proc%d ", j);
        }
        printf("\n");
    }
}

void bestfit(int nh, int np, int holes[], int rem[], int proc[], int prochole[]){

    for(int i=0; i<np; i++) prochole[i]=-1;
    int findmin=-1;
    for(int i=0; i<np ; i++){
        findmin=-1;
        for(int j=0; j<nh; j++){
            if(rem[j]>=proc[i]){
                //alloc hole to proc
                if(findmin==-1)
                    findmin=j;
                else{
                    if(rem[j]<rem[findmin]) findmin=j;
                }
            }
        }
        if(findmin!=-1){
            rem[findmin]-=proc[i];
            prochole[i]=findmin;
        }
        
    }
    printf("\nBest Fit\n");
    for(int i=0; i<np; i++){
        if(prochole[i]!=-1)
            printf("proc%d: %d : %dhole\n", i, proc[i], prochole[i]);
        else 
            printf("proc%d: %d :unallocated \n", i, proc[i]);
    }
    printf("\n\tsize IF\n");
    for(int i=0; i<nh; i++){
        if(holes[i]==rem[i]){
            printf("hole%d : %d : unallocated\n", i, holes[i]);
            continue;
        }
        printf("hole%d : %d : %d\t", i, holes[i], rem[i]);
        for(int j=0; j<np; j++){
            if(prochole[j]==i) printf("proc%d ", j);
        }
        printf("\n");
    }
}

void worstfit(int nh, int np, int holes[], int rem[], int proc[], int prochole[]){

    for(int i=0; i<np; i++) prochole[i]=-1;
    int findmin=-1;
    for(int i=0; i<np ; i++){
        findmin=-1;
        for(int j=0; j<nh; j++){
            if(rem[j]>=proc[i]){
                //alloc hole to proc
                if(findmin==-1)
                    findmin=j;
                else{
                    if(rem[j]>rem[findmin]) findmin=j;
                }
            }
        }
        if(findmin!=-1){
            rem[findmin]-=proc[i];
            prochole[i]=findmin;
        }
        
    }
    printf("\nWorst Fit\n");
    for(int i=0; i<np; i++){
        if(prochole[i]!=-1)
            printf("proc%d: %d : %dhole\n", i, proc[i], prochole[i]);
        else 
            printf("proc%d: %d :unallocated \n", i, proc[i]);
    }
    printf("\n\tsize IF\n");
    for(int i=0; i<nh; i++){
        if(holes[i]==rem[i]){
            printf("hole%d : %d : unallocated\n", i, holes[i]);
            continue;
        }
        printf("hole%d : %d : %d\t", i, holes[i], rem[i]);
        for(int j=0; j<np; j++){
            if(prochole[j]==i) printf("proc%d ", j);
        }
        printf("\n");
    }
}

int main(){
    int nh, np;
    printf("Enter no. of holes: "); scanf("%d", &nh);
    int holes[nh], rem[nh];
    printf("Enter hole size:\n");
    for(int i=0; i<nh; i++){
        printf("%d :", i);
        scanf("%d", &holes[i]);
        rem[i]=holes[i];
    }

    printf("Enter no. of proc: "); scanf("%d", &np);
    int  proc[np], prochole[np];
    printf("Enter proc size:\n");
    for(int i=0; i<np; i++){
        printf("%d :", i);
        scanf("%d", &proc[i]);
    }

    firstfit(nh, np, holes, rem, proc, prochole);
    reset_hole_prochole(nh, np, holes, rem, prochole);
     bestfit(nh, np, holes, rem, proc, prochole);
    return 0;
    
}