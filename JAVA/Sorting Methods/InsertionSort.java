package ASSIGNMENTS;

import java.util.Scanner;

public class InsertionSort {

    // Method to perform Insertion Sort
    public static void insertionSort(int[] arr) {
        int n = arr.length;

        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            // Move elements of arr[0..i-1], that are greater than key, to one position ahead
            // of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    // Method to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nEnter the number of elements in the array (or enter 0 to exit): ");
            int n = scanner.nextInt();

            // Exit condition
            if (n == 0) {
                System.out.println("Exiting the program.");
                break;
            }

            // Input array from user
            int[] array = new int[n];
            System.out.println("Enter the elements of the array:");
            for (int i = 0; i < n; i++) {
                array[i] = scanner.nextInt();
            }

            // Display unsorted array
            System.out.println("Unsorted array:");
            printArray(array);

            // Perform insertion sort
            insertionSort(array);

            // Display sorted array
            System.out.println("Sorted array:");
            printArray(array);
        }

        scanner.close(); // Close the scanner to avoid resource leakage
    }
}

