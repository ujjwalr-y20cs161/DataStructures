#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *head=NULL,*tail=NULL;
void create(){
    Node* newnode;
    int val,c;
    do{
    printf("Enter the value:");
    scanf("%d",&val);
    newnode=malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    printf("Y(any number)/N(0):");
    fflush(stdin);
    scanf("%d",&c);
    }while(c);
}

void display(){
    Node *temp=head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertBeg(){
    Node* newnode;
    int val;
    newnode=malloc(sizeof(Node));
    printf("\nval to insert[Begin]:");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void insertEnd(){
    Node* newnode;
    int val;
    newnode=malloc(sizeof(Node));
    printf("\nval to insert[End]:");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;
    tail->next=newnode;
    tail=newnode;
}
 
void insertPos(){
    Node *newnode,*temp=head;
    int val,P;
    newnode=(Node*)malloc(sizeof(Node));
    printf("\nval to insert[after the Pos]:");
    scanf("%d",&val);
    printf("position to insert:");
    scanf("%d",&P);
    for(int i=0;i<P;i++)
    {
        temp=temp->next;
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}

void deleteBeg(){
    Node *temp;
    temp=head->next;
    free(head);
    head=temp;
    printf("\n~");
}

void deleteEnd(){
    printf("\n");
    Node *temp=head;
    while(temp->next!=tail){
        temp=temp->next;
    }
    free(temp->next);
    tail=temp;
    tail->next=NULL;

}

void deletePos(){
    Node *temp=head,*q;
    int p;
    printf("\nPos to delete:");
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        temp=temp->next;
    }
    q=temp->next->next;
    free(temp->next);
    temp->next=q;
}

void main(){
    create();
    display();
    insertBeg();
    display();
    insertEnd();
    display();
    insertPos();
    display();
    deletePos();
    display();
}

/* output::
                Enter the value:5
                Y(any number)/N(0):5
                Enter the value:6
                Y(any number)/N(0):0
                5 6 
                val to insert[Begin]:4
                4 5 6 
                val to insert[End]:7
                4 5 6 7 
                val to insert[after the Pos]:2
                position to insert:2
                4 5 6 2 7 
                Pos to delete:2 
                4 5 6 7 
