//y20cs161 Doubly Linkedlist

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node* prev;
        struct node* next;
}Node;

Node* create(Node* head){
        printf("--------------creation of DLL-----------------\n");
        Node* newnode,*tail;
        int val;
        char ch;
        do{
                printf("Val::");
                scanf("%d",&val);
                newnode=malloc(sizeof(Node));
                newnode->data=val;
                newnode->next=NULL;
                newnode->prev=NULL;
                if(head==NULL){
                        head=newnode;
                        tail=newnode;
                }
                else{
                        tail->next=newnode;
                        newnode->prev=tail;
                        tail=newnode;
                }
                printf("Continue:Y/N::");
                getchar();
                scanf("%c",&ch);
        }while(ch=='Y'||ch=='y');
        return head;
}

void display(Node *head){
        printf("\n---------------------Display-----------------\n");
        Node* temp=head;
        while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
        }
        printf("\n----------------\n");
}

Node* insertBeg(Node* head){
        printf("----------------------Insertion at the Begining---------\n");
        Node* newnode;
        int val;
        printf("Val::");
        scanf("%d",&val);
        newnode=malloc(sizeof(Node));
        newnode->data=val;
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
}

Node* insertPos(Node* head){
        printf("\n------------Insert at a Postion--------\n");
        Node* newnode,*temp=head;
        int val,pos;
        printf("Val::");
        scanf("%d",&val);
        printf("POS::");
        scanf("%d",&pos);
        for(int i=1;i<pos;i++){
                temp=temp->next;
        }
        newnode=malloc(sizeof(Node));
        newnode->data=val;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next->prev=newnode;
        temp->next= newnode;
        return head;
}
int count(Node* head){
        Node* temp=head;
        int c=0;
        while(temp!=NULL){
                c++;
                temp=temp->next;
        }
        return c;
}


void main(){
        Node *head=NULL;
        head=create(head);
        display(head);
        head=insertBeg(head);
        display(head);
        head=insertPos(head);
        display(head);
        printf("%d is nodes\n",count(head));
}
