package Day3;
/*
 * Question 3: Calling a Method
Problem Statement:
Create a Java class Person that contains a method display() which prints the person’s name. Use another method show() 
that uses the this keyword to call display() from within the same class.
Tasks:
Define the Person class with methods display() and show().
Use this.display() inside the show() method.
Call show() from the main method to print the person’s name.
 */

public class Person2 {
    // Instance variable
    private String name;

    // Constructor to initialize the name
    public Person2(String name) {
        this.name = name;
    }

    // Method to display the person's name
    public void display() {
        System.out.println("Name: " + this.name);
    }

    // Method that uses this to call the display() method
    public void show() {
        this.display(); // Calls the display() method using this
    }

    public static void main(String[] args) {
        // Create a Person object and initialize it using the constructor
        Person2 person = new Person2("Alice");

        // Call the show() method to print the person's name
        person.show();
    }
}
