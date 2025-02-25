package Day3;
/*
 * Question 3: Static Block
Problem Statement:
Create a Java program to demonstrate the use of a static block. In a class Configuration, use a static
block to initialize a static variable appVersion. Print the value of appVersion from the main method.
Tasks:
Define a class Configuration with a static variable appVersion.
Use a static block to initialize appVersion with a default value.
Display appVersion from the main method.
 */

public class Configuration {
    // Static variable to hold the application version
    static String appVersion;

    // Static block to initialize the static variable
    static {
        appVersion = "1.0.0";
    }

    public static void main(String[] args) {
        // Display the value of appVersion
        System.out.println("Application Version: " + Configuration.appVersion);
    }
}
