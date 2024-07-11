import java.util.Scanner;

interface Item {
    double calculateSales();
}

class Hardware implements Item {
    private String category;
    private String manufacturer;
    private double sales;
    private static double totalHardwareSales = 0;

    public Hardware(String category, String manu, double sales) {
        this.category = category;
        this.manufacturer = manu;
        this.sales = sales;
        totalHardwareSales += this.sales;
    }

    @Override
    public double calculateSales() {
        return totalHardwareSales;
    }
}

class Software implements Item {
    private String type;
    private String os;
    private double sales;
    private static double totalSoftware = 0;

    public Software(String type, String os, double sales) {
        this.type = type;
        this.os = os;
        this.sales = sales;
        totalSoftware += this.sales;
    }

    @Override
    public double calculateSales() {
        return totalSoftware;
    }
}

public class SalesCalculator {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of products");
        n = sc.nextInt();

        Software[] s = new Software[n];
        Hardware[] h = new Hardware[n];

        int scnt = 0;
        int hcnt = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("1. Hardware\n2. Software");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            if (choice == 1) {
                System.out.println("Enter Category:");
                String c= sc.nextLine();
                System.out.println("Manufacturer:");
                String m = sc.nextLine();
                System.out.println("Enter sales:");
                double sale = sc.nextDouble();
                h[hcnt] = new Hardware(c, m, sale);
                hcnt++;
            } else if (choice == 2) {
                System.out.println("Enter Software Type:");
                String type = sc.nextLine();
                System.out.println("Operating System:");
                String os = sc.nextLine();
                System.out.println("Enter sales:");
                double sales = sc.nextDouble();
                s[scnt] = new Software(type, os, sales);
                scnt++;
            }
        }

        // Calculate and print total sales for hardware and software items
        System.out.println("Total sales for hardware items: " + h[0].calculateSales());
        System.out.println("Total sales for software items: " + s[0].calculateSales());

        sc.close();
    }
}
