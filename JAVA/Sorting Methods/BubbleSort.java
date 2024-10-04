import java.util.Scanner;

	public class BubbleSort {

	    // Method to perform Bubble Sort
	    public static void bubbleSort(int[] arr) {
	        int n = arr.length;
	        boolean swapped;

	        // Outer loop for each pass
	        for (int i = 0; i < n - 1; i++) {
	            swapped = false;

	            // Inner loop for comparison in each pass
	            for (int j = 0; j < n - i - 1; j++) {
	                if (arr[j] > arr[j + 1]) {
	                    // Swap arr[j] and arr[j + 1]
	                    int temp = arr[j];
	                    arr[j] = arr[j + 1];
	                    arr[j + 1] = temp;
	                    swapped = true;
	                }
	            }

	            // If no two elements were swapped in the inner loop, array is sorted
	            if (!swapped) break;
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

	            // Perform bubble sort
	            bubbleSort(array);

	            // Display sorted array
	            System.out.println("Sorted array:");
	            printArray(array);
	        }

	        scanner.close(); // Close the scanner to avoid resource leakage
	    }
	}

