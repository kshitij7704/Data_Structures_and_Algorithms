#include<stdio.h>

int queue[20];
int front = -1, rear = -1, MAX = 20;

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if((rear + 1) % MAX == front){
        return 1;
    }
    else return 0;
}

void display(){
    if(!isEmpty()){
        printf("Elements in queue are: \n");
        int i = front;
        do{
            printf("%d\t",queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
    else{
        printf("Queue is empty\n");
    }
}

void insert(int val){
    if(!isFull()){
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        else{
            rear = (rear + 1) % MAX;
            queue[rear] = val;
        }
    }
    else{
        printf("Queue Overflow\n");
    }
}

int delete(){
    int x = -1;
    if(!isEmpty()){
        x = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % MAX;
        }
    }
    else{
        printf("Queue Underflow\n");
    }
    return x;
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
                int del = delete();
                printf("%d deleted\n",del);
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