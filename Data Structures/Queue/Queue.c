#include<stdio.h>

int queue[20];
int front = -1, rear = -1, MAX = 20;

void insert(int element){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if(rear == MAX - 1){
        printf("Queue Overflow\n");
    }
    else{
        rear++;
        queue[rear] = element;
    }
}

int delete(){
    if(front == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        int x = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
        return x;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    do{
        printf("Enter the numbers for the following operations: \n");
        printf("1. For inserting a element\n");
        printf("2. For deleting a element\n");
        printf("3. For displaying\n");
        printf("4. To quit\n");
        scanf("%d",&n);
        switch(n){
            case 1: {
                int elem;
                printf("Enter a element to insert: ");
                scanf("%d",&elem);
                insert(elem);
                display();
            }
            break;
            case 2: {
                delete();
                display();
            }
            break;
            case 3: {
                display();
            }
            break;
            case 4: 
            break;
            default:
            printf("Invalid input!\n");
        }
    }while(n != 4);
    return 0;
}