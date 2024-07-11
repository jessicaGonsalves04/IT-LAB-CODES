import java.util.Scanner;
public class areaCalc2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       System.out.print("Enter the length of the rectangle: ");
        double l= sc.nextDouble();
        System.out.print("Enter the width of the rectangle: ");
        double w = sc.nextDouble();
       System.out.print("Enter the radius of the circle: ");
        double r = sc.nextDouble();

        Rectangle rect = new Rectangle(l, w);
       Circle c = new Circle(r);
       
        System.out.println("Area of rectangle: " + rect.calculateArea());
        System.out.println("Area of circle: " + c.calculateArea());
    }
}
interface Shape {
    double calculateArea();
}
class Rectangle implements Shape {
   double length;
     double width;
    public Rectangle(double l, double w) {
       length = l;
        width = w;
    }
    @Override
    public double calculateArea() {
        return length * width;
    }
}
class Circle extends Shapes {
    double radius;
    public Circle(double r) {
     radius = r;
    }
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}