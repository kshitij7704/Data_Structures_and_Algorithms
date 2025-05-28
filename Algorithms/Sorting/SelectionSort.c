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
    // Sorting the array using selection sort algorithm
    printf("Sorting using Selection sort: \n");
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    printArr(arr, n);
    return 0;
}