#include<stdio.h>
#include"queue_opeartions.h"
#include<stdlib.h>
#include<time.h>
void run(){
    srand(time(0));
    int n=rand()%6;
    for(int i=0;i<n;i++){
        enqueue(1);
    }
}