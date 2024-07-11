import java.util.Scanner;

interface Shape {
    double getArea();
}

class Square implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}

class Triangle implements Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double getArea() {
        return 0.5 * base * height;
    }
}

public class AreaCalculator2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Select a shape:");
        System.out.println("1. Square");
        System.out.println("2. Triangle");
        int choice = scanner.nextInt();

        Shape shape = null;
        double area = 0.0;

        if (choice == 1) {
            System.out.print("Enter the side length of the square: ");
            double side = scanner.nextDouble();
            shape = new Square(side);
        } else if (choice == 2) {
            System.out.print("Enter the base length of the triangle: ");
            double base = scanner.nextDouble();
            System.out.print("Enter the height of the triangle: ");
            double height = scanner.nextDouble();
            shape = new Triangle(base, height);
        } else {
            System.out.println("Invalid choice.");
            scanner.close();
            return;
        }

        area = shape.getArea();
        System.out.println("Area: " + area);

        scanner.close();
    }
}
