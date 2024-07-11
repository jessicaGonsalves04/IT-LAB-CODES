import java.util.Scanner;

class Account {
    String name;
    String type;
    int accno;

    Account(String n, int a, String t) {
        this.name = n;
        this.accno = a;
        this.type = t;
    }
}

class Current extends Account {
    int balance;

    Current(String n, int a, String t) {
        super(n, a, t);
        balance = 0;
    }

    void deposit(int d) {
        balance += d;
        System.out.println(d + " deposited in current account");
    }

    void display() {
        System.out.println("Balance in current account: " + balance);
    }

    void withdraw(int w) {
        balance -= w;
        System.out.println(w + " withdrawn from current account");
        checkBalance();
    }

    void checkBalance() {
        if (balance < 1000) {
            int serviceTax = (int) (balance * 0.05);
            balance -= serviceTax;
            System.out.println("Service tax of 5% imposed.");
        }
    }
}

class Savings extends Account {
    int balance;

    Savings(String n, int a,String t) {
        super(n, a, t);
        balance = 0;
    }

    void calcInterest() {
        int interestRate = (int) (balance * 0.05);
        balance += interestRate;
        System.out.println("Interest added: " + interestRate);
    }

    void withdraw(int w) {
        balance -= w;
        System.out.println(w + " withdrawn from savings account");
    }

    void deposit(int d) {
        balance += d;
        System.out.println(d + " deposited in savings account");
    }

    void display() {
        System.out.println("Balance in savings account: " + balance);
    }
}

public class q1 {
    public static void main(String[] args) {
        int x;
        Scanner sc = new Scanner(System.in);

        Savings acc1 = new Savings("Jack", 204812,"savings");
        Current acc2 = new Current("Jack", 204812, "current");

        acc1.display();
        acc2.display();

        System.out.println("Amount to be deposited in savings account:");
        x = sc.nextInt();
        acc1.deposit(x);
        acc1.display();

        System.out.println("Amount to be deposited in current account:");
        x = sc.nextInt();
        acc2.deposit(x);
        acc2.display();

        System.out.println("Amount to be withdrawn from savings: ");
        x = sc.nextInt();
        acc1.withdraw(x);
        acc1.display();

        System.out.println("Amount to be withdrawn from current: ");
        x = sc.nextInt();
        acc2.withdraw(x);
        acc2.display();

        System.out.println("Calculating interest (5%) on balance in savings account");
        acc1.calcInterest();
        acc1.display();
    }
}
