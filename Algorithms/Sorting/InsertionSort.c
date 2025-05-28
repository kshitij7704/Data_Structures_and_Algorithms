#include<stdio.h>

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {3,8,6,1,9,7,2};
    int n = 7;
    printf("Array before sorting: \n");
    printArr(arr, n);
    // Sorting the array using insertion sort algorithm
    printf("Sorting using Insertion sort: \n");
    // Loop for passes
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        // Loop for each passes
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printArr(arr, n);
    return 0;
}