#define N 5
struct element{
    int item;
    int priority;
};
struct element queue[N];
int front=-1,rear=-1;
int count=0;