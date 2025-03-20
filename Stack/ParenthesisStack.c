#include <stdio.h>
#include <stdlib.h>

struct StackADT {
    char *stack;
    int top;
    int size;
};

void display(struct StackADT *s1) {
    if (s1->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s1->top; i >= 0; i--) {
        printf("%c\t", s1->stack[i]);
    }
    printf("\n");
}

struct StackADT* createStack(int size) {
    struct StackADT *s1 = (struct StackADT *)malloc(sizeof(struct StackADT));
    s1->stack = (char *)malloc(size * sizeof(char));
    s1->size = size;
    s1->top = -1;
    return s1;
}

void push(struct StackADT *s1, char n) {
    if (s1->top != (s1->size - 1)) {
        (s1->top)++;
        s1->stack[s1->top] = n;
    } 
    else {
        printf("Stack Overflow\n");
    }
}

char pop(struct StackADT *s1) {
    int ret = -1;
    if (s1->top != -1) {
        ret = s1->stack[s1->top];
        (s1->top)--;
    } 
    else {
        printf("Stack Underflow\n");
    }
    return ret;
}

char peek(struct StackADT *s1) {
    int up = -1;
    if (s1->top != -1) {
        printf("%c", s1->stack[s1->top]);
        up = s1->stack[s1->top];
    } 
    else {
        printf("Stack is empty!\n");
    }
    return up;
}

int isFull(struct StackADT *s1) {
    if ((s1->top + 1) == s1->size) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct StackADT *s1) {
    if (s1->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int bracketChecker(char exp[]){
    int len = 0;
    for(int i=0;exp[i]!='\0';i++){
        len++;
    }
    struct StackADT *s1 = createStack(len);

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(s1, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(s1)){
                return 0;
            }
            pop(s1);
        }
    }
    if(isEmpty(s1)){
        return 1;
    }
    return 0;
}

int main() {
    char exp[] = "(a*[b-c]/{c-d})";
    if (bracketChecker(exp)) {
        printf("Valid expression");
    } 
    else {
        printf("Invalid expression");
    }
    return 0;
}