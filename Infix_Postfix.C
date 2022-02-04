{
#include <stdio.h>
#include<ctype.h>
#include<stdbool.h>

#define sz 10
char epr[sz];
char stack[sz];
int top = -1;

bool isEmpty(){ 
    if(top==-1)return true;
    else return false;
}

void push(char a){
    //if the top points the size and if pushed results in Overflow
    if(top>=sz){
        printf("Stack Overflow!");
        return;
    }
    else{
        //incrementing the top and push
        top++;
        stack[top] = a;
    }
}

char pop(){
    // if top points to the bottom of the stack it results in Underflow
    if(isEmpty()){
        printf("Stack Underflow!");
        return '#';
    }
    //removes the last element and return it
    else return stack[top--];
}
char peek(){
    //just return the top element without removing
    return stack[top];
}
}
void Eval(char ex[]){
    int i=0;
    while(ex[i]!='\0'){
        char c = ex[i];
        if(isalpha(c))printf("%c",c);
        else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%'||c=='^'||c=='(')push(c);
        i++;
    }
    while(!isEmpty()){printf("%c",pop());}
}

int main(void) {
	
	scanf("%s",epr);
	Eval(epr);
	return 0;
}

