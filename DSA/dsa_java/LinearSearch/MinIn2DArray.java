package com.omkar.LinearSearch;

import java.util.Arrays;

public class MinIn2DArray {
    public static void main(String[] args) {
        int[][] arr = {
                {23, 24, 45},
                {78, 56, 99, 6},
                {12, 53, 29, 85, 81},
                {22, 11}
        };
        System.out.println(min(arr));
    }
    static int min(int[][] arr){
        int min = Integer.MAX_VALUE;
        for(int row = 0; row < arr.length; row++){
            for (int col = 0; col < arr[row].length; col++){
                if (arr[row][col] < min){
                    min = arr[row][col];
                }
            }
        }
        return min;
    }
}
