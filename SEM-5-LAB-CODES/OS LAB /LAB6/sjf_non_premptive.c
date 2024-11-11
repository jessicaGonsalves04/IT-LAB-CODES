#include <stdio.h>
#include <limits.h> // For INT_MAX

struct process {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
};

void find_SJF(struct process p[], int n) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].bt;
    }

    int current_time = 0;
    int complete = 0;
    int shortest;
    int minBurst;

    while (complete < n) {
        minBurst = INT_MAX;
        shortest = -1;

        // Find the process with the smallest remaining burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && remaining_time[i] > 0 && remaining_time[i] < minBurst) {
                minBurst = remaining_time[i];
                shortest = i;
            }
        }

        if (shortest != -1) {
            // Process the shortest job
            remaining_time[shortest]--;
            if (remaining_time[shortest] == 0) {
                complete++;
                p[shortest].ct = current_time + 1; // Completion Time here 1 is added coz we increamnt current time in the end
                p[shortest].tat = p[shortest].ct - p[shortest].at; // Turnaround Time
                p[shortest].wt = p[shortest].tat - p[shortest].bt; // Waiting Time
            }
        }

        current_time++;
    }
}

void display(struct process p[], int n) {
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
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

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of P%d: ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }

    find_SJF(p, n);
    display(p, n);

    return 0;
}
