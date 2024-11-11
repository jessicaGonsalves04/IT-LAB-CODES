#include<stdio.h>
struct Frame{
    int page;
    int timestamp;
};
int main(){
    int frame;
    int pages;
    printf("Enter the number of frames: ");
    scanf("%d",&frame);
    printf("Enter the number of pages: ");
    scanf("%d",&pages);
    struct Frame frameArray[frame];
    int incomingSequence[pages];
    printf("Enter the page sequence: ");
    for(int i=0;i<pages;i++){
        scanf("%d",&incomingSequence[i]);
    }
    for(int j=0;j<frame;j++){
        frameArray[j].page=-1;
        frameArray[j].timestamp=-1;
    }
    printf("Incoming\t");
    for(int i=0;i<frame;i++){
        printf("Frame%d\t",i+1);
    }
    printf("\n");
    int page;
    int pagefault=0;
    int check;
    int time=0;
    for(int m=0;m<pages;m++){
        page=incomingSequence[m];
        check=0;
        for(int n=0;n<frame;n++){
            if(page==frameArray[n].page){
                check=1;
                frameArray[n].timestamp=time++;
                break;
            }
        }
        if(check==0){
            int lruindex=0;
            int minTime=frameArray[0].timestamp;
            for(int i=1;i<frame;i++){
                if(frameArray[i].timestamp<minTime){
                    lruindex=i;
                    minTime=frameArray[i].timestamp;
                }
            }
            pagefault++;
            frameArray[lruindex].page=page;
            frameArray[lruindex].timestamp=time++;
        }
        printf("%d\t\t",page);
        for(int i=0;i<frame;i++){
            if(frameArray[i].page!= -1){
                printf("%d\t",frameArray[i].page);
            }
            else{
                printf("-\t");
            }
        }
        printf("\n");
    }
    printf("Total Page Fault: %d\n",pagefault);
}
