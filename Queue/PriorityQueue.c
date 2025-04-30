#include<stdio.h>

int queue[4][5];
int pointer[4][2];
int MAX = 5;

void initialize() {
    for (int i = 0; i < 4; i++) {
        pointer[i][0] = -1;
        pointer[i][1] = -1;
    }
}

void insert(int element, int priority) {
    int front = pointer[priority][0];
    int rear = pointer[priority][1];
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[priority][rear] = element;
    }
    else if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
    }
    else {
        rear = (rear + 1) % MAX;
        queue[priority][rear] = element;
    }
}

int delete(int priority) {
    int front = pointer[priority][0];
    int rear = pointer[priority][1];
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        int x = queue[priority][front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
        return x;
    }
}

void display(int priority) {
    int front = pointer[priority][0];
    int rear = pointer[priority][1];
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else {
        int i = front;
        do{
            printf("%d\t",queue[priority][i]);
        }while(i != (i +1) % MAX); 
        printf("\n");
    }
}

int main() {
    initialize();
    int n;
    do {
        printf("Enter the numbers for the following operations: \n");
        printf("1. For inserting a element\n");
        printf("2. For deleting a element\n");
        printf("3. For displaying\n");
        printf("4. To quit\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                int elem, pri;
                printf("Enter a element to insert: ");
                scanf("%d", &elem);
                printf("Enter the priority: ");
                scanf("%d", &pri);
                insert(elem, pri);
                display(pri);
            }
                break;
            case 2: {
                int pri;
                printf("Enter the priority: ");
                scanf("%d", &pri);
                delete(pri);
                display(pri);
            }
                break;
            case 3: {
                int pri;
                printf("Enter the priority: ");
                scanf("%d", &pri);
                display(pri);
            }
                break;
            case 4: {
                printf("Exiting the program!\n");
            }
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (n != 4);
    return 0;
}