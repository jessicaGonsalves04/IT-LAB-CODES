import java.util.Scanner;

class Student {
    private int regNumber;
    private String firstName;
    private String lastName;
    private String degree;

    public Student(int regNumber, String firstName, String lastName, String degree) {
        this.regNumber = regNumber;
        this.firstName = firstName;
        this.lastName = lastName;
        this.degree = degree;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    @Override
    public String toString() {
        return "Registration Number: " + regNumber +
                "\nFirst Name: " + firstName +
                "\nLast Name: " + lastName +
                "\nDegree: " + degree;
    }
}

public class StudentSearch {
    public static void main(String[] args) {
        Student[] students = new Student[10];

        students[0] = new Student(1, "John", "Doe", "Computer Science");
        students[1] = new Student(2, "Alice", "Smith", "Mathematics");
        students[2] = new Student(3, "Bob", "Johnson", "Physics");
        students[3] = new Student(4, "Eve", "Wilson", "Chemistry");
        students[4] = new Student(5, "Charlie", "Brown", "Biology");
        students[5] = new Student(6, "Grace", "Davis", "Engineering");
        students[6] = new Student(7, "Frank", "Miller", "Economics");
        students[7] = new Student(8, "Olivia", "Moore", "History");
        students[8] = new Student(9, "Daniel", "Thomas", "Psychology");
        students[9] = new Student(10, "Sophia", "Anderson", "English");

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the First Name or Last Name of the student to search: ");
        String searchName = sc.nextLine();

        boolean found = false;

        for (Student student : students) {
            if (student.getFirstName().equalsIgnoreCase(searchName) || student.getLastName().equalsIgnoreCase(searchName)) {
                System.out.println("Student found:");
                System.out.println(student);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student not found.");
        }

        sc.close();
    }
}
