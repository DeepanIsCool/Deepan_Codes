package Day3;
/*
 * Question 2: Calling Another Constructor
Problem Statement:
Write a Java program to demonstrate how to use this to call another constructor in the same class. Create a class Rectangle with two constructors:
One constructor with no parameters that calls the parameterized constructor with default values.
One parameterized constructor that initializes length and width.
Tasks:
Define the class Rectangle with two constructors.
Use this() in the no-argument constructor to call the parameterized constructor.
Display the values of length and width.
 */

public class Rectangle {
    // Instance variables
    private double length;
    private double width;

    // No-argument constructor that calls the parameterized constructor with default
    // values
    public Rectangle() {
        this(1.0, 1.0); // Calls the parameterized constructor with default values
    }

    // Parameterized constructor to initialize length and width
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Method to display the values of length and width
    public void display() {
        System.out.println("Length: " + this.length);
        System.out.println("Width: " + this.width);
    }

    public static void main(String[] args) {
        // Create a Rectangle object using the no-argument constructor
        Rectangle defaultRectangle = new Rectangle();
        System.out.println("Default Rectangle:");
        defaultRectangle.display();

        // Create a Rectangle object using the parameterized constructor
        Rectangle customRectangle = new Rectangle(5.0, 3.0);
        System.out.println("Custom Rectangle:");
        customRectangle.display();
    }
}
