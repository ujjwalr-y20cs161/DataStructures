









#include<stdio.h>
#include<stdbool.h>

//---------------------------------queue---------------------------

#define sz 20
int Q[sz];
int fr = 0, rr = 0;

bool isFull(){
        if(fr == 0 && rr == sz-1) return true;
        else return false;
}

bool isEmpty(){
        if(fr == rr) return true;
        else return false;
}

void Enq(int x){
        if(isFull())printf("Queue Full!"){
