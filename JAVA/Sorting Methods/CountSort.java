import java.util.Arrays;

public class CountSort {
    public static void countSort(int[] arr) {
        int n = arr.length;
        int output[] = new int[n];
        int count[] = new int[256]; // Assuming the range of input is 0 to 255

        // Initialize count array
        Arrays.fill(count, 0);

        // Store count of each character
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        // Change count[i] so that it contains actual position of this character in output[]
        for (int i = 1; i <= 255; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        // Copy the output array to arr[], so that arr[] now contains sorted characters
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 8, 3, 3, 1};
        countSort(arr);
        System.out.println("Sorted array: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
