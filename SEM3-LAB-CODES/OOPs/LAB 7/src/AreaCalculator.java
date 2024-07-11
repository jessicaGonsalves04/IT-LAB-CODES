import java.util.Scanner;
public class AreaCalculator {
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
        Rectangle rectangle = new Rectangle(length, width);
        Circle circle = new Circle(radius);
        // Print the areas of the rectangle and circle.
        System.out.println("Area of rectangle: " + rectangle.calculateArea());
        System.out.println("Area of circle: " + circle.calculateArea());
    }
}
class Shapes {
    double calculateArea() {
        return 0;
    }
}
class rectangle extends Shapes {
    private double length;
    private double width;
     rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    @Override
    double calculateArea() {
        return length * width;
    }
}
class circle extends Shapes {
    private double radius;
    circle(double radius) {
        this.radius = radius;
    }
    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}