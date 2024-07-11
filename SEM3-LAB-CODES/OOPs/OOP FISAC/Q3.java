import java.util.Scanner;

class NegativeMarkException extends Exception {
    public NegativeMarkException(String message) {
        super(message);
    }
}

class OutOfRangeException extends Exception {
    public OutOfRangeException(String message) {
        super(message);
    }
}

class Student {
    String studentName;
    String regNo;
    String category;
    int[] marks = new int[3];
    char grade;

    public Student(String studentName, String regNo, String category) {
        this.studentName = studentName;
        this.regNo = regNo;
        this.category = category;
    }

    public void input() throws NegativeMarkException, OutOfRangeException {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            System.out.print("Enter mark for Subject " + (i + 1) + ": ");
            int mark = scanner.nextInt();
            if (mark < 0) {
                throw new NegativeMarkException("Negative marks are not allowed.");
            } else if (mark < 0 || mark > 100) {
                throw new OutOfRangeException("Marks should be between 0 and 100.");
            }
            marks[i] = mark;
        }
        calculateGrade();
    }

    private void calculateGrade() {
        int total = marks[0] + marks[1] + marks[2];
        int average = total / 3;
        if (average >= 90) {
            grade = 'A';
        } else if (average >= 80) {
            grade = 'B';
        } else if (average >= 70) {
            grade = 'C';
        } else {
            grade = 'F';
        }
    }

    public String getRegNo() {
        return regNo;
    }

    public char getGrade() {
        return grade;
    }
}

 class Q3 {
    public static void main(String[] args) {
        Student[] students = new Student[3];

        try {
            Scanner scanner = new Scanner(System.in);
            String[][] studentDetails = new String[3][2]; // 2D matrix to store RegNo and grade

            for (int i = 0; i < students.length; i++) {
                System.out.println("Enter details for Student " + (i + 1) + ":");
                System.out.print("Student Name: ");
                String studentName = scanner.next();
                System.out.print("Reg No: ");
                String regNo = scanner.next();
                System.out.print("Category (UG/PG): ");
                String category = scanner.next();
                students[i] = new Student(studentName, regNo, category);
                students[i].input();

                // Store RegNo and grade in the 2D matrix
                studentDetails[i][0] = students[i].getRegNo();
                studentDetails[i][1] = String.valueOf(students[i].getGrade());
            }

            // Sort students based on average marks
            for (int i = 0; i < students.length; i++) {
                for (int j = i + 1; j < students.length; j++) {
                    if (students[i].getGrade() > students[j].getGrade()) {
                        Student temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }

            System.out.println("Top 3 Students with Highest Grades:");
            for (int i = 0; i < Math.min(3, students.length); i++) {
                System.out.println("Student Name: " + students[i].studentName);
                System.out.println("Reg No: " + students[i].getRegNo());
                System.out.println("Category: " + students[i].category);
                System.out.println("Grade: " + students[i].getGrade());
                System.out.println();
            }

            // Display the 2D matrix with RegNo and grade
            System.out.println("2D Matrix of RegNo and Grade:");
            for (int i = 0; i < students.length; i++) {
                System.out.println("Reg No: " + studentDetails[i][0]);
                System.out.println("Grade: " + studentDetails[i][1]);
                System.out.println();
            }
        } catch (NegativeMarkException | OutOfRangeException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
