import java.util.Scanner;

public class Calculations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");
        double num1 = scanner.nextDouble();

        System.out.print("Enter second number: ");
        double num2 = scanner.nextDouble();

        double sum = num1 + num2;
        double difference = num1 > num2 ? num1 - num2 : num2 - num1;
        double product = num1 * num2;
        double quotient = num1 > num2 ? num1 / num2 : num2 / num1;
        double remainder = num1 > num2 ? num1 % num2 : num2 % num1;

        System.out.println("Sum: " + sum + "\nDifference: " + difference + "\nProduct: " + product + "\nQuotient: "
                + quotient + "\nRemainder: " + remainder);

        scanner.close();
    }
}