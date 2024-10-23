package com.omkar.LinearSearch;
//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
public class EvenDigits {
    public static void main(String[] args) {
        int[] nums = {12,345,2,6,7896, 24};
        System.out.println(findNumbers(nums));  // OP: 3

        System.out.println(digits(234567)); // OP: 6
        System.out.println(digits(-2345));
        System.out.println(digits(0));

        System.out.println(even(34)); // OP: true
    }
    static int findNumbers(int[] nums){
        int count = 0;
        for (int num: nums){
            if (even(num)){
                count++;
            }
        }
        return count;
    }

    static boolean even(int num){
        int numberOfDigits = digits(num);
        if (numberOfDigits % 2 == 0){
            return true;
        }
        return false;
    }

    static int digits(int num) {
        if (num < 0){
            num = num * -1;
        }

        if (num == 0){
            return 1;
        }
        int count = 0;
        while (num > 0) {
            count++;
            num = num / 10; // num/= 10
        }
        return count;
    }
}
