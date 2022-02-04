//stack implementation using S Linked Lists
//y20cs161--<uR21>

#include <stdio.h>
//header for the booleans and memory allocation
#include<stdbool.h>
#include<stdlib.h>

//Node definition
typedef struct node{
    int data;
    struct node* next;
}Node;

//head acts as the top pointer here
Node* head = NULL;

//isEmpty()
/* always use isEmpty()
    but not isEmpty,
    because isEmpty() is a function */
bool isEmpty(){
    if(head == NULL) return true;
    else return false;
}

/*push as in Linked Lists Overflow is not that often encountered,
until the heap is full hence we neglect Overflow condition!*/
void push(int a){
    Node* nnode;
    nnode = malloc(sizeof(Node));
    nnode->data = a;
    nnode->next = head;
    head = nnode; 
}

//pop
int pop(){
    if(head != NULL){
        Node *temp = head;
        int x = head->data;
        head = head->next;
        //freeing the unncessary Nodes
        free(temp);
        return x;
    }
    else printf("Stack Underflow!");
}

int peek(){
    if(!isEmpty()) return head->data;
    else return -1;
}

void display(){
    Node *temp = head;
    while(temp != NULL){
        printf("|%d|",temp->data);
        temp = temp->next;
    }
}

int main(){
    push(3);
    push(4);
    push(5);
    display();
    for(int i=0;!isEmpty();i++) printf("%d |", pop());
    push(70);
    printf("%d##%d##",isEmpty(),peek());
}


//  outputs:: |5||4||3|5 |4 |3 |0##70##
