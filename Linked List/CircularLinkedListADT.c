#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createLinkedList(int size) {
    struct node* first = NULL;
    struct node* temp = NULL;
    struct node* ptr = NULL;

    for (int i = 0; i < size; i++) {
        int x;
        printf("Enter the data %d: ", i + 1);
        scanf("%d", &x);

        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;

        if (first == NULL) {
            temp->next = temp;
            first = temp;
        } else {
            ptr = first;
            while (ptr->next != first) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = first;
        }
    }
    return first;
}

void display(struct node* first) {
    struct node* ptr = first;
    if (first == NULL) {
        printf("Linked List is empty!\n");
    } else {
        do {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        } while (ptr != first);
        printf("\n");
    }
}

struct node* deleteNode(struct node* first, int data) {
    if (first == NULL) {
        printf("Linked List is empty!\n");
    } else {
        struct node* current = first;
        struct node* prev = NULL;

        do {
            if (current->data == data) {
                if (current == first) {
                    struct node* last = first;
                    while (last->next != first) {
                        last = last->next;
                    }
                    first = first->next;
                    last->next = first;
                } else {
                    prev->next = current->next;
                }
                printf("%d deleted\n", current->data);
                free(current);
                break;
            }
            prev = current;
            current = current->next;
        } while (current != first);

        if (current == first) {
            printf("%d not found in the list\n", data);
        }
    }
    return first;
}

struct node* insert(struct node* first, int elem) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = elem;
    temp->next = NULL;

    if (first == NULL) {
        temp->next = temp;
        first = temp;
    } else {
        int opt;
        printf("Enter the following from the choices to insert:\n");
        printf("1. For first node insertion\n");
        printf("2. For last node insertion\n");
        printf("3. For middle node insertion\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                struct node* last = first;
                while (last->next != first) {
                    last = last->next;
                }
                temp->next = first;
                last->next = temp;
                first = temp;
                break;
            }
            case 2: {
                struct node* last = first;
                while (last->next != first) {
                    last = last->next;
                }
                last->next = temp;
                temp->next = first;
                break;
            }
            case 3: {
                int pos;
                printf("Enter position to insert: ");
                scanf("%d", &pos);

                if (pos <= 1) {
                    struct node* last = first;
                    while (last->next != first) {
                        last = last->next;
                    }
                    temp->next = first;
                    last->next = temp;
                    first = temp;
                } else {
                    struct node* current = first;
                    int i = 1;

                    while (i < pos - 1 && current->next != first) {
                        current = current->next;
                        i++;
                    }

                    temp->next = current->next;
                    current->next = temp;
                }
                break;
            }
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return first;
}

void search(struct node* first, int elem) {
    int flag = 0;
    int i = 0;
    struct node* ptr = first;
    do {
        i++;
        if (ptr->data == elem) {
            printf("Found %d at node number %d\n", elem, i);
            flag = 1;
            break;
        }
        ptr = ptr->next;
    } while (ptr != first);

    if (flag == 0) {
        printf("%d is not found\n", elem);
    }
}

void update(struct node* first, int cur, int next) {
    int flag = 0;
    struct node* ptr = first;
    do {
        if (ptr->data == cur) {
            ptr->data = next;
            printf("Updated %d in place of %d\n", next, cur);
            flag = 1;
            break;
        }
        ptr = ptr->next;
    } while (ptr != first);

    if (flag == 0) {
        printf("%d is not found\n", cur);
    }
}

int main() {
    int size, opt;
    printf("Enter the size of circular Linked List to create: ");
    scanf("%d", &size);
    struct node* l1 = createLinkedList(size);

    do {
        printf("Enter the following from the choices to perform operations on circular Linked List:\n");
        printf("1. For insertion\n");
        printf("2. For deletion\n");
        printf("3. For display\n");
        printf("4. For update operation\n");
        printf("5. For searching\n");
        printf("6. To exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                int elem;
                printf("Enter an element to insert: ");
                scanf("%d", &elem);
                l1 = insert(l1, elem);
                display(l1);
                break;
            }
            case 2: {
                int elem;
                printf("Enter an element to delete: ");
                scanf("%d", &elem);
                l1 = deleteNode(l1, elem);
                display(l1);
                break;
            }
            case 3: {
                display(l1);
                break;
            }
            case 4: {
                int cur, next;
                printf("Enter the element to update: ");
                scanf("%d", &cur);
                printf("\nEnter the new element to insert: ");
                scanf("%d", &next);
                update(l1, cur, next);
                display(l1);
                break;
            }
            case 5: {
                int elem;
                printf("Enter the element to search: ");
                scanf("%d", &elem);
                search(l1, elem);
                break;
            }
            case 6: {
                printf("Exiting the program!\n");
                break;
            }
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (opt != 6);
    struct node* next = NULL;

    do {
        next = l1->next;
        free(l1);
        l1 = next;
    } while (next != l1);

    return 0;
}