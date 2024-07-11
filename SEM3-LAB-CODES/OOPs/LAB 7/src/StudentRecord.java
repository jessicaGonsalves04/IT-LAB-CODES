
import java.util.Scanner;
class Student_Detail {
    private String name;
    private int id;
    private static String college_name = "MIT";
     Student_Detail(String name, int id) {
        this.name = name;
        this.id = id;
    }
    public void display_details() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("College Name: " + college_name);
    }
}
public class StudentRecord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student_Detail[] students = new Student_Detail[100];
        System.out.println("Enter the number of students: ");
        int numStudents = sc.nextInt();
        for (int i = 0; i < numStudents; i++) {
            System.out.println("Enter the name of student " + (i + 1) + ": ");
            String name = sc.next();
            System.out.println("Enter the ID of student " + (i + 1) + ": ");
            int id = sc.nextInt();
            students[i] = new Student_Detail(name, id);
        }
       System.out.println("The details of all students are: ");
        for (int i = 0; i < numStudents; i++) {
            students[i].display_details();
        }
    }
}