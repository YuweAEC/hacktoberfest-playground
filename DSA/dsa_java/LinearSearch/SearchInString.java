package com.omkar.LinearSearch;

import java.lang.reflect.Array;
import java.util.Arrays;

public class SearchInString {
    public static void main(String[] args) {
        String name = "Omkar";
        char target = 'r';
        System.out.println(search(name, target));  // OP: true  --> search function
        System.out.println(Arrays.toString(name.toCharArray()));   // OP: [O, m, k, a, r] --> search2 function
    }
    static boolean search(String str, char target){
        if(str.length() == 0){
            return false;
        }
        for(int i=0; i < str.length(); i++){
            if(target == str.charAt(i)){
                return true;
            }
        }
        return false;
    }

    // using the for each loop
    static boolean search2(String str, char target){
        if(str.length() == 0){
            return false;
        }
        for(char ch : str.toCharArray()){
            if(ch == target){
                return true;
            }
        }
        return false;
    }

}

