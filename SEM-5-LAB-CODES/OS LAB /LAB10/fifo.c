#include <stdio.h>

int main() {
    int pageFaults = 0;

    // Ask the user for the number of frames
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Ask the user for the number of pages
    int pages;
    printf("Enter the number of pages: ");
    scanf("%d", &pages);

    // Declare the incoming stream array
    int incomingStream[pages];

    // Input the page numbers
    printf("Enter the page numbers: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &incomingStream[i]);
    }

    printf("Incoming\t");
    for (int i = 0; i < frames; i++) {
        printf("Frame%d\t", i + 1);
    }
    printf("\n");

    int temp[frames];
    for (int m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    int index = 0; // Tracks the position in a circular manner for FIFO

    for (int m = 0; m < pages; m++) {
        int s = 0;

        // Check if the page is already in one of the frames
        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s = 1; // Set flag to 1 if page is found
                break;
            }
        }

        // If the page is not found in frames, replace the oldest page
        if (s == 0) {
            temp[index] = incomingStream[m];
            index = (index + 1) % frames; // Move index to the next frame in FIFO order
            pageFaults++;
        }

        // Print the current state of the frames
        printf("%d\t\t", incomingStream[m]);
        for (int n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf("%d\t", temp[n]);
            else
                printf("-\t");
        }
        printf("\n");
    }

    printf("Total Page Faults:\t%d\n", pageFaults);
    return 0;
}
