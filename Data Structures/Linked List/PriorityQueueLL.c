#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int priority;
	struct node* next;
};

struct node* first = NULL;

void enqueue(int elem, int pri){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->priority  = pri;
    temp->next = NULL;

    if(first == NULL || first->priority > temp->priority){
        temp->next = first;
        first = temp;
    }
    else{
        struct node* ptr = first;
        struct node* prev = NULL;
        while(ptr != NULL && ptr->priority <= temp->priority){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = temp;
        temp->next = ptr;
    }
}

void dequeue(){
	if(first == NULL){
		printf("Queue is Empty!\n");
	}
	else{
		struct node *temp = first;
		first = first->next;
		free(temp);
	}
}

void display(){
    if(first == NULL){
        printf("Queue is Empty!\n");
    }
    else{
        struct node *ptr = first;
	    printf("\nPriority : Data\n");
	    while(ptr != NULL){
		    printf("   %d     :  %d\n", ptr->priority, ptr->data);
		    ptr = ptr->next;
	    }
	    printf("\n");
    }
}

int main(){
    int opt;
    do{
        printf("Enter the follwing numbers to perform operations on Priority queue:\n");
        printf("1. To enqueue\n");
        printf("2. To dequeue\n");
        printf("3. To display\n");
        printf("4. To exit\n");
        scanf("%d",&opt);
        switch(opt){
            case 1: {
                int data, priority;
                printf("Enter the data: ");
                scanf("%d",&data);
                printf("Enter the priority: ");
                scanf("%d",&priority);
                enqueue(data, priority);
            }
            break;
            case 2: {
                dequeue();
            }
            break;
            case 3: {
                display();
            }
            break;
            case 4: {
                printf("Exiting the program!\n");
            }
            break;
            default:
            printf("Invalid choice!\n");
        }
    }while(opt != 4);
	return 0;
}