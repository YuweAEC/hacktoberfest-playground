package com.omkar.LinearSearch;
//https://leetcode.com/problems/richest-customer-wealth/description/
public class MaxWealth {
    public static void main(String[] args){
        int[][] account = {
                {1,5},
                {7,3},
                {3,5}
        };
        System.out.println(maximumWealth(account));
    }
    public static int maximumWealth(int[][] accounts){
        int ans = Integer.MIN_VALUE;

        for(int person = 0; person < accounts.length; person++){
            int sum = 0;
            for (int account = 0; account < accounts[person].length; account++){
                sum += accounts[person][account];
            }
            //now we have some account
            // check with over all ans
            if(sum > ans){
                ans = sum;
            }
        }
        return ans;
    }
}
