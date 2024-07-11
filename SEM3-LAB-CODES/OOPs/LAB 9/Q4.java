/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class Q4 {
    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Compare two Strings");
            System.out.println("2. Convert uppercase to lowercase and vice-versa");
            System.out.println("3. Check if one string is a substring of the other");
            System.out.println("4. Replace substring with 'Hello'");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.println("Enter String 1:");
                    String str1 = sc.nextLine();
                    System.out.println("Enter String 2:");
                    String str2 = sc.nextLine();
                    System.out.println("Comparison Result: " + str1.compareTo(str2));
                    break;

                case 2:
                    System.out.println("Enter a String:");
                    String str3 = sc.nextLine();
                    System.out.println("Converted String: " + convertCase(str3));
                    break;

                case 3:
                    System.out.println("Enter the Main String:");
                    String mainStr = sc.nextLine();
                    System.out.println("Enter the Substring:");
                    String subStr = sc.nextLine();
                    System.out.println("Is Substring: " + mainStr.contains(subStr));
                    break;

                case 4:
                    System.out.println("Enter the Main String:");
                    String mainString = sc.nextLine();
                    System.out.println("Enter the Substring:");
                    String substring = sc.nextLine();
                    System.out.println("Replaced String: " + mainString.replace(substring, "Hello"));
                    break;

                case 5:
                    sc.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }

    public static String convertCase(String str) {
        StringBuilder result = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (Character.isUpperCase(c)) {
                result.append(Character.toLowerCase(c));
            } else if (Character.isLowerCase(c)) {
                result.append(Character.toUpperCase(c));
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }
}
