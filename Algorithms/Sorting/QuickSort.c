#include <stdio.h>

void printArr(int *arr, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[low]; // always take first element as pivot
    int i = (low + 1); // index of smaller element
    int j = high; // index of larger element
    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;     
}

void quickSort(int arr[], int low, int high){
    int pivot_index;
    if(low < high){
        pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

int main(){
    int arr[] = {3,8,6,1,9,7,2};
    int n = 7;
    printf("Array before sorting: \n");
    printArr(arr, n);
    // Sorting the array using quick sort algorithm
    quickSort(arr, 0, n-1);
    printf("Sorting using Quick sort: \n");
    printArr(arr, n);
    return 0;
}