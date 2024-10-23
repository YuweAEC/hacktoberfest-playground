package com.omkar.LinearSearch;

public class SearchInRange {
    public static void main(String[] args) {
        int[] arr = {18, 12, -7, 5, 14, 28, 35, 40, 45, 50};
        int target = 12;
        System.out.println(search(arr, target, 2, 6));
        //if check the target out of range, it will give the -1.

    }
    static int search(int[] arr, int target, int start, int end){
        if(arr.length == 0){
            return -1;
        }
        //run the for loop
        for(int index = start; index <= end; index++){
            // check for element at every index if it is = target
            int element =arr[index];
            if(element == target){
                return index;
            }
        }
        return -1;
    }
}
