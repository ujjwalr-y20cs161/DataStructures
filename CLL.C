#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(Node *head,Node *tail){
    int ch,va;
    do{
    Node *newnode=(Node*)malloc(sizeof(Node));
    printf("Enter value::");
    scanf("%d",&va);
    newnode->data=va;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->next=head;
        tail->next=newnode;
        tail=newnode;
    }
    printf("Y(any num)/N(0)");
    scanf("%d",&ch);
    }while(ch);
    return head;
}

void display(Node *head){
    Node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    temp=temp->next;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

int main(){
    Node *head=NULL,*tail =NULL;
    head=create(head,tail);
    display(head);
}