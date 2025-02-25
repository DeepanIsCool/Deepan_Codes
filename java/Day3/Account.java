package Day3;
/*
 * Question 4: Passing the Current Object as an Argument
Problem Statement:
Write a program to demonstrate passing the current object using this. Create a class Account with a method printBalance(). 
Create another method displayAccount(Account obj) that takes an Account object as a parameter. Use this to pass the current object to displayAccount() from printBalance().
Tasks:
Define the Account class with methods printBalance() and displayAccount(Account obj).
Use this to pass the current object.
Call printBalance() from the main method to demonstrate this feature.
 */

public class Account {
    // Instance variable to hold the account balance
    private double balance;

    // Constructor to initialize the account balance
    public Account(double balance) {
        this.balance = balance;
    }

    // Method to print the account balance
    public void printBalance() {
        // Pass the current object to the displayAccount method
        this.displayAccount(this);
    }

    // Method that takes an Account object as a parameter and displays its balance
    public void displayAccount(Account obj) {
        System.out.println("Account Balance: " + obj.balance);
    }

    public static void main(String[] args) {
        // Create an Account object and initialize it using the constructor
        Account account = new Account(1000.0);

        // Call the printBalance method to demonstrate passing the current object
        account.printBalance();
    }
}
