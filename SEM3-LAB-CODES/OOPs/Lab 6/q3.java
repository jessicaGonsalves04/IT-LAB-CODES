import java.util.Scanner;

class Bank {
    double IR;

    double getInterestRate() {
        return 0;
    }
}

class SBI extends Bank {
    SBI() {
        IR = 8.0;
    }

    double getInterestRate() {
        return IR;
    }
}

class ICICI extends Bank {
    ICICI() {
        IR = 7.0;
    }

    double getInterestRate() {
        return IR;
    }
}

class AXIS extends Bank {
    AXIS() {
        IR = 9.0;
    }

    double getInterestRate() {
        return IR;
    }
}

public class q3 {
    public static void main(String[] args) {
        double p, t;
        Scanner sc = new Scanner(System.in);
        SBI sbibank = new SBI();
        ICICI icicibank = new ICICI();
        AXIS axisbank = new AXIS();
        
        System.out.println("Interest rates");
        System.out.println("SBI: " + sbibank.getInterestRate() + "\nICICI: " + icicibank.getInterestRate() + "\nAXIS: " + axisbank.getInterestRate());

        System.out.println("Enter Principal Amount:");
        p = sc.nextDouble();
        System.out.println("Enter duration:");
        t = sc.nextDouble();
        System.out.println("Interest: ");
        System.out.println("SBI: " + (sbibank.getInterestRate() * p * t / 100) + "\nICICI: " + (icicibank.getInterestRate() * p * t / 100) + "\nAXIS: " + (axisbank.getInterestRate() * p * t / 100));
    }
}
