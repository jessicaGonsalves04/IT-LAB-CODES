import java.util.Scanner;

public class negativeRoot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        double number = sc.nextDouble();

        try {
            if (number < 0) {
                throw new IllegalArgumentException("Negative number, cannot calculate square root.");
            }
            double result = Math.sqrt(number);
            System.out.println("Square root of " + number + " is: " + result);
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid input: " + e);
        }
    }
}
