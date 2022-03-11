//binary search tree

#include<stdio.h>
#include<stdlib.h>

//------------------------------------------Node---------------------------------------------------------------------------------------
typedef struct Node{
        int data;
        struct Node* Lchild;
        struct Node* Rchild;
}Node;
//---------------------------------------traversalS---and-display----------------------------------------------------------------------
void Inorder(Node* root){
        // printf(">>");
        if(root != NULL){
                Inorder(root->Lchild);
                printf(" %d ",root->data);
                Inorder(root->Rchild);
        }
        // printf("|");
}

void Preorder(Node* root){
        // printf(">>");
        if(root != NULL){
                printf(" %d ",root->data);
                Preorder(root->Lchild);
                Preorder(root->Rchild);
        }
        // printf("|");
}

void Postorder(Node *root){
        // printf(">>");
        if(root != NULL){
            Postorder(root->Lchild);
            Postorder(root->Rchild);
            printf(" %d ",root->data);
        }
        // printf("|");
}

int min(Node *root){
        Node* tmp = root;
        while(tmp->Lchild != NULL) tmp = tmp->Lchild;

        printf(">>min:: %d\n",tmp->data);
        return tmp->data;
}

Node* minNode(Node *root){
        Node* tmp = root;
        while(tmp->Lchild != NULL) tmp = tmp->Lchild;
        return tmp;
}

int max(Node *root){
        Node *tmp = root;
        while(tmp->Rchild != NULL) tmp = tmp->Rchild;

        printf(">>max:: %d\n",tmp->data);
        return tmp->data;
}

Node* search(Node* root, int x){
    if(x == root->data || root == NULL)return root;
    else if(x> root->data) return search(root->Rchild,x);
    else return search(root->Lchild,x);
}
void rprnt(Node* root){
    if(root != NULL)printf("##%d##",root->data);
}
//---------------------------------------creation and deletion-------------------------------------------------------------------------
Node* insert(Node* root,int x){


        
        if( root == NULL){
            Node *tmp  = malloc(sizeof(Node));
            tmp ->data = x;
            tmp -> Lchild = NULL;
            tmp -> Rchild = NULL;
            root = tmp;
            
        }
        else if(root->data == x);
        else if( x > root->data) root->Rchild = insert(root->Rchild,x);

        else root->Lchild = insert(root->Lchild,x);

        return root;
}

Node* deleteNode(Node* root,int key){

    if (root == NULL)
        return root;
 
    if (key < root->data)
        root->Lchild = deleteNode(root->Lchild, key);
 
    else if (key > root->data)
        root->Rchild = deleteNode(root->Rchild, key);

    else {
        if (root->Rchild == NULL) {
            Node* temp = root->Rchild;
            free(root);
            return temp;
        }
        else if (root->Rchild == NULL) {
            Node* temp = root->Lchild;
            free(root);
            return temp;
        }

        Node* temp = minNode(root->Rchild);
 
        root->data = temp->data;

        root->Rchild = deleteNode(root->Rchild, temp->data);
    }
    return root;
}

//--------------------------------------main-------------------------------------------------------------------------------------------

void main(){
    Node * root = NULL;
    root = insert(root,5);
    
    for(int i = 5;i<10;i++){
        if(i%2 == 0)root = insert(root,i*2+1);
        else root = insert(root,i-3);
        printf(">>");
        Inorder(root);
        printf("|\n");
    }
    root = insert(root,3);
    printf("delete:\n");
    deleteNode(root,6);
    printf(">>Inorder:");
    Inorder(root);
    printf("\n>>Postorder:");
    Postorder(root);
    printf("\n>>Preorder:");
    Preorder(root);
}

/*output::      >> 2  5 |
                >> 2  5  13 |
                >> 2  4  5  13 |
                >> 2  4  5  13  17 |
                >> 2  4  5  6  13  17 |
                delete:
                >>Inorder: 2  3  4  5  13  17 
                >>Postorder: 3  4  2  17  13  5 
                >>Preorder: 5  2  4  3  13  17 
