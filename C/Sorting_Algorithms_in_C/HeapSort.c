#include<stdio.h>

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapify(int A[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && A[left] > A[largest])
        largest = left;

    if(right < n && A[right] > A[largest])
        largest = right;

    if(largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n){
    // Build heap (rearrange array)
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(A, n, i);
    }

    // Extract elements from heap one by one
    for(int i = n - 1; i > 0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
    }
}

int main(){
    int A[] = {6,3,-2,-12,23,45,73,0,11,-986};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printarray(A, n);

    heapSort(A, n);

    printf("Sorted array: ");
    printarray(A, n);

    return 0;
}
