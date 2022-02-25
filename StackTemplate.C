


#include<stdio.h>
#include<stdbool.h>

//--------------------------------------------stack---------------------------------------
#define sz 15

char stack[sz];
int top = -1;

bool isEmpty(){
        if(top == -1)return true;
        else return false;
}

bool isFull(){
        if(top == sz) return true;
        else return false;
}

void push(char c){
        if(isFull())printf("\t Overflow!");
        else stack[++top] = c;
}

char pop(){
        if(isEmpty())return;
        else return stack[top--];
}
//---------------------------------------------------------------------------------------
