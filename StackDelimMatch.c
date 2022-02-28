
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//--------------------------------------------stack---------------------------------------
#define sz 25

char stack[sz];
int top = -1;

bool isEmpty(){
        if(top == -1)return true;
        else return false;
}

bool isFull(){
        if(top == sz) return true;
        else return false;
}

void push(char c){
        if(isFull())printf("\t Overflow!");
        else stack[++top] = c;
}

char pop(){
        if(isEmpty())return;
        else return stack[top--];
}
char peek(){
    return stack[top];
}
//-----------------------------------------------------------------------------------

bool match(char a , char b){
    if((a == '(' && b == ')')||(a == '[' && b == ']')||(a == '{' && b == '}'))return true;
    else {
            printf("\n>> %c and %c \n",a,b);
            return false;
    }
}

void Expression(char exp []){
    int i = 0;
    char c = exp[i];
    
    while(c != '#'){
        if(c == '(' || c == '{' ||  c == '[') push(c);
        else if( c == ')' || c == '}' || c == ']')
        {   char x =  peek();
            if(!match(x,c)){
                printf("Failure! -->%d , %c",i+1,c);
                return;
            }
            pop();
        }
        i++;
        c = exp[i];
    }    
    if(isEmpty())printf("Success!");
    else printf("Failure!");

}

void main(){
    char exp[sz];
    scanf("%s",exp);
    strcat(exp,"#");
    printf("%s\n",exp);
    Expression(exp);
}

/*Test runs:
        one: {{[([]]}}
        output:         >> ( and ] 
                        Failure! -->7 , ]
                        
        two :   {([])}#
                Success!
