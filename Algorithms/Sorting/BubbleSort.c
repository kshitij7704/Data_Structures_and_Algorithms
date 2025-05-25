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
    // Sorting the array using bubble sort algorithm
    printf("Sorting using Bubble sort: \n");
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArr(arr, n);
    return 0;
}