import java.util.Scanner;

class MyThread extends Thread {
    @Override
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println("Thread using Thread class: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class MyRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println("Thread using Runnable interface: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Create thread using Thread class");
            System.out.println("2. Create thread using Runnable interface");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    MyThread threadUsingThreadClass = new MyThread();
                    threadUsingThreadClass.start();
                    break;

                case 2:
                    MyRunnable myRunnable = new MyRunnable();
                    Thread threadUsingRunnable = new Thread(myRunnable);
                    threadUsingRunnable.start();
                    break;

                case 3:
                    sc.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}
