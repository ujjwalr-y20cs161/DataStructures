//stack implemention using arrays
//y20cs161--<uR21>
#include <stdio.h>
//header for the booleans
#include<stdbool.h>

//size of the stack
#define sz 10

//gloabl declarations
int stack[sz];
int top = -1;


bool isEmpty(){ 
    if(top==-1)return true;
    else return false;
}

void push(int a){
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

int pop(){
    // if top points to the bottom of the stack it results in Underflow
    if(isEmpty()){
        printf("Stack Underflow!");
        return;
    }
    //removes the last element and return it
    else return stack[top--];
}

int peek(){
    //just return the top element without removing
    return stack[top];
}

//main function
int main() {
    
	push(1);
	push(5);
	push(7);
//	printf("%d ",peek());
	for(int i=0;i<9;i++){
    //random inputting
	    push(i*4+3);
	}
	
	for(int i=0;!isEmpty();i++)printf("|%d ",pop());
	//return pop();
}


//	outputs::	Stack Overflow!|31 |27 |23 |19 |15 |11 |7 |3 |7 |5 |1 Stack Underflow!
