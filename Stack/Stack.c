#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int size, int *top, int n) {
    if (*top != (size - 1)) {
        (*top)++;
        stack[*top] = n;
    } else {
        printf("Stack Overflow\n");
    }
}

void pop(int stack[], int *top) {
    if (*top != -1) {
        (*top)--;
    } else {
        printf("Stack Underflow\n");
    }
}

void peek(int stack[], int *top){
    if(*top!=-1){
        printf("%d", stack[*top]);
    }
    else{
        printf("Stack is Empty!\n");
    }
}


void display(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = *top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[20] = {1, 2, 3, 4, 5};
    int size = 20;
    int top = 4;

    display(stack, &top);
    push(stack, size, &top, 77);
    display(stack, &top);
    pop(stack, &top);
    display(stack, &top);
    peek(stack, &top);

    return 0;
}