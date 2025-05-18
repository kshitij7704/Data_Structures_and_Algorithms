#include<stdio.h>

int stack[20];
int top = -1;
#define MAX 20

void push(int elem){
    if(top == MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = elem;
    }
}

int pop(){
    int x = -1;
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x = stack[top];
        top--;
    }
    return x;
}

void peek(){
    if(top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is at top",stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        for(int i=top;i>0;i--){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

int isDigit(char exp){
    if(exp == '1' || exp == '2' || exp == '3' || exp == '4' || exp == '5' || exp == '6' || exp == '7' || exp == '8' || exp == '9' || exp == '0'){
        return 1;
    }
    else{
        return 0;
    }
}

void postfixEvaluator(char exp[]){
    for(int i=0;exp[i]!='\0';i++){
        if(isDigit(exp[i])){
            push(exp[i] - '0');
        }
        else{
            int val1 = pop();
            int val2 = pop();
            switch(exp[i]){
                case '+': {
                    push(val1+val2);
                }
                break;
                case '-': {
                    push(val1-val2);
                }
                break;
                case '*': {
                    push(val1*val2);
                }
                break;
                case '/': {
                    push(val1/val2);
                }
                break;
                default:
                printf("Invalid\n");
            }
        }
    }
    printf("Result is: %d",pop());
}

int main(){
    char exp[20] = "72+";
    postfixEvaluator(exp);
    return 0;
}