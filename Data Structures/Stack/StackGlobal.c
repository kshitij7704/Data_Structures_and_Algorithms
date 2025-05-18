#include <stdio.h>
#include <stdlib.h>

struct StackADT {
    int *stack;
    int top;
    int size;
};
struct StackADT s1;


void display() {
    if (s1.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s1.top; i >= 0; i--) {
        printf("%d\t", s1.stack[i]);
    }
    printf("\n");
}


void push(int n) {
    if (s1.top != (s1.size - 1)) {
        (s1.top)++;
        s1.stack[s1.top] = n;
    } else {
        printf("Stack Overflow\n");
    }
}


void pop() {
    if (s1.top != -1) {
        (s1.top)--;
    } else {
        printf("Stack Underflow\n");
    }
}


void peek() {
    if (s1.top != -1) {
        printf("%d\n", s1.stack[s1.top]);
    } else {
        printf("Stack is empty!\n");
    }
}


void createStack(int size) {
    s1.stack = (int *)malloc(size * sizeof(int));
    s1.size = size;
    s1.top = -1;
}


int main() {
    int size, n, elem;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    createStack(size);
    printf("How many elements you want to enter: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &elem);
        push(elem);
    }
    printf("\nStack is: \n");
    display();
    printf("\nAfter popping: \n");
    pop();
    pop();
    display();
    printf("\nPeek function: \n");
    peek();
    free(s1.stack);
    s1.stack = NULL;
    return 0;
}