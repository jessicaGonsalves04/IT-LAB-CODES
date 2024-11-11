#include<stdio.h>
#include<limits.h>
struct Frame{
    int page;
    int futureIndex;
};
int findFutureIndex (int page,int incomingSeq[],int currentIndex, int pages){
    for(int i=currentIndex+1;i<pages;i++){
        if(incomingSeq[i]==page){
            return i;
        }
    }
    return INT_MAX;
}
int main(){
    int frame,pages;
    printf("Enter the number of frames: ");
    scanf("%d",&frame);
    printf("Enter the number of pages: ");
    scanf("%d",&pages);
    int incomingSequence[pages];
    printf("Enter the incoming sequence:\n");
    for(int i=0;i<pages;i++){
        scanf("%d",&incomingSequence[i]);
    }
    struct Frame frameArray[frame];
    int pageFault=0;
    int check;
    for(int i=0;i<frame;i++){
        frameArray[i].page=-1;
        frameArray[i].futureIndex=-1;
    }
    printf("\nIncoming\t");
    for(int i=0;i<frame;i++){
        printf("Frame%d\t",i+1);
    }
    printf("\n");
    // Main LOOP
    for(int i=0;i<pages;i++){
        int page=incomingSequence[i];
        check=0;
        for(int j=0;j<frame;j++){
            if(frameArray[j].page==page){
                check=1;
                frameArray[j].futureIndex=findFutureIndex(page,incomingSequence,i,pages);
                break;
            }
        }

        int replaceIndex=-1;
        int farthestIndex=-1;

        if(check==0){
            //Check if there is an empty frame
            for(int i=0;i<frame;i++){
                if(frameArray[i].page==-1){
                    replaceIndex=i;
                    break;
                }
            }
            //If there is no empty frame then find the farthest used
            if(replaceIndex==-1){
                for(int i=0;i<frame;i++){
                    if(frameArray[i].futureIndex>farthestIndex){
                        replaceIndex=i;
                        farthestIndex=frameArray[i].futureIndex;
                    }
                }
            }
            frameArray[replaceIndex].page = page;
            frameArray[replaceIndex].futureIndex = findFutureIndex(page, incomingSequence, i, pages);
            pageFault++;
            printf("%d\t\t",page);
            for(int i=0;i<frame;i++){
                if(frameArray[i].page!=-1){
                    printf("%d\t",frameArray[i].page);
                }
                else{
                    printf("-\t");
                }
            }
            printf("\n");
        }
        
    }
printf("Total Page Fault: %d",pageFault);
    
    
}