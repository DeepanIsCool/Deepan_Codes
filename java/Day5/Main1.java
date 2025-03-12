/*
 * 1.Write a Java program to create an interface Shape with the getArea() method. Create three classes Rectangle, Circle, and Triangle 
 * that implement the Shape interface. Implement the getArea() method for each of the three classes.
 */

package Day5;

// Define the Shape interface with the getArea() method
interface Shape {
    double getArea();
}

// Implement the Rectangle class that implements the Shape interface
class Rectangle implements Shape {
    private double length;
    private double width;

    // Constructor to initialize length and width
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Implement the getArea() method for Rectangle
    @Override
    public double getArea() {
        return length * width;
    }
}

// Implement the Circle class that implements the Shape interface
class Circle implements Shape {
    private double radius;

    // Constructor to initialize radius
    public Circle(double radius) {
        this.radius = radius;
    }

    // Implement the getArea() method for Circle
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

// Implement the Triangle class that implements the Shape interface
class Triangle implements Shape {
    private double base;
    private double height;

    // Constructor to initialize base and height
    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    // Implement the getArea() method for Triangle
    @Override
    public double getArea() {
        return 0.5 * base * height;
    }
}

public class Main1 {
    public static void main(String[] args) {
        // Create objects of Rectangle, Circle, and Triangle
        Shape rectangle = new Rectangle(5, 3);
        Shape circle = new Circle(4);
        Shape triangle = new Triangle(6, 4);

        // Print the area of each shape
        System.out.println("Rectangle Area: " + rectangle.getArea());
        System.out.println("Circle Area: " + circle.getArea());
        System.out.println("Triangle Area: " + triangle.getArea());
    }
}