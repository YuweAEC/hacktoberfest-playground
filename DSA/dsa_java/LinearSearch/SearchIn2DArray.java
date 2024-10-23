package com.omkar.LinearSearch;

import java.util.Arrays;

public class SearchIn2DArray {
    public static void main(String[] args) {
        int[][] arr = {
                {23, 24, 45},
                {78, 56, 89, 6},
                {12, 53, 29, 85, 81},
                {22, 11}
        };
        int target=  81; // OP: [2, 4] --> In 2nd row & In 4th col the 81.
        int[] ans= search(arr, target);   // format of return value {row, col}
        System.out.println(Arrays.toString(ans));
    }
    static int[] search(int[][] arr, int target){
        for(int row=0; row < arr.length; row++){
            for(int col=0; col < arr[row].length; col++){
                if(arr[row][col] == target){
                    return new int[]{row, col};
                }
            }
        }
        return new int[]{1, -1};
    }
}
