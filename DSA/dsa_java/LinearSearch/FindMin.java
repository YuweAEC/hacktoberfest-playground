package com.omkar.LinearSearch;

public class FindMin {
    public static void main(String[] args) {
        int[] arr = {11, 12, -7, 5, 14, 29, 35, 40, 45, 50};
        System.out.println(min(arr));
    }

    //assume arr.length != 0
    // return the minimum number
    static int min(int[] arr){
        int ans = arr[0];
        for (int i=0; i < arr.length; i++ ){
            if(arr[i] < ans){
                ans = arr[i];
            }
        }
        return ans;
    }
}
