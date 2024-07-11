#include <stdio.h>
#include <stdlib.h>

typedef struct WashingMachine {
    int machineID;
    int duration;
    struct WashingMachine* next;
    struct WashingMachine* prev;
} WashingMachine;

// Initialize the circular doubly linked list of washing machines
WashingMachine* initWashingMachines(int numMachines) {
    WashingMachine* head = NULL;
    WashingMachine* tail = NULL;

    for (int i = 1; i <= numMachines; i++) {
        WashingMachine* newMachine = (WashingMachine*)malloc(sizeof(WashingMachine));
        newMachine->machineID = i;
        newMachine->duration = 0;  // Initially not booked
        newMachine->next = head;

        if (head != NULL) {
            head->prev = newMachine;
        }

        head = newMachine;

        if (tail == NULL) {
            tail = newMachine;
        }
    }

    if (tail != NULL) {
        tail->next = head;
        head->prev = tail;
    }

    return head;
}

// Function to display the status of washing machines
void displayWashingMachines(WashingMachine* head) {
    if (head == NULL) {
        printf("No washing machines available.\n");
        return;
    }

    WashingMachine* current = head;
    do {
        printf("Machine %d: ", current->machineID);
        if (current->duration > 0) {
            printf("Booked for %d minutes.\n", current->duration);
        } else {
            printf("Available for booking.\n");
        }
        current = current->next;
    } while (current != head);
}

// Function to book a washing machine
void bookWashingMachine(WashingMachine* head, int machineID, int duration) {
    WashingMachine* current = head;
    do {
        if (current->machineID == machineID && current->duration == 0) {
            current->duration = duration;
            printf("Machine %d booked for %d minutes.\n", machineID, duration);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Machine %d is not available for booking or already booked.\n", machineID);
}

// Function to update the status of washing machines after a duration
void updateWashingMachines(WashingMachine* head) {
    if (head == NULL) {
        return;
    }

    WashingMachine* current = head;
    do {
        if (current->duration > 0) {
            current->duration--;

            if (current->duration == 0) {
                printf("Machine %d is now available for booking.\n", current->machineID);
            }
        }
        current = current->next;
    } while (current != head);
}

int main() {
    int numMachines;
    int machineID, duration;
    printf("Enter the number of washing machines: ");
    scanf("%d", &numMachines);

    WashingMachine* machines = initWashingMachines(numMachines);

    int choice;
    while (1) {
        printf("\nWashing Machine Rental System Menu:\n");
        printf("1. Display washing machine status\n");
        printf("2. Book a washing machine\n");
        printf("3. Simulate time progress\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayWashingMachines(machines);
                break;
            case 2:
                
                printf("Enter machine ID: ");
                scanf("%d", &machineID);
                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);
                bookWashingMachine(machines, machineID, duration);
                break;
            case 3:
                updateWashingMachines(machines);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
