//y20cs161 circular linkedlist

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node* next;
}Node;

Node* create(Node* head){
        printf("Creating a Circular Linkedlist!\n");
        Node* newnode,*tail;
         int val;
         char ch;
         do{
                 newnode=(Node*)malloc(sizeof(Node));
                 printf("Enter val?::");
                 scanf("%d",&val);
                 newnode->data=val;
                 newnode->next=NULL;
                 if(head==NULL){
                         head=newnode;
                         tail=newnode;
                 }                 
		 else{
                         tail->next=newnode;
                         tail=newnode;
                         tail->next=head;
                 }
                 printf("Continue? Y/N:");
                 getchar();
                 scanf("%c",&ch);
         }while(ch=='Y'||ch=='y');
         return head;
}

void display(Node* head){
        printf("--------Display------\n");        Node* temp=head;
        do{
                printf("%d ",temp->data);
                temp=temp->next;
        }while(temp!=head);
        printf("\n--------------\n");
}

Node* insertBeg(Node* head){
        printf("-------Insert at the Begin-----\n");

        Node* newnode,*tail,*temp;
        temp=head;
        while(temp->next!=head){
                temp=temp->next;
        }
        tail=temp;


        int val;
        printf("Val to Insert::");
        scanf("%d",&val);

        newnode=malloc(sizeof(Node));
        newnode->data=val;
        newnode->next=head;
        head=newnode;
        tail->next=newnode;

        return head;
}

Node* insertEnd(Node* head){
        printf("-------------INSERT AT END------------\n");
        Node* newnode,*temp;
        temp=head;
        while(temp->next!=head){
                temp=temp->next;
        }
        newnode=malloc(sizeof(Node));
        int val;
        printf("Val to Insert::");
        scanf("%d",&val);

        newnode->data=val;
        newnode->next=head;
        temp->next=newnode;
        return head;
}
Node* insertPos(Node* head){
        printf("-------------Insert at Position---------\n");
        Node* newnode,*temp;
        temp=head;
        int val,pos;
        printf("Val to Insert::");
        scanf("%d",&val);
        printf("Enter POS::");
        scanf("%d",&pos);

        newnode=malloc(sizeof(Node));
        newnode->data=val;
        for(int i=0;i<pos;i++){
                temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

        return head;
}

Node* deletePos(Node* head){
        printf("------------Delete POS-----not for 1st positon------------\n");
        Node* temp=head,*q;
        int pos;
        printf("Enter the position::");
        scanf("%d",&pos);
        for(int i=1;i<pos-1;i++)
                temp=temp->next;
        q=temp->next;
        temp->next=temp->next->next;
        free(q);
        return head;
}
Node* deleteBeg(Node* head)
{
        printf("-----------Delete head-------------\n");
        Node* temp=head;
        while(temp->next!=head){
                temp=temp->next;
        }
        temp->next=head->next;
        free(head);
        head=temp->next;
        return head;
}

void main(){
        Node* head=NULL;
        head=create(head);
        display(head);
        head=insertBeg(head);
        display(head);
        head=insertEnd(head);
        display(head);
        head=insertPos(head);
        display(head);
        head=deleteBeg(head);
        display(head);
        head=deletePos(head);
        display(head);
}

/*
	output::
			Creating a Circular Linkedlist!
			Enter val?::5
			Continue? Y/N:y
			Enter val?::10
			Continue? Y/N:y
			Enter val?::17
			Continue? Y/N:n
			--------Display------
			5 10 17 
			--------------
			-------Insert at the Begin-----
			Val to Insert::21
			--------Display------
			21 5 10 17 
			--------------
			-------------INSERT AT END------------
			Val to Insert::14
			--------Display------
			21 5 10 17 14 
			--------------
			-------------Insert at Position---------
			Val to Insert::7
			Enter POS::3
			--------Display------
			21 5 10 17 7 14 
			--------------
			-----------Delete head-------------
			--------Display------
			5 10 17 7 14 
			--------------
			------------Delete POS-----not for 1st positon------------
			Enter the position::3
			--------Display------
			5 10 7 14 
			--------------
