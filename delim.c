#include<stdio.h>

#define sz 10

char Stack[sz];
int top = -1;

int Full(){
    if(top ==  sz-1)return 1;
    else return 0;
}

int Empty(){
    if(top == -1)return 1;
    else return 0;
}

void push(char c){
    if(Full())printf("<< Full >>");
    else{Stack[++top] = c;}
}

char pop(){
    if(Empty) printf("<< Empty >>");
    else return Stack[top--];
}
int isDel(char c){
    if (c =='(' || c == '{'  || c == '[' ) return 1;
    else if( c == ')'|| c =='}'|| c == ']') return -1;
    else return 0;\
}

void Express(char x[]){
    char c;
    for( int i =0, c = x[i] ;c != '\0' ;i++){
        if()
    }
}
