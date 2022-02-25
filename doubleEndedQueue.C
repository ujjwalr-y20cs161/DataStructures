#include<stdio.h>
#include<stdbool.h>

#define z 10

int dq[z];

int fr = 0, rr = 0, cnt = 0;

bool isFull(){
        if((fr == 0 && rr == z-1)||(rr == fr -1)) return true;
        else return false;
}

bool isEmpty(){
        if( fr == rr) return true;
        else return false;
}

void display(){
        printf("\n||");
        for( int i = fr ; i!= rr ; i = (i+1)%z ) printf(" %d ",dq[i]);
        printf("||");
}

void EnqFr(int x){
        if( isFull() ) printf("\n<< Full >>");
        else {
                if( fr > 0) fr--;
                else fr = z-1;
                dq[fr] = x;
        }
        display();
}

void EnqRr( int x ){
        if(isFull() ) printf("\n<< Full >>");
        else {
                dq[rr] = x;
                rr = (rr+1)%z;
        }
        display();
}

int DeqFr(){
        if( isEmpty() ) printf("\n<< Empty >>");
        else{
                int c = dq[fr];
                fr = (fr+1)%z;
                display();
                return c;
        }
}

int DeqRr(){
        if( isEmpty() ) printf("\n<< Empty >>");
        else {
                int c = dq[rr];
                if(rr > 0) rr--;
                else rr = z-1;
                display();
                return c;
        }
}

void main(){
        EnqFr(5);
        EnqRr(7);
        EnqFr(10);
        EnqRr(14);
        DeqFr();
        DeqRr();
        EnqRr(21);
        EnqFr(15);
        for(int i =0;i<7 ;i++) DeqFr();
}

/* output::

                || 5 ||
                || 5  7 ||
                || 10  5  7 ||
                || 10  5  7  14 ||
                || 5  7  14 ||
                || 5  7 ||
                || 5  7  21 ||
                || 15  5  7  21 ||
                || 5  7  21 ||
                || 7  21 ||
                || 21 ||
                ||||
                << Empty >>
                << Empty >>
                << Empty >>
*/
