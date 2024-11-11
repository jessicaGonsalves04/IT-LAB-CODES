#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt=1;
int numReaders=0;

void* reader (void *rno){
    pthread_mutex_lock(&mutex);
    numReaders++;
    if(numReaders==1){
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d:read count as %d\n",*((int*)rno),cnt);
    pthread_mutex_lock(&mutex);
    numReaders--;
    if(numReaders==0){
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}
void* writer (void *wno){
    sem_wait(&wrt);
    cnt=cnt*2;
    printf("Writer %d: modified count to %d\n",*((int *)wno),cnt);
    sem_post(&wrt);
}

int main(){
    int m,n;
    printf("Enter number of reader and writer resp");
    scanf("%d%d",&m,&n);
    pthread_t read[m],write[n];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&wrt,0,1);
    int k;
    if(m>=n){
        k=m;
    }
    else{
        k=n;
    }
    int arr[k];
    for(int i=0;i<k;i++){
        arr[i]=i+1;
    }
    //Create reader threads 
    for(int i=0;i<m;i++){
        pthread_create(&read[i],NULL,(void *)reader,(void *)&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        pthread_create(&write[i],NULL,(void *)writer,(void *)&arr[i]);
    }
    for(int i=0;i<m;i++){
        pthread_join(read[i],NULL);
    }
    for(int i=0;i<n;i++){
        pthread_join(write[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;

}
