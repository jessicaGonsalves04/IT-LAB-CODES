#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int *safesequence;
int ss = -1;

bool checkneed(int m, int need[m], int avail[m])
{
    for (int r = 0; r < m; r++)
    {
        if (need[r] > avail[r])
            return true;
    }
    return false;
}

bool checksafe(int n, bool finish[])
{
    for (int k = 0; k < n; k++)
    {
        if (finish[k] == false)
        {
            // printf("Unsafe state\n");
            return false;
        }
    }
    // printf("Safe state\n");
    return true;
}

bool safestate(int m, int n, int avail[], int alloc[][m], int max[][m], int need[][m])
{
    int work[m];
    bool finish[n];
    for (int r = 0; r < m; r++)
        work[r] = avail[r];
    for (int p = 0; p < n; p++)
        finish[p] = false;

    int i = 0, j = 0;
    while (true)
    {
        j = i;
        while (finish[i] == true || checkneed(m, need[i], work))
        {
            i = (i + 1) % n;
            if (i == j)
            {
                return checksafe(n, finish);
            }
        }

        for (int r = 0; r < m; r++)
        {
            work[r] += alloc[i][r];
        }
        finish[i] = true;
        safesequence[++ss] = i;
    }
}

bool requestallocation(int m, int n, int avail[], int alloc[][m], int max[][m], int need[][m])
{
    int request[m], pid;

    printf("Enter process no: ");
    scanf("%d", &pid);
    printf("Requesting: ");
    for (int r = 0; r < m; r++)
    {
        scanf("%d", &request[r]);
    }

    for (int r = 0; r < m; r++)
    {
        if (request[r] > need[pid][r])
        {
            printf("Resource requested exceeds max requirement for process%d\n", pid);
            return false;
        }
    }
    for (int r = 0; r < m; r++)
    {
        if (request[r] > avail[r])
        {
            printf("Resource requested exceeds available resource\n");
            return false;
        }
    }
    // allocate resource
    for (int r = 0; r < m; r++)
    {
        avail[r] -= request[r];
        need[pid][r] -= request[r];
        alloc[pid][r] += request[r];
    }
    if (safestate(m, n, avail, alloc, max, need))
        return true;
    else
    {
        for (int r = 0; r < m; r++)
        {
            avail[r] += request[r];
            need[pid][r] += request[r];
            alloc[pid][r] -= request[r];
        }
        printf("restoring old safe state.\n");
        return false;
    }
}

int main()
{
    int m, n;
    printf("Enter no. of resource types: ");
    scanf("%d", &m);
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    int available[m], allocation[n][m], max[n][m], need[n][m];
    safesequence = (int *)malloc(sizeof(int) * n);

    printf("total resource available for process: ");
    for (int r = 0; r < m; r++)
    {
        scanf("%d", &available[r]);
        safesequence[r] = -1;
    }

    for (int p = 0; p < n; p++)
    {
        printf("Enter resource allocated for process%d: ", p);
        for (int r = 0; r < m; r++)
        {
            scanf("%d", &allocation[p][r]);
            available[r] -= allocation[p][r];
        }
    }

    for (int p = 0; p < n; p++)
    {
        printf("Enter max need for process%d: ", p);
        for (int r = 0; r < m; r++)
        {
            scanf("%d", &max[p][r]);
        }
    }

    for (int p = 0; p < n; p++)
    {
        printf("resource required for process%d: ", p);
        for (int r = 0; r < m; r++)
        {
            need[p][r] = max[p][r] - allocation[p][r];
            printf("%d", need[p][r]);
        }
        printf("\n");
    }

    if (safestate(m, n, available, allocation, max, need))
    {
        printf("Safe state\nSafe sequnece: ");
        for (int p = 0; p < n; p++)
            printf("P%d ", safesequence[p]);
    }
    else
        printf("Unsafe state.");

    int ch;
    do{
        printf("\nrequest resource allocation?(1/0) ");
        scanf("%d", &ch);
        if(ch==1){
            if(requestallocation(m, n, available, allocation, max, need)){
                printf("request granted.\n");
            }
            else printf("Request Denied.\n");
        }
        else break;
    }while(true);
    return 0;
}