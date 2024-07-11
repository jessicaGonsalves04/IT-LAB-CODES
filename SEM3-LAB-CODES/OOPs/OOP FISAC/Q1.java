import java.util.Arrays;

class Employee implements Comparable<Employee> {
    private String name;
    private int yoE;

    public Employee(String name, int yoE) {
        this.name = name;
        this.yoE = yoE;
    }

    @Override
    public String toString() {
        return "Employee[" +
                "name='" + name + '\'' +
                ", YoE=" + yoE +
                ']';
    }

    @Override
    public int compareTo(Employee other) {
        return Integer.compare(this.yoE, other.yoE);
    }
}

class Student implements Comparable<Student> {
    private String name;
    private String grade;

    public Student(String name, String grade) {
        this.name = name;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "Student[" +
                "name='" + name + '\'' +
                ", grade='" + grade + '\'' +
                ']';
    }

    @Override
    public int compareTo(Student other) {
        return this.grade.compareTo(other.grade);
    }
}

class SortUtility<T extends Comparable<T>> {
    private T[] data;

    public SortUtility(T[] data) {
        this.data = data;
    }

    public void sort() {
        Arrays.sort(data);
    }

    public void display() {
        for (T item : data) {
            System.out.println(item.toString());
        }
    }
}

public class Q1 {
    public static void main(String[] args) {
        Employee[] employees = {
                new Employee("John", 5),
                new Employee("Alice", 3),
                new Employee("Bob", 7)
        };

        Student[] students = {
                new Student("Tom", "A"),
                new Student("Mary", "B"),
                new Student("Jerry", "A+")
        };

        SortUtility<Employee> employeeSortUtility = new SortUtility<>(employees);
        SortUtility<Student> studentSortUtility = new SortUtility<>(students);

        System.out.println("Before sorting:");
        employeeSortUtility.display();
        studentSortUtility.display();

        employeeSortUtility.sort();
        studentSortUtility.sort();

        System.out.println("\nAfter sorting:");
        employeeSortUtility.display();
        studentSortUtility.display();
    }
}
