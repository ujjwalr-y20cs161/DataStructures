//circluar queue using linked list

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int cnt = 0;
typedef struct Node{
        struct Node* prev;
        int data;
        struct Node* next;
}Node;

Node *fr = NULL, *rr =NULL ;

bool isEmpty(){
        if(fr == NULL && rr == NULL) return true;
        else return false;
}

void display(){
        if(isEmpty())printf("\n<< Empty >>");
        else{
                Node *temp = fr;
                printf("\n||");
                while( temp != rr){
                        printf(" %d ",temp->data);
                        temp =  temp->next ;
                }
                printf(" %d ",temp->data);
                printf("||");
        }
}

void EnqRr(int x){
        Node *temp;
        temp = malloc(sizeof(Node));
        temp->data = x;
        if(isEmpty()){
                fr = temp;
                rr = temp;
                temp->prev = rr;
                rr->next = fr;
        }
        else{
                rr->next = temp;
                temp->prev = rr;
                rr = rr->next;
                rr->next = fr;
                fr->prev = rr;
        }
        display();
}

void EnqFr(int x){
        Node *temp;
        temp = malloc(sizeof(Node));
        temp->data = x;

        if(isEmpty()){
                fr = temp;
                rr = temp;
                rr->next = fr;
                fr->prev = rr;
        }
        else{
                fr->prev = temp;
                temp->next = fr;
                fr = fr->prev;
                fr->prev = rr;
                rr->next = fr;
        }
        display();
}

int DeqFr(){
        Node *temp = fr;
        if(isEmpty())printf("\n<<Empty>>");
        else{
                rr->next = fr->next;
                fr = fr->next;
                fr->prev = rr;
                int c = temp->data;
                free(temp);
                display();
                return c;
        }
}

int DeqRr(){
        Node *temp = rr;
        if(isEmpty())printf("\n<<Empty>>");
        else{
                int x = rr->data;
                fr->prev = rr->prev;
                rr = rr->prev;
                rr->next = fr;
                free(temp);
                display();
                return x;
        }
}

void main(){
        EnqFr(5);
        EnqRr(7);
        EnqFr(10);
        EnqRr(14);
        DeqRr();
        DeqFr();
        EnqRr(21);
        EnqFr(15);
        for(int i=0;i<7;i++)DeqFr();

}

/* output::

              || 5 ||
              || 5  7 ||
              || 10  5  7 ||
              || 10  5  7  14 ||
              || 10  5  7 ||
              || 5  7 ||
              || 5  7  21 ||
              || 15  5  7  21 ||
              || 5  7  21 ||
              || 7  21 ||
              || 21 ||
              || 21 ||
*/
