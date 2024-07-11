import java.util.Scanner;

class Input_Exception extends Exception {
    public Input_Exception(String message) {
        super(message);
    }
}

public class SumInput {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;

        while (true) {
            try {
                System.out.print("Enter a number (-1 to calculate sum): ");
                String input = sc.nextLine();
                double number = Double.parseDouble(input);

                if (number == -1) {
                    break;
                } else if (number % 1 != 0) {
                    throw new Input_Exception("Floating point numbers are not allowed.");
                } else {
                    sum += (int) number;
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a valid number.");
            } catch (Input_Exception e) {
                System.out.println(e.getMessage());
            }
        }

        System.out.println("Sum of entered numbers: " + sum);

        sc.close();
    }
}
