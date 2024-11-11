#include <stdio.h>

#define MAX_PROCESSES 100

typedef struct {
    int bt;   // Original Burst Time
    int at;   // Arrival Time
    int start; // Start Time
    int end;   // End Time
    int tat;   // Turnaround Time
    int wt;    // Waiting Time
} Process;

void robin_p(Process processes[], int n, int q, int current_bt[]) {
    int t = 0, execproc = 0, rQ[MAX_PROCESSES], f = -1, e = -1, ptr = 0;
    int lastexec = -1;

    while (execproc < n) {
        // Add processes to the ready queue based on arrival time.
        for (int i = ptr; i < n && processes[i].at <= t; i++) {
            e = (e + 1) % (MAX_PROCESSES);
            rQ[e] = i;
            ptr++;
        }

        // Re-add the last executed process if it still has burst time left.
        if (lastexec != -1 && current_bt[lastexec] > 0) {
            e = (e + 1) % (MAX_PROCESSES);
            rQ[e] = lastexec;
        }

        if (f == e) {
            t++;
            lastexec = -1;
            continue;
        }

        int pos = (f + 1) % (MAX_PROCESSES);
        int pid = rQ[pos];

        if (processes[pid].start == -1) {
            processes[pid].start = t;
        }

        current_bt[pid]--;
        t++;

        for (int i = 1; current_bt[pid] > 0 && i < q; i++) {
            current_bt[pid]--;
            t++;
        }

        f = (f + 1) % (MAX_PROCESSES);

        if (current_bt[pid] == 0) {
            processes[pid].end = t;
            processes[pid].tat = processes[pid].end - processes[pid].at;
            processes[pid].wt = processes[pid].tat - processes[pid].bt;
            execproc++;
        }

        lastexec = pid;
    }
}

void display(Process processes[], int n, int original_bt[]) {
    int total_tat = 0, total_wt = 0;

    printf("\nPID  BT  AT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        int tat = processes[i].end - processes[i].at;
        int wt = processes[i].tat-processes[i].bt;

        processes[i].tat = tat;
        processes[i].wt = wt;

        total_tat += tat;
        total_wt += wt;

        printf("%d    %d   %d   %d    %d   %d\n", i + 1, original_bt[i], processes[i].at, processes[i].end, tat, wt);
    }

    double avg_tat = (double)total_tat / n;
    double avg_wt = (double)total_wt / n;

    printf("\nAverage TAT: %.2f\n", avg_tat);
    printf("Average WT: %.2f\n", avg_wt);
}

int main() {
    int num, q;

    printf("Enter no. of processes: ");
    scanf("%d", &num);
    printf("Enter quantum time: ");
    scanf("%d", &q);

    Process processes[num];
    int original_bt[num];
    int current_bt[num];

    for (int i = 0; i < num; i++) {
        processes[i].start = -1;
        processes[i].end = -1;
        processes[i].tat = 0;
        processes[i].wt = 0;
    }

    printf("\nEnter Burst Time and Arrival Time for each process:\n");
    for (int i = 0; i < num; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &original_bt[i]);
        processes[i].bt = original_bt[i];  // Store original burst time in the process structure
        current_bt[i] = original_bt[i];   // Initialize current burst time with original burst time
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &processes[i].at);
    }

    printf("\nInitial Data:\n");
    for (int i = 0; i < num; i++) {
        printf("Process %d: BT = %d, AT = %d\n", i + 1, original_bt[i], processes[i].at);
    }

    robin_p(processes, num, q, current_bt);
    display(processes, num, original_bt);

    return 0;
}
