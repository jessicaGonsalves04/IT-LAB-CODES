#include<pthread.h>
#include<stdio.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>


sem_t chopstick[5];

void *philosopher (void*);


void* philosopher(void* num){
    int phil=*(int*)num;
    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil+1)%5]);
    printf("Philospher %d has finished eating\n",phil);
    sem_post(&chopstick[(phil+1)%5]);
    sem_post(&chopstick[phil]);
}


int main(){
    for(int i=0;i<5;i++){
        sem_init(&chopstick[i],0,1);
    }
    pthread_t tid[5];
    int a[5];

    for(int i=0;i<5;i++){
        a[i]=i;
        pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
    }
    for(int i=0;i<5;i++){
        pthread_join(tid[i],NULL);
    }
    return 0;
}
