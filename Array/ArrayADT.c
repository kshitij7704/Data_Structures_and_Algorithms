#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *arr;
    int size;
    int elem;
};

struct Array* createArray(int size) {
    struct Array *a1 = (struct Array *)malloc(sizeof(struct Array));
    a1->arr = (int *)malloc(size * sizeof(int));
    a1->size = size;
    a1->elem = 0;
    return a1;
}

int addElem(struct Array* a1) {
    int n;
    printf("Enter how many elements you want to enter: ");
    scanf("%d", &n);
    if (a1->size < n) {
        printf("Array cannot hold this many elements.\n");
        exit(1);
    } else {
        for (int i = 0; i < n; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &a1->arr[i]);
        }
        a1->elem = n; // Update the element count
    }
    return n;
}

void traverse(struct Array* a1) {
    for (int i = 0; i < a1->elem; i++) {
        printf("%d\t", a1->arr[i]);
    }
    printf("\n");
}

void display(struct Array* a1) {
    for (int i = 0; i < a1->elem; i++) {
        printf("%d\t", a1->arr[i]);
    }
    printf("\n");
}

void sort(struct Array* a1) {
    int temp = 0, min, index;
    for (int i = 0; i < (a1->elem - 1); i++) {
        min = a1->arr[i];
        index = i;
        for (int j = i + 1; j < a1->elem; j++) {
            if (a1->arr[j] < min) {
                min = a1->arr[j];
                index = j;
            }
        }
        if (index != i) {
            temp = a1->arr[i];
            a1->arr[i] = a1->arr[index];
            a1->arr[index] = temp;
        }
    }
}

void search(struct Array* a1, int s) {
    short flag = 1;
    for (int i = 0; i < a1->elem; i++) {
        if (a1->arr[i] == s) {
            printf("Found %d at %d index\n", s, i + 1);
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("Element is not present in the array\n");
    }
}

void insertElement(struct Array* a1, int element) {
    int c;
    printf("Choose where to insert the element: \n");
    printf("1. For inserting at the start\n");
    printf("2. For inserting at the end\n");
    printf("3. For inserting in the middle\n");
    scanf("%d", &c);
    switch (c) {
        case 1: {
            if (a1->elem < a1->size) {
                for (int i = a1->elem; i > 0; i--) {
                    a1->arr[i] = a1->arr[i - 1];
                }
                a1->arr[0] = element;
                (a1->elem)++;
            } else {
                printf("Array is full, cannot insert\n");
            }
        } break;
        case 2: {
            if (a1->elem < a1->size) {
                a1->arr[a1->elem] = element;
                (a1->elem)++;
            } else {
                printf("Array is full, cannot insert\n");
            }
        } break;
        case 3: {
            int pos;
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (a1->elem < a1->size) {
                if (pos > a1->elem) {
                    pos = a1->elem;
                }
                for (int i = a1->elem; i > pos; i--) {
                    a1->arr[i] = a1->arr[i - 1];
                }
                a1->arr[pos] = element;
                (a1->elem)++;
            } else {
                printf("Array is full, cannot insert\n");
            }
        } break;
        default:
            printf("Invalid input\n");
    }
}

void modify(struct Array* a1, int rem, int add) {
    for (int i = 0; i < a1->elem; i++) {
        if (a1->arr[i] == rem) {
            a1->arr[i] = add;
        }
    }
}

void deleteElement(struct Array* a1, int pos) {
    if (pos >= 1 && pos <= a1->elem) {
        for (int i = pos - 1; i < a1->elem - 1; i++) {
            a1->arr[i] = a1->arr[i + 1];
        }
        (a1->elem)--;
    } else {
        printf("Invalid position to delete\n");
    }
}

int main() {
    int size, c;

    printf("Enter the size of array: ");
    scanf("%d", &size);
    struct Array* a1 = createArray(size);

    addElem(a1);
    display(a1);

    do{
        printf("\nChoose which operation to do: \n");
        printf("1. For traversing the elements\n");
        printf("2. For sorting the array\n");
        printf("3. For search operation\n");
        printf("4. For insertion\n");
        printf("5. For deletion\n");
        printf("6. For modification\n");
        printf("7. For display operation\n");
        printf("8. To exit\n");
        scanf("%d", &c);
        printf("\n");

        switch (c) {
            case 1: {
                traverse(a1);
            } break;
            case 2: {
                sort(a1);
                display(a1);
            } break;
            case 3: {
                int s;
                printf("Enter the element to search: ");
                scanf("%d", &s);
                search(a1, s);
            } break;
            case 4: {
                int elem;
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertElement(a1, elem);
                display(a1);
            } break;
            case 5: {
                int pos;
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteElement(a1, pos);
                display(a1);
            } break;
            case 6: {
                int rem, add;
                printf("Enter the element to remove: ");
                scanf("%d", &rem);
                printf("\nEnter the element to add: ");
                scanf("%d", &add);
                modify(a1, rem, add);
                display(a1);
            } break;
            case 7: {
                display(a1);
            } break;
            default:
            printf("Invalid choice\n");
        }
    }while(c!=8);

    free(a1->arr);
    free(a1);

    return 0;
}