#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#define MAXCAPACITY 100

int buff[MAXCAPACITY];
sem_t pmutex, cmutex,full,empty;
int in=1,out=1;
int item=0;
int status=0;

void* produce(void *arg){
    sem_wait(&empty);//wait if not empty
    item++;
    sem_wait(&pmutex);//lock on producer
    buff[in]=item;
    printf("Produced data %d\n", buff[in]);
    in=(in%MAXCAPACITY)+1;
    sem_post(&pmutex);
    sem_post(&full);
    return 0;

}

void* consume(void *arg){
    int citem=0;
    sem_wait(&full);//there are no items to consume
    sem_wait(&cmutex);
    citem=buff[out];
    printf(" Consumed Data = %d\n",buff[out]);
    	out= out % MAXCAPACITY + 1;
    	sem_post(&cmutex);
    	sem_post(&empty);
   	 return 0;
}

int main(int argc , const char *argv[]){

    in=1; //in:  Producers insert items (i.e., the index of the next available empty slot).
    out=1;//out: Consumers retrieve items (i.e., the index of the next available filled slot).
    int i,NumThreads;
    sem_init(&pmutex,0,1);//implying that the pmutex is unlocked 
    sem_init(&cmutex,0,1);//imply that cmutex is unlocked 
    sem_init(&full,0,0);//initialize full to 0
    sem_init(&empty,0,MAXCAPACITY);//initialize empty to max capacity

    pthread_t *producers,*consumers;
    NumThreads=abs(atoi(argv[1]));//argv[1]:command line argument. atoi: converts string to int. abs:removes negative value.
    producers=(pthread_t *)malloc(sizeof(pthread_t)*NumThreads);//to store producer threads
    consumers=(pthread_t *)malloc(sizeof(pthread_t)*NumThreads);//to store consumer threads

    //Loop to create porducer and consumer threads
    for(i=0;i<NumThreads;i++){
        pthread_create(&consumers[i],NULL,&consume,NULL);//consume is the function the thread will run and NULL to the right is the argument which will be passed
        pthread_create(&producers[i],NULL,&produce,NULL);
    }
    //wait for threads to complete 
    for (i = 0; i < NumThreads; i++)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }
return 0;
}