#include <stdio.h>
#include <stdlib.h>

struct StackADT{
    int *stack;
    int top;
    int size;
};


void display(struct StackADT *s1) {
    if (s1->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i=s1->top;i>=0;i--) {
        printf("%d\t", s1->stack[i]);
    }
    printf("\n");
}


struct StackADT* createStack(int size){
    struct StackADT *s1 = (struct StackADT *)malloc(sizeof(struct StackADT));
    s1->stack = (int *)malloc(s1->size * sizeof(int));
    s1->size = size;
    s1->top = -1;
    return s1;
}


void push(struct StackADT *s1, int n){
    if(s1->top != (s1->size-1)){
        (s1->top)++;
        s1->stack[s1->top] = n;
    }
    else{
        printf("Stack Overflow\n");
    }
}


void pop(struct StackADT *s1){
    if(s1->top != -1){
        (s1->top)--;
    }
    else{
        printf("Stack Underflow\n");
    }
}


void peek(struct StackADT *s1){
    if(s1->top != -1){
        printf("%d", s1->stack[s1->top]);
    }
    else{
        printf("Stack is empty!\n");
    }
}


int main(){
    int size, n, elem;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    struct StackADT *s1 = createStack(size);
    printf("\nHow many elemnts you want to enter: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", (i+1));
        scanf("%d", &elem);
        push(s1, elem);
    }
    printf("\nStack is: \n");
    display(s1);
    printf("\nAfter popping: \n");
    pop(s1);
    pop(s1);
    display(s1);
    printf("\nPeek function: \n");
    peek(s1);
    free(s1->stack);
    free(s1);
    s1 = NULL;
    return 0;
}