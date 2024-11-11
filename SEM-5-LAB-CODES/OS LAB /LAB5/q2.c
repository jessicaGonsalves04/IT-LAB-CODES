#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
void sort_strings(char *arr[],int n){
    char *temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(arr[i],arr[j])>0){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(int argc, char *argv[]){
    if(argc<2){
        printf("Enter the elements in command line.");
        return 1;
    }
    pid_t pid;
    pid=fork();
    if(pid<0){
        printf("Fork unsuccesful.");
        return 1;
    }
    
    else if(pid==0){
        sort_strings(argv+1,argc-1);
        printf("The sorted array is :\n");
        for(int i=1;i<argc;i++){
            printf("%s\n",argv[i]);
        }
        exit(0);//exit from child process
    }

    else{
        wait(NULL);
        printf("Unsorted array is:\n");
        for(int i=1;i<argc;i++){
            printf("%s\n",argv[i]);
        }
    }
}