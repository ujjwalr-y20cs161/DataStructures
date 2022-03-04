//binary tree
#include<stdio.h>
#include<stdlib.h>

//------------------------------------------Node---------------------------------------------------------------------------------------
typedef struct Node{
        int data;
        struct Node* Lchild;
        struct Node* Rchild;
}
//---------------------------------------traversalS---and-display----------------------------------------------------------------------
void Inorder(Node* root){
        if(root != NULL){
                Inorder(root->Lchild);
                printf(" %d ",root->data);
                Inorder(root->Rchild);
        }
}

void Preorder(Node* root){
        if(root != NULL){
                Preorder(root->Lchild);
                Preorder(root->Rchild);
                printf(" %d ",root->data);
        }
}

void Postorder(Node *root){
        if(root != NULL){
                printf(" %d ",root->data);
                Postorder(root->Lchild);
                Postorder(root->Rchild);
        }
}

int min(Node *root){
        Node* tmp = root;
        while(tmp->Lchild != NULL) tmp = tmp->Lchild;

        printf(">>min:: %d\n",tmp->data);
        return tmp->data;
}

int max(Node *root){
        Node *tmp = root;
        while(tmp->Rchild != NULL) tmp = tmp->Rchild;

        printf(">>max:: %d\n",tmp->data);
        return tmp->data;
}
//---------------------------------------creation and deletion-------------------------------------------------------------------------
Node* insert(Node* root,int x){

        Node *tmp  = malloc(sizeof(Node));
        tmp ->data = x;
        tmp -> Lchild = NULL;
        tmp -> Rchild = NULL;

        if( root == NULL) root = tmp;

        else if( x > root->data) root->Rchild = tmp;

        else root -> Lchild = tmp;

        return root;
}
//--------------------------------------main-------------------------------------------------------------------------------------------

void main(){

}
