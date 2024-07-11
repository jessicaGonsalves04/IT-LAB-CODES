public class SyncStatementDemo {
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
    public void t1() {
        synchronized (this) {
            for (int i = 1; i <= 3; i++) {
                System.out.println("Task 1: " + i);
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void t2() {
        synchronized (this) {
            for (int i = 1; i <= 3; i++) {
                System.out.println("Task 2: " + i);
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
