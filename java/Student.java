/*
 * Question 1: Accessing Instance Variables
Problem Statement:
Write a Java program that demonstrates how to use the this keyword to differentiate between instance variables and local variables. Create a class Student with 
instance variables name and age. Use a constructor to initialize these variables with local parameters having the same names as the instance variables.
Tasks:
Define the Student class with name and age as instance variables.
Use the this keyword inside the constructor to assign values to the instance variables.
Display the values of name and age.
 */

public class Student {
    // Instance variables
    private String name;
    private int age;

    // Constructor to initialize instance variables with local parameters
    public Student(String name, int age) {
        this.name = name; // 'this.name' refers to the instance variable
        this.age = age; // 'this.age' refers to the instance variable
    }

    // Method to display the values of name and age
    public void display() {
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
    }

    public static void main(String[] args) {
        // Create a Student object and initialize it using the constructor
        Student student = new Student("John Doe", 20);

        // Display the values of name and age
        student.display();
    }
}
