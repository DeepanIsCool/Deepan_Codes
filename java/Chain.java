/*
 * Question 5: Returning the Current Object
Problem Statement:
Create a class Chain with a method setValue(int value) that returns the current object using this. 
Use a chain of method calls in the main method to set a value and print it.
Tasks:
Define the Chain class with an instance variable value.
Use this to return the current object in setValue(int value).
Call setValue() using method chaining.
 */

public class Chain {
    // Instance variable to hold the value
    private int value;

    // Method to set the value and return the current object
    public Chain setValue(int value) {
        this.value = value;
        return this; // Return the current object
    }

    // Method to print the value
    public void printValue() {
        System.out.println("Value: " + this.value);
    }

    public static void main(String[] args) {
        // Create a Chain object and use method chaining to set a value and print it
        Chain chain = new Chain();
        chain.setValue(10).printValue(); // Method chaining
    }
}