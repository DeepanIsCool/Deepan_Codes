package Day3;
/*
 * Question 2: Static Methods
Problem Statement:
Write a Java program to calculate the square of a number using a static method in a class MathUtil. The method square(int n) 
should be declared static and called from the main method without creating an instance of MathUtil.
Tasks:
Define a class MathUtil with a static method square(int n).
Call the method from the main method and display the result.
 */

public class MathUtil {
    // Static method to calculate the square of a number
    public static int square(int n) {
        return n * n;
    }

    public static void main(String[] args) {
        // Call the static method square and display the result
        int number = 5;
        int result = MathUtil.square(number);
        System.out.println("The square of " + number + " is: " + result);
    }
}
