package com.omkar.BinarySearch;

public class BinarySearchAnuj {
    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 5, 12, 45, 77, 85, 87, 88, 95, 99};
        int key = 77;
        int ans = binarySearch(arr, key);
        System.out.println(ans);
        
    }
    static int binarySearch(int[] arr, int key){
        int start = 0;
        int end = arr.length-1;
        
        while (start <= end){
            int mid = (start + end) /2;

            if(arr[mid] == key) {
                return mid;
            } else if (key > arr[mid]) {
                start = mid +1;
            }
            else {
                end = mid -1;
            }
        }
        return -1;
    }
}
