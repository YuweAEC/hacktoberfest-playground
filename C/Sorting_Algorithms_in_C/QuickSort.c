#include<stdio.h>

void printarray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int temp;
    int i = low + 1;
    int j = high;

    do {
        // Move 'i' to the right until we find an element larger than the pivot
        while(i <= high && A[i] < pivot) {
            i++;
        }
        // Move 'j' to the left until we find an element smaller than the pivot
        while(j >= low && A[j] > pivot) {
            j--;
        }
        // Swap A[i] and A[j] if 'i' is less than 'j'
        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while(i < j);

    // Swap pivot element with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // Return pivot index
}

void quicksort(int A[], int low, int high){
    if(low < high){
        int partitionIndex = partition(A, low, high);
        // Recursively sort elements before and after partition
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
    }
}

int main(){
    int A[] = {3, 6, 44, 67, 23};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printarray(A, n);

    quicksort(A, 0, n - 1);

    printf("Sorted array: ");
    printarray(A, n);

    return 0;
}
