import java.util.Scanner;

public class PhoneNumberExtractor {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a phone number in the format (555) 555-5555: ");
        String phoneNumber = sc.nextLine();

        String areaCode = extractAreaCode(phoneNumber);
        String firstThreeDigits = extractFirstThreeDigits(phoneNumber);
        String lastFourDigits = extractLastFourDigits(phoneNumber);

        System.out.println("Area Code: " + areaCode);
        System.out.println("Seven-Digit Phone Number: " + firstThreeDigits + lastFourDigits);

        sc.close();
    }

    public static String extractAreaCode(String phoneNumber) {
        int startIndex = phoneNumber.indexOf("(");
        int endIndex = phoneNumber.indexOf(")");
        return phoneNumber.substring(startIndex + 1, endIndex);
    }

    public static String extractFirstThreeDigits(String phoneNumber) {
        int startIndex = phoneNumber.indexOf(") ") + 1;
        int endIndex = phoneNumber.indexOf("-");
        return phoneNumber.substring(startIndex, endIndex);
    }

    public static String extractLastFourDigits(String phoneNumber) {
        int startIndex = phoneNumber.indexOf("-") + 1;
        return phoneNumber.substring(startIndex);
    }
}
