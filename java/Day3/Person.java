package Day3;
/*
 * Question 1: Static Variables
Problem Statement:
Create a Java program that keeps track of the number of objects created from a class Person. The class should contain a static variable count that 
is incremented every time a new Person object is created. Demonstrate how the static variable retains its value across different objects.
Tasks:
Define a class Person with a static variable count.
Increment the count variable in the constructor.
Create a main method to create multiple objects of Person and print the value of count.
 */

public class Person {
    // Static variable to keep track of the number of Person objects created
    private static int count = 0;

    // Constructor that increments the count variable
    public Person() {
        count++;
    }

    // Static method to get the current count value
    public static int getCount() {
        return count;
    }

    public static void main(String[] args) {
        // Creating multiple Person objects
        Person person1 = new Person();
        Person person2 = new Person();
        Person person3 = new Person();

        // Printing the value of count
        System.out.println("Number of Person objects created: " + Person.getCount());
    }
}
