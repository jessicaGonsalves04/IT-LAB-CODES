public class SyncMethodDemo {
    public static void main(String[] args) {
        SharedRes resource = new SharedRes();

        Thread t1 = new Thread(() -> {
            resource.t1();
        });

        Thread t2 = new Thread(() -> {
            resource.t2();
        });

        t1.start();
        t2.start();
    }
}

class SharedRes {
    public synchronized void t1() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Task 1: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized void t2() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Task 2: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
