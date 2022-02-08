#include<stdio.h>

void insertSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int k=a[i];
        while(j>=0&&k<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
}

void display(int a[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void main(){
    int n=10;
    int a[10];
    for(int i=0;i<n;i++){
        if(i%2==0){
            a[i]=7*i+3;
        }
        else{
            a[i]=2*i+3;
        }
    }    

    display(a,n);
    insertSort(a,n);
    display(a,n);
}