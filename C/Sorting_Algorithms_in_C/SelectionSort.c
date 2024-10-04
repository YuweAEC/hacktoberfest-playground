#include<stdio.h>

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n){
    int minIndex, temp;

    // Traverse through the array
    for(int i = 0; i < n - 1; i++){
        // Assume the current element is the minimum
        minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[minIndex]){
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if(minIndex != i){
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}

int main(){
    int A[] = {3, -2,189, 67, 23};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printarray(A, n);

    selectionSort(A, n);

    printf("Sorted array: ");
    printarray(A, n);

    return 0;
}
