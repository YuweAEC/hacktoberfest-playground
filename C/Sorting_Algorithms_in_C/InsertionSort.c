#include<stdio.h>

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = A[i];
        j = i - 1;

        while(j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

int main(){
    int A[] = {9,-3,53,23,55,123,-98,24};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printarray(A, n);

    insertionSort(A, n);

    printf("Sorted array: ");
    printarray(A, n);

    return 0;
}
