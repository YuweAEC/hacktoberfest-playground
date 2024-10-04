#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    struct Bucket {
        int count;
        float* values;
    };

    struct Bucket* buckets = malloc(n * sizeof(struct Bucket));

    for (int i = 0; i < n; i++) {
        buckets[i].count = 0;
        buckets[i].values = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count - 1; j++) {
            for (int k = 0; k < buckets[i].count - j - 1; k++) {
                if (buckets[i].values[k] > buckets[i].values[k + 1]) {
                    float temp = buckets[i].values[k];
                    buckets[i].values[k] = buckets[i].values[k + 1];
                    buckets[i].values[k + 1] = temp;
                }
            }
        }
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++)
            arr[idx++] = buckets[i].values[j];
    }

    for (int i = 0; i < n; i++)
        free(buckets[i].values);

    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    return 0;
}
