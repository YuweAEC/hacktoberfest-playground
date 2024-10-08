#include<stdio.h>

void mergeSort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

void mergeSort(int a[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[50];  

    // Merging the two parts into temp array `b[]`
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from the first half, if any
    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from the second half, if any
    while(j <= high){
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy the sorted elements back into original array `a[]`
    for(i = low; i <= high; i++){
        a[i] = b[i];
    }
}

int main(){
    int a[] = {8, 3, 5, 7, 2, 1, 10, 4};
    int n = sizeof(a) / sizeof(a[0]);

    // Print the original array
    printf("Original array: \n");
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    printf("\n\n");

    // Apply merge sort
    mergeSort(a, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    
    return 0;
}
