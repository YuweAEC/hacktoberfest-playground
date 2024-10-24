// Remove all characters except the numeric characters from an alphanumeric string.

// Example 1:

// Input: S = "AA1d23cBB4"
// Output: 1234
// Explanation: Remove all characters
// other than numbers


import java.util.*;

public class Solution1 {
    public static void main(String[] args) {
        String S = "AA1d23cBB4";
        String str = ""; 
        for (int i = 0; i < S.length(); i++) {
            if (Character.isDigit(S.charAt(i))) {
                str += S.charAt(i);
            }
        }
        System.out.println(str);
    };
    
    
}







