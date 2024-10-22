package com.omkar.LinearSearch;

public class MaxIn2DArray {
    public static void main(String[] args) {
        int[][] arr = {
                {23, 24, 45},
                {78, 56, 99, 6},
                {12, 53, 29, 85, 81},
                {22, 11}
        };
        System.out.println(max(arr));
    }

    static int max(int[][] arr){
        int max = Integer.MIN_VALUE;
        for (int row = 0; row < arr.length; row++){
            for (int col = 0; col < arr[row].length; col++){
                if (arr[row][col] > max) {
                    max = arr[row][col];
                }
            }
        }
        return max;
    }
}
