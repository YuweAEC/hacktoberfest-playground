//  Given two positive integers a and b, find GCD of a and b.

import java.util.Scanner;
import java.math.*;

public class Solution1 {
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       System.out.println("enter num1");
       int num1=sc.nextInt();
       System.out.println("enter num2");
       int num2=sc.nextInt();

       int max = Math.max(num1, num2);
       int min = Math.min(num1, num2);
        int rem;
        while (max%min!=0) {
            rem = max%min;
            max = min;
            min = rem;
        }
       System.out.println(min);
    };

}
