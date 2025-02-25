package Day3;
/*
 * Question 9:
 * Write a Java program that demonstrates method overriding using a class `Animal` and
a subclass `Dog`.
- The `Animal` class should have a method `sound()` that prints &quot;Animal makes a
sound&quot;.
- The `Dog` class should override the `sound()` method to print &quot;Dog barks&quot;.
Create objects of both classes and call the `sound()` method to demonstrate method
overriding.
 */

class Animal {
    // Method to print the sound of an animal
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    // Overriding the sound method to print the sound of a dog
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an object of the Animal class and call the sound method
        Animal animal = new Animal();
        animal.sound(); // Output: Animal makes a sound

        // Create an object of the Dog class and call the sound method
        Dog dog = new Dog();
        dog.sound(); // Output: Dog barks
    }
}