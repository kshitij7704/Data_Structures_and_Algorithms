#include <stdio.h>
#include <stdlib.h>

struct StackADT {
    char *stack;
    int top;
    int size;
};

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
    char ret = '\0';
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
    char up = '\0';
    if (s1->top != -1) {
        up = s1->stack[s1->top];
    }
    return up;
}

char isEmpty(struct StackADT *s1) {
    if (s1->top == -1) {
        return 1;
    } 
    else {
        return 0;
    }
}

int precedence(char exp) {
    if (exp == '^') {
        return 3;
    } 
    else if (exp == '*' || exp == '/' || exp == '%') {
        return 2;
    } 
    else if (exp == '+' || exp == '-') {
        return 1;
    } 
    else {
        return 0;
    }
}

int isOperator(char exp) {
    if(exp == '+' || exp == '-' || exp == '*' || exp == '/' || exp == '%' || exp == '^'){
        return 1;
    }
    else{
        return 0;
    }
}

int length(char *exp) {
    int n = 0;
    while (exp[n] != '\0') {
        n++;
    }
    return n;
}

char* reverse(char *exp){
    char temp;
    int start = 0;
    int end = length(exp) - 1;
    while(start < end){
        temp = exp[start];
        exp[start] = exp[end];
        exp[end] = temp;
        start++;
        end--; 
    }
    return exp;
}

char* infixToPrefix(char *infix) {
    int len = length(infix);
    struct StackADT *s1 = createStack(len);
    char *prefix = (char *)malloc((len) * sizeof(char));
    int i = len-1, j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ')') {
            push(s1, infix[i]);
            i--;
        } 
        else if (infix[i] == '(') {
            while (!isEmpty(s1) && peek(s1) != ')') {
                prefix[j] = pop(s1);
                j++;
            }
            if (!isEmpty(s1) && peek(s1) == ')') {
                pop(s1);
            }
            i--;
        } 
        else if (!isOperator(infix[i])) {
            prefix[j] = infix[i];
            i--;
            j++;
        } 
        else {
            while (!isEmpty(s1) && precedence(infix[i]) < precedence(peek(s1))) {
                prefix[j] = pop(s1);
                j++;
            }
            push(s1, infix[i]);
            i--;
        }
    }
    while (!isEmpty(s1)) {
        prefix[j] = pop(s1);
        j++;
    }

    prefix[j] = '\0';

    free(s1->stack);
    free(s1);

    return reverse(prefix);
}

int main() {
    char *exp = "(A+B)-(C*D/E+F)+(G*K)";
    printf("Infix is: %s\n", exp);

    char *pre = infixToPrefix(exp);
    printf("Prefix is: %s\n", pre);

    free(pre);

    return 0;
}