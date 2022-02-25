//circular queue
//
#include<stdio.h>

#define Z 10

int cq[Z];
int fr = 0, rr = 0, cnt = 0;

int  isFull(){
        if((fr == 0 && rr == Z-1)|| (rr == fr-1))return 1;
        else return 0;
}

int isEmpty(){
        if(fr == rr) return 1;
        else return 0;
}

void display(){
        printf("\n||");
        for( int i = fr ; i != rr ; i = (i+1)%Z ) printf(" %d ",cq[i]);
        printf("||");
}

void Enqueue(int x){
        if( isFull() ) printf("\n<< Full >>");
        else {
                cq[rr] = x;
                rr = (rr+1)%Z;
                cnt++;
                display();
        }
}

int Dequeue(){
        if( isEmpty() ) printf("\n<< Empty >>");
        else {
                cnt--;
                int y = cq[fr];
                fr = (fr+1)%Z;
                display();
                return Z;
        }
}

void Cmt(){printf("\n--count = %d --\n",cnt);}

void Dip(){
        printf("\n>>||");
        for( int i = 0 ; i < Z; i++){
                printf(" %d ",cq[i]);
        }
        printf("||");
}

void main(){
        for(int i =0; i<Z-1 ;i++){
                Enqueue(i+1);
        }
        // Cmt();
        // display();
        for(int i =0 ; i<Z-1 ;i++){
                Dequeue();
        }
        // Cmt();
        // display();
        // Dip();
        for(int  i = 1 ; i < 5 ;i++)Enqueue(2*i*10);
        // Dip();
}

/*output ::
                || 1 ||
                || 1  2 ||
                || 1  2  3 ||
                || 1  2  3  4 ||
                || 1  2  3  4  5 ||
                || 1  2  3  4  5  6 ||
                || 1  2  3  4  5  6  7 ||
                || 1  2  3  4  5  6  7  8 ||
                || 1  2  3  4  5  6  7  8  9 ||
                || 2  3  4  5  6  7  8  9 ||
                || 3  4  5  6  7  8  9 ||
                || 4  5  6  7  8  9 ||
                || 5  6  7  8  9 ||
                || 6  7  8  9 ||
                || 7  8  9 ||
                || 8  9 ||
                || 9 ||
                ||||
                || 20 ||
                || 20  40 ||
                || 20  40  60 ||
                || 20  40  60  80 ||
*/
