#include <stdio.h>
#define MAX 100
#define NULL_VALUE 0

int stack[MAX];
int top = -1;


void push(int value) {
    if(top == MAX -1){
        printf("Stack overflow\n");
    }else{
        top++;
        stack[top]=value;
    }
}

void pop() {
    if(top == -1) {
        printf("Stack underflow\n");
    }else{
        stack[top] = NULL_VALUE;
        top--;
    }
}

void print_stack(){
    printf("Estado da pilha: ");
    if(top == -1){
        printf("Vazia");
    }else{
        int items = 0;
        for(int s : stack){
            if(s != NULL_VALUE){
                items++;
            }
        }
        printf("Quantidade atual de itens: %d \n", items);
    }
}

bool isEmpty() {
    return top == -1i;
}




int main() {
    
    push(10);
    push(12);
    print_stack();

    pop();
    pop();

    print_stack();
    
    return 0;
}
