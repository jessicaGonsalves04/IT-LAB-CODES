import java.util.ArrayList;
import java.util.EmptyStackException;

class StudentEmploye<T> 
{
    private ArrayList<T> stack;

    public StudentEmploye() 
    {
        stack = new ArrayList<>();
    }

    public void push(T item) 
    {
        stack.add(item);
    }

    public T pop() 
    {
        if (isEmpty()) 
        {
            throw new EmptyStackException();
        }
        return stack.remove(stack.size() - 1);
    }

    public boolean isEmpty() 
    {
        return stack.isEmpty();
    }
}
class Student 
{
    private String name;

    public Student(String name) 
    {
        this.name = name;
    }

    @Override
    public String toString() 
    {
        return "Student: " + name;
    }
}

class Employee 
{
    private String empID;

    public Employee(String empID) 
    {
        this.empID = empID;
    }

    @Override
    public String toString() 
    {
        return "Employee ID: " + empID;
    }
}

public class StudentEmployee {
    public static void main(String[] args) 
    {
        StudentEmploye<Student> studentStack = new StudentEmploye<>();
        studentStack.push(new Student("Hello"));
        studentStack.push(new Student("World"));

        System.out.println("Students in the stack:");
        while (!studentStack.isEmpty()) 
        {
            System.out.println(studentStack.pop());
        }

        StudentEmploye<Employee> employeeStack = new StudentEmploye<>();
        employeeStack.push(new Employee("EMP001"));
        employeeStack.push(new Employee("EMP002"));

        System.out.println("\nEmployees in the stack:");
        while (!employeeStack.isEmpty()) 
        {
            System.out.println(employeeStack.pop());
        }
    }
}