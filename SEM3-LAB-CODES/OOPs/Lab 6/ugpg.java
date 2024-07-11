import java.util.Scanner;

class Student {
    int regno;
    String name;
    int age;

    Student(int rn, String n, int a) {
        this.regno = rn;
        this.name = n;
        this.age = a;
    }

    void display() {
        System.out.println("Registration No: " + regno + "\nName: " + name + "\nAge: " + age);
    }
}

class UG extends Student {
    int sem;
    double fees;

    UG(int rn, String n, int a, int sem, double fees) {
        super(rn, n, a);
        this.sem = sem;
        this.fees = fees;
    }

    void displayUG() {
        super.display();
        System.out.println("Semester: " + sem + "\nFees: " + fees);
    }
}

class PG extends Student {
    int sem;
    double fees;

    PG(int rn, String n, int a, int sem, double fees) {
        super(rn, n, a);
        this.sem = sem;
        this.fees = fees;
    }

    void displayPG() {
        super.display();
        System.out.println("Semester: " + sem + "\nFees: " + fees);
    }
}

public class ugpg {
    public static void main(String[] args) {
        int num, ch, regno, age, sem;
        String name;
        double fees;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students");
        num = sc.nextInt();
        UG[] u = new UG[100];
        PG[] p = new PG[100];
        int ugcount = 0, pgcount = 0;
        sc.nextLine(); // Consume the newline character

        for (int i = 0; i < num; i++) {
            System.out.println("Reg No: ");
            regno = sc.nextInt();
            sc.nextLine(); 
            System.out.println("Name: ");
            name = sc.nextLine();
            System.out.println("Enter age: ");
            age = sc.nextInt();
            System.out.println("Semester: ");
            sem = sc.nextInt();
            System.out.println("Fees: ");
            fees = sc.nextDouble();
            System.out.println("UG/PG (1/2): ");
            ch = sc.nextInt();
            if (ch == 1) {
                u[ugcount] = new UG(regno, name, age, sem, fees);
                ugcount++;
            } else if(ch==2) {
                p[pgcount] = new PG(regno, name, age, sem, fees);
                pgcount++;
            }
            else
            break;
        }

        System.out.println("\nPG students: ");
        for (int i = 0; i < pgcount; i++)
            p[i].displayPG();

        System.out.println("\nUG students: ");
        for (int i = 0; i < ugcount; i++)
            u[i].displayUG();

        System.out.println("\nTotal UG admissions: " + ugcount);
        System.out.println("\nTotal PG admissions: " + pgcount);
    }
}
