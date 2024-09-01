#include<conio.h>
#include"processed_queue.h"
#include"time.h"
void message(char *msg){
    int c=0;
    while(1){
        printf("\n");
        printf(msg);
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        printf("\33[2K\033[A\r");
        if(c==1)
            break;
        c++;
    }
}
int main(){
    run();
    printf("--------------------WELCOME--------------------\n");
    if(isfull()){
        printf("THE QUEUE IS FULL\n");
    }
    else{
        if(count!=0)
            display();
        printf("\nTHERE ARE %d CALLER(S) IN QUEUE\n",count);
    }
    int choice;
    printf("DO YOU WANT TO GO ON CALL? (1-YES 0-NO): ");
    scanf("%d",&choice);
    if(choice==0){
        printf("THANK YOU FOR YOUR TIME!");
        exit(0);
    }
    if(isfull()){
        printf("\nALL OPEARTORS ARE BUSY!\nWE ARE SORRY FOR THE INCONVENIENCE!\nPLEASE WAIT:\n");
        printf("\n%d CALLER(S) REMAINING! WAIT FOR A SLOT!\n",count);
        display();
        message("WAIT");
        dequeue();
        printf("\n%d CALLER(S) REMAINING BEFORE YOU\n",count);
        display();
        goto label;
    }
    else{
        int ans;
        label:
        if(count>0){
            printf("\nIS THE CALL AN EMERGENCY (1-YES, 0-NO):\n");
            scanf("%d",&ans);
        }
        else{
            ans=1;
        }
        if(ans==1){
            printf("\nYOU HAVE BEEN SKIPPED TO THE FRONT OF THE QUEUE");
            queue[(rear+1)%N].priority=1;
            enqueue(2);
            printf("\nYOU ARE ON THE CALL!\n");
            display();
            printf("\nPLEASE TALK!");
            for(int i=0;i<3;i++)
                message("TALKING");
            printf("\nTHE CALL HAS ENDED");
            printf("\nTHANK YOU FOR YOUR TIME!");
        }
        else{
            enqueue(2);
            int temp_count=count;
            while(queue[front].item!=2){
                printf("\n%d CALLER(S) REMAINING BEFORE YOU\n",--temp_count);
                display();
                message("WAIT");
                dequeue();
                for(int i=0;i<N+1-count;i++)
                    enqueue(1);
            }
            printf("\n");
            printf("\nYOU ARE ON THE CALL!\n");
            display();
            printf("\nPLEASE TALK!");
            for(int i=0;i<3;i++)
                message("TALKING");
            printf("\nTHE CALL HAS ENDED");
            printf("\nTHANK YOU FOR YOUR TIME!");
        }
    }
    return 0;
}