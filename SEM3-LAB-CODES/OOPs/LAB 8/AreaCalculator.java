import java.util.Scanner;
public class AreaCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the rectangle: ");
        double l= sc.nextDouble();
        System.out.print("Enter the width of the rectangle: ");
        double w = sc.nextDouble();
        System.out.print("Enter the radius of the circle: ");
        double r = sc.nextDouble();
      
        Rectangle rad= new Rectangle(l, w);
        Circle c = new Circle(r);
       
        System.out.println("Area of rectangle: " + rad.calculateArea());
        System.out.println("Area of circle: " + c.calculateArea());
    }
}
class Shapes {
    double calculateArea() {
        return 0;
    }
}
class Rectangle extends Shapes {
     double length;
     double width;
     Rectangle(double l, double w) {
        this.length = l;
        this.width = w;
    }
    @Override
    double calculateArea() {
        return length * width;
    }
}
class Circle extends Shapes {
    private double radius;
    Circle(double r) {
        this.radius = r;
    }
    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }
}