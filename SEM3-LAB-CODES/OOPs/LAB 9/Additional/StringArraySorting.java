import java.util.Scanner;

public class StringArraySorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of strings: ");
        int n = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        String[] stringArray = new String[n];

        // Input strings from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            stringArray[i] = sc.nextLine();
        }

        // Sort the array in alphabetical order
        sortStringArray(stringArray);

        // Display the sorted array
        System.out.println("Strings in alphabetical order:");
        for (String str : stringArray) {
            System.out.println(str);
        }

        sc.close();
    }

    public static void sortStringArray(String[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = i + 1; j < array.length; j++) {
                if (array[i].compareTo(array[j]) > 0) {
                    // Swap the strings
                    String temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}
