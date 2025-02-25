package Day3;
/*
 * Question 6: Preventing Shadowing of Class Members
Problem Statement:
Create a class Product with instance variables id and price. Use a parameterized constructor where local variables have 
the same name as instance variables. Use this to refer to the class members and assign values correctly.
Tasks:
Define the Product class with id and price as instance variables.
Use this in the constructor to avoid shadowing by local variables.
Print the values of id and price.
 */

public class Product {
    // Instance variables
    private int id;
    private double price;

    // Parameterized constructor with local variables having the same names as
    // instance variables
    public Product(int id, double price) {
        this.id = id; // 'this.id' refers to the instance variable
        this.price = price; // 'this.price' refers to the instance variable
    }

    // Method to print the values of id and price
    public void printDetails() {
        System.out.println("Product ID: " + this.id);
        System.out.println("Product Price: " + this.price);
    }

    public static void main(String[] args) {
        // Create a Product object and initialize it using the constructor
        Product product = new Product(101, 29.99);

        // Print the values of id and price
        product.printDetails();
    }
}