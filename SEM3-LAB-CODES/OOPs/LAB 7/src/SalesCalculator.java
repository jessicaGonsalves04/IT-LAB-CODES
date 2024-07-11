import java.util.Scanner;

interface Item {
    double calculateSales();
}

class Hardware implements Item {
    private String category;
    private String manufacturer;
    private double sales;
    private static double totalHardwareSales = 0;

    public Hardware(String category, String manufacturer, double sales) {
        this.category = category;
        this.manufacturer = manufacturer;
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
    private String operatingSystem;
    private double sales;
    private static double totalSoftwareSales = 0;

    public Software(String type, String operatingSystem, double sales) {
        this.type = type;
        this.operatingSystem = operatingSystem;
        this.sales = sales;
        totalSoftwareSales += this.sales;
    }

    @Override
    public double calculateSales() {
        return totalSoftwareSales;
    }
}

public class SalesCalculator {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of products");
        n = sc.nextInt();

        Software[] softwareArray = new Software[n];
        Hardware[] hardwareArray = new Hardware[n];

        int softwareCount = 0;
        int hardwareCount = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("1. Hardware\n2. Software");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            if (choice == 1) {
                System.out.println("Enter Category:");
                String category = sc.nextLine();
                System.out.println("Manufacturer:");
                String manufacturer = sc.nextLine();
                System.out.println("Enter sales:");
                double sales = sc.nextDouble();
                hardwareArray[hardwareCount] = new Hardware(category, manufacturer, sales);
                hardwareCount++;
            } else if (choice == 2) {
                System.out.println("Enter Software Type:");
                String type = sc.nextLine();
                System.out.println("Operating System:");
                String operatingSystem = sc.nextLine();
                System.out.println("Enter sales:");
                double sales = sc.nextDouble();
                softwareArray[softwareCount] = new Software(type, operatingSystem, sales);
                softwareCount++;
            }
        }

        // Calculate and print total sales for hardware and software items
        System.out.println("Total sales for hardware items: " + hardwareArray[0].calculateSales());
        System.out.println("Total sales for software items: " + softwareArray[0].calculateSales());

        sc.close();
    }
}
