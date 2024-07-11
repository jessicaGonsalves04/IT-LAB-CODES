import java.util.Scanner;

public class student {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name;
        int roll, m1, m2, m3;
        
        System.out.println("Enter name:");
        name = sc.nextLine();
        System.out.println("Roll No:");
        roll = Integer.parseInt(sc.nextLine());

        try {
            System.out.println("Marks 1:");
            m1 = Integer.parseInt(sc.nextLine());
            System.out.println("Marks 2:");
            m2 = Integer.parseInt(sc.nextLine());
            System.out.println("Marks 3:");
            m3 = Integer.parseInt(sc.nextLine());

            double percentage = (m1 + m2 + m3) / 3.0;
            char grade = (percentage > 80) ? 'A' : (percentage > 60) ? 'B' : 'C';

            System.out.println("Percentage is: " + percentage + "%");
            System.out.println("Grade: " + grade);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter valid marks.");
            System.out.println("Exception: " + e);
        }
    }
}
