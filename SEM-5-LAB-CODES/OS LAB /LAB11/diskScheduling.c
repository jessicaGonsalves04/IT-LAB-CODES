#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j + 1]
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void fcfs(){
    printf("Enter the number of elements in the sequence:\n");
    int n;
    scanf("%d",&n);
    int head, total;
    printf("Enter the head: ");
    scanf("%d",&head);
    printf("Enter the total number of cylinders: ");
    scanf("%d",&total); 
    int a[n];
    printf("Enter the sequence: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int totalHeadCount=0;
    int prev=head;
    int curr;
    for(int i=0;i<n;i++){
        curr=a[i];
        totalHeadCount+=abs(curr-prev);
        printf("%d -> %d\n",prev,curr);
        prev=curr;
    }
    printf("Total Head Count: %d\n",totalHeadCount);
    return;
}
void sstf(){
   printf("Enter the number of elements in the queue:\n");
    int n;
    scanf("%d",&n);
    int head, total;
    printf("Enter the head: ");
    scanf("%d",&head);
    printf("Enter the total number of cylinders: ");
    scanf("%d",&total);
    int a[n];
    printf("Enter the sequence: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,n);
    bool serviced[n];  // To track serviced requests
    for (int i = 0; i < n; i++) {
        serviced[i] = false;
    }

    int totalHeadCount = 0;
    int prev = head;

    for (int i = 0; i < n; i++) {
        int closestIndex = -1;
        int minDistance = total;  // Start with maximum possible distance

        // Find the closest unserviced request
        for (int j = 0; j < n; j++) {
            if (!serviced[j]) {
                int distance = abs(a[j] - prev);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestIndex = j;
                }
            }
        }

        // Update the head and mark the request as serviced
        if (closestIndex != -1) {
            serviced[closestIndex] = true;
            totalHeadCount += minDistance;
            printf("%d -> %d\n", prev, a[closestIndex]);
            prev = a[closestIndex];
        }
    }
    printf("Total Head Count: %d\n", totalHeadCount);
}
void scan() {
    printf("Enter the number of elements in the queue:\n");
    int n;
    scanf("%d", &n);
    
    int head, total;
    printf("Enter the head: ");
    scanf("%d", &head);
    printf("Enter the total number of cylinders: ");
    scanf("%d", &total);
    
    int a[n];
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the requests
    sort(a, n);
    
    // Boolean array to keep track of processed requests
    bool processed[n];
    for (int i = 0; i < n; i++) {
        processed[i] = false;
    }

    printf("Enter previous head position: ");
    int prevPos;
    scanf("%d", &prevPos);
    
    int totalHeadCount = 0;
    int curr = head;

    // Determine the direction based on previous head position
    int dir = (head > prevPos) ? 1 : -1;

    if (dir == 1) {
        // Moving towards higher cylinder numbers
        for (int i = 0; i < n; i++) {
            if (a[i] >= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        // Go to the end if needed
        if (curr < total) {
            totalHeadCount += abs(total - curr);
            printf("%d -> %d\n", curr, total);
            curr = total;
        }
        // Then move towards the lower cylinder numbers in descending order
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    } else {
        // Moving towards lower cylinder numbers
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        // Go to the start if needed
        if (curr > 0) {
            totalHeadCount += abs(0 - curr);
            printf("%d -> %d\n", curr, 0);
            curr = 0;
        }
        // Then move towards the higher cylinder numbers in ascending order
        for (int i = 0; i < n; i++) {
            if (a[i] > curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    }

    printf("Total Head Count: %d\n", totalHeadCount);
}
void cscan() {
    printf("Enter the number of elements in the queue:\n");
    int n;
    scanf("%d", &n);
    
    int head, total;
    printf("Enter the head: ");
    scanf("%d", &head);
    printf("Enter the total number of cylinders: ");
    scanf("%d", &total);
    
    int a[n];
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the requests
    sort(a, n);
    
    // Boolean array to keep track of processed requests
    bool processed[n];
    for (int i = 0; i < n; i++) {
        processed[i] = false;
    }

    printf("Enter previous head position: ");
    int prevPos;
    scanf("%d", &prevPos);
    
    int totalHeadCount = 0;
    int curr = head;

    // Determine the direction based on previous head position
    int dir = (head > prevPos) ? 1 : -1;

    // Moving towards higher cylinder numbers
    if (dir == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] >= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }

        // Go to the end if needed
        if (curr < total) {
            totalHeadCount += abs(total - curr);
            printf("%d -> %d\n", curr, total);
            curr = total;
        }
        // Jump back to the start of the queue
        if (curr != 0) {
            totalHeadCount += abs(0 - curr);
            printf("%d -> %d\n", curr, 0);
            curr = 0;
        }
        
        // Then move towards the higher cylinder numbers in ascending order
        for (int i = 0; i < n; i++) {
            if (a[i] > curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    } else {
        for (int i = n-1; i>0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
         // Go to the end if needed
        if (curr >0) {
            totalHeadCount += abs(curr-0);
            printf("%d -> %d\n", curr, 0);
            curr = 0;
        }
        // Jump back to the end of the queue
        if (curr != total) {
            totalHeadCount += abs(total - curr);
            printf("%d -> %d\n", curr, total);
            curr = total;
        }
        for (int i = n-1; i >0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        
    }

    printf("Total Head Count: %d\n", totalHeadCount);
}
void look() {
    printf("Enter the number of elements in the queue:\n");
    int n;
    scanf("%d", &n);
    
    int head, total;
    printf("Enter the head: ");
    scanf("%d", &head);
    printf("Enter the total number of cylinders: ");
    scanf("%d", &total);
    
    int a[n];
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the requests
    sort(a, n);
    
    // Boolean array to keep track of processed requests
    bool processed[n];
    for (int i = 0; i < n; i++) {
        processed[i] = false;
    }

    printf("Enter previous head position: ");
    int prevPos;
    scanf("%d", &prevPos);
    
    int totalHeadCount = 0;
    int curr = head;

    // Determine the direction based on previous head position
    int dir = (head > prevPos) ? 1 : -1;

    if (dir == 1) {
        // Moving towards higher cylinder numbers
        for (int i = 0; i < n; i++) {
            if (a[i] >= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        // Then move towards the lower cylinder numbers in descending order
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    } else {
        // Moving towards lower cylinder numbers
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        // Then move towards the higher cylinder numbers in ascending order
        for (int i = 0; i < n; i++) {
            if (a[i] > curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    }

    printf("Total Head Count: %d\n", totalHeadCount);
}
void clook() {
    printf("Enter the number of elements in the queue:\n");
    int n;
    scanf("%d", &n);
    
    int head, total;
    printf("Enter the head: ");
    scanf("%d", &head);
    printf("Enter the total number of cylinders: ");
    scanf("%d", &total);
    
    int a[n];
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Sort the requests
    sort(a, n);
    
    // Boolean array to keep track of processed requests
    bool processed[n];
    for (int i = 0; i < n; i++) {
        processed[i] = false;
    }

    printf("Enter previous head position: ");
    int prevPos;
    scanf("%d", &prevPos);
    
    int totalHeadCount = 0;
    int curr = head;

    // Determine the direction based on previous head position
    int dir = (head > prevPos) ? 1 : -1;

    // Moving towards higher cylinder numbers
    if (dir == 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] >= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        if(curr != a[0]){
            totalHeadCount+=abs(a[0]-curr);
            printf("%d -> %d\n",curr,a[0]);
            curr=a[0];
            processed[0]=true;
        }
        // Then move towards the higher cylinder numbers in ascending order
        for (int i = 0; i < n; i++) {
            if (a[i] > curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
    } else {
        for (int i = n-1; i>0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        if(curr != a[n-1]){
            totalHeadCount+=abs(a[n-1]-curr);
            printf("%d->%d",curr,a[n-1]);
            curr=a[n-1];
            processed[n-1]=true;
        }
        for (int i = n-1; i >0; i--) {
            if (a[i] <= curr && !processed[i]) {
                totalHeadCount += abs(a[i] - curr);
                printf("%d -> %d\n", curr, a[i]);
                curr = a[i];
                processed[i] = true; // Mark as processed
            }
        }
        
    }

    printf("Total Head Count: %d\n", totalHeadCount);
}
int main(){
    while(1){
        int option;
        printf("1. First Come-First Serve (FCFS)\n");
        printf("2. Shortest Seek Time First (SSTF)\n");
        printf("3. Elevator (SCAN)\n");
        printf("4. Circular SCAN (C-SCAN)\n");
        printf("5. LOOK\n");
        printf("6. C-LOOK\n");
        printf("7. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                fcfs();
                break;
            case 2:
                sstf();
                break;
            case 3:
                scan();
                break;
            case 4:
                cscan();
                break;
            case 5:
                look();
                break;
            case 6:
                clook();
                break;
            case 7:
                printf("Exiting....");
                exit(0);
            default:
                printf("Invalid Option Try again\n");
                break;
        }
    }
}