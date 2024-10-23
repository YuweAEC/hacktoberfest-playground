package com.omkar.LinearSearch;

public class Main {
    public static void main(String[] args) {
        int[] nums = {23, 45, 66, 52, 3, 10, 6, 8, 9};
//        int[] nums = {};
        int target = 10;
        int ans = linearSearch(nums, target);
        System.out.println(ans);
    }


    //Search in the array: return the index if item found otherwise if item not found return -1
    static int linearSearch(int[] arr, int target){
        if(arr.length == 0){
            return -2;
        }

        //run a for loop
        for(int index=0; index<arr.length; index++){
            //check for element at every index if it is = target
            int element = arr[index];
            if(element == target){
                return index;
            }
        }
        // this line will execute if none of the return statements above have executed
        // hence the target not found
        return -1;
    }

    // search the target and return the element
    static int linearSearch2(int[] arr, int target){
        if(arr.length == 0){
            return -2;
        }

        //run a enhance for loop
        for (int element : arr) {
            //check for element at every index if it is = target
            if (element == target) {
                return element;
            }
        }
        // this line will execute if none of the return statements above have executed
        // hence the target not found
        return -1;
    }
}
