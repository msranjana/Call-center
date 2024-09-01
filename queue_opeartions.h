#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int isfull(){
    if((rear+1)%N==front){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(){
    if(front==-1&&rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int ele){
    if(!isfull()){
        if(front==-1&&rear==-1){
            front=rear=0;
            queue[rear].item=ele;
        }
        else
        {
            if(queue[(rear+1)%N].priority==1){
                queue[(rear+1)%N].priority=0;
                int i=rear;
                while(i!=front){
                    queue[(i+1)%N].item=queue[i].item;
                    i=(i+1)%N;
                }
                queue[front].item=ele;
                queue[front].priority=1;
                rear=(rear+1)%N;
                return;
            }
            rear=(rear+1)%N;
            queue[rear].item=ele;
        }
        count++;
    }
}

void dequeue(){
    if(!isempty()){
        if(front==rear){
            queue[front].item=0;
            front=rear=-1;
        }
        else{
            queue[front].item=0;
            front=(front+1)%N;
        }
        count--;
    }
}

int j=1;
int l=0;
void display(){
    if(l++==1)
        j=1;
    int k=j;
    int i=front;
    printf("QUEUE: ");
    while(i!=rear){
        if(queue[i].item==1){
            printf(" |CALLER %d| ",k++);
        }
        else{
            printf(" |YOU| ");
        }
        i=(i+1)%N;
    }
    if(queue[i].item==1){
        printf(" |CALLER %d|\n",k++);
    }
    else{
        printf(" |YOU|\n");
    }
    j++;
}