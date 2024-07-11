import java.util.Scanner;
public class areaCalc2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Prompt the user to enter the length and width of the rectangle.
        System.out.print("Enter the length of the rectangle: ");
        double length = scanner.nextDouble();
        System.out.print("Enter the width of the rectangle: ");
        double width = scanner.nextDouble();
        // Prompt the user to enter the radius of the circle.
        System.out.print("Enter the radius of the circle: ");
        double radius = scanner.nextDouble();
        // Create instances of the Rectangle and Circle classes.
        Shapes rectangle = new Rectangle(length, width);
        Shapes circle = new Circle(radius);
        // Print the areas of the rectangle and circle.
        System.out.println("Area of rectangle: " + rectangle.calculateArea());
        System.out.println("Area of circle: " + circle.calculateArea());
    }
}
interface Shape {
    double calculateArea();
}
class Rectangle implements Shape {
    private double length;
    private double width;
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    @Override
    public double calculateArea() {
        return length * width;
    }
}
class Circle extends Shapes {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}