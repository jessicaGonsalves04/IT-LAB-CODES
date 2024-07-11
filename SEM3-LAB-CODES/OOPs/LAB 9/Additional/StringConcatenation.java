import java.util.Scanner;

public class StringConcatenation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter five strings:");

        String[] strings = new String[5];

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            strings[i] = sc.nextLine();
        }

        String concatenatedString = concatenateStrings(strings);

        System.out.println("Concatenated string: " + concatenatedString);

        sc.close();
    }

    public static String concatenateStrings(String[] strings) {
        StringBuilder result = new StringBuilder();

        for (String str : strings) {
            result.append(str);
        }

        return result.toString();
    }
}
