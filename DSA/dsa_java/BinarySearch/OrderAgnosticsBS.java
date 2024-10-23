package com.omkar.BinarySearch;

public class OrderAgnosticsBS {
    public static void main(String[] args) {
//        int[] arr = {-18, -12, -4, 0, 2, 3, 4, 15, 16, 18, 22, 45, 89}; // ascending order array
        int[] arr = {99, 80, 75, 22, 11, 10, 5, 2, -3}; // descending order
        // note: time complexity is same either ascending or descending order.
        int target = 22;
        int ans = orderAgnosticBS(arr,target);
        System.out.println(ans);
    }

    static int orderAgnosticBS(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;


        // find whether the array is sorted in ascending or descending
        boolean isAsc;
        if (arr[start] < arr[end]){
            isAsc = true;
        } else{
            isAsc = false;
        }



        while (start <= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] == target){
                return mid;
            }


            if(isAsc){
                if (target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else{
                if (target > arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}
