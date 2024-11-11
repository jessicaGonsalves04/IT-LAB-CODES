#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a solution to the first readers-writers problem using mutex and semaphore.
It demonstrates the solution with 10 readers and 5 writers, but these values can be adjusted.
*/

// Semaphore to control access to the shared resource (writers' access)
sem_t wrt;

// Mutex to protect the numreader variable (readers' count)
pthread_mutex_t mutex;

// Shared resource (variable to be read by readers and modified by writers)
int cnt = 1;

// Counter to track the number of readers currently accessing the shared resource
int numreader = 0;

/* 
 * Writer function
 * Each writer multiplies the shared resource `cnt` by 2.
 * The semaphore ensures mutual exclusion, so only one writer can modify the shared resource at a time.
 */
void *writer(void *wno)
{   
    // Wait until the semaphore is available (block other writers and readers)
    sem_wait(&wrt);

    // Critical section: modify the shared resource
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", (*((int *)wno)), cnt);

    // Release the semaphore (allow others to access the shared resource)
    sem_post(&wrt);
}

/* 
 * Reader function
 * Each reader reads the shared resource `cnt`. 
 * Multiple readers can read the resource concurrently, but no writers can modify it while readers are reading.
 */
void *reader(void *rno)
{   
    // Lock the mutex to update the number of active readers
    pthread_mutex_lock(&mutex);
    numreader++;  // Increment the reader count

    // If this is the first reader, block writers by acquiring the semaphore
    if(numreader == 1) {
        sem_wait(&wrt); // First reader locks the shared resource for reading
    }

    // Unlock the mutex to allow other readers to increment numreader
    pthread_mutex_unlock(&mutex);

    // Reading section: read the shared resource
    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    // Lock the mutex to update the reader count again after reading
    pthread_mutex_lock(&mutex);
    numreader--;  // Decrement the reader count

    // If this is the last reader, release the semaphore to allow writers to access the resource
    if(numreader == 0) {
        sem_post(&wrt); // Last reader unlocks the shared resource for writers
    }

    // Unlock the mutex to allow other threads to update numreader
    pthread_mutex_unlock(&mutex);
}

/* 
 * Main function 
 * Creates and joins 10 reader threads and 5 writer threads.
 * Initializes and destroys the semaphore and mutex used for synchronization.
 */
int main()
{   
    pthread_t read[10], write[5]; // Thread arrays for readers and writers

    // Initialize the mutex and semaphore
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1); // Initialize semaphore to 1 (resource available)

    // Array used to number the readers and writers
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create 10 reader threads
    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }

    // Create 5 writer threads
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    // Wait for all reader threads to finish
    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }

    // Wait for all writer threads to finish
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    // Destroy the mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;   
}
