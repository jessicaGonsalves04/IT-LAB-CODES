class M {
    private int[][] m;

    M(int r, int c) {
        m = new int[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = (int) (Math.random() * 100);
    }

    void d() {
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[0].length; j++) {
                System.out.print(m[i][j] + "\t");
            }
            System.out.println();
        }
    }

    void t() {
        for (int j = 0; j < m[0].length; j++) {
            for (int i = 0; i < m.length; i++) {
                System.out.print(m[i][j] + "\t");
            }
            System.out.println();
        }
    }

    void ma() {
        int max = m[0][0];
        for (int[] r : m)
            for (int v : r)
                max = Math.max(max, v);
        System.out.println("Max value: " + max);
    }

    void pd() {
        for (int i = 0; i < m.length; i++)
            System.out.print(m[i][i] + "\t");
        System.out.println();
    }

    void nd() {
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[0].length; j++)
                if (i != j)
                    System.out.print(m[i][j] + "\t");
        System.out.println();
    }

    boolean isThreadAlive(Thread thread) {
        return thread.isAlive();
    }
}

public class Q3 {
    public static void main(String[] a) {
        M m = new M(4, 4);

        Thread t1 = new Thread(() -> m.d());
        Thread t2 = new Thread(() -> m.t());
        Thread t3 = new Thread(() -> m.ma());
        Thread t4 = new Thread(() -> m.pd());
        Thread t5 = new Thread(() -> m.nd());

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();

        System.out.println("Thread t1 is alive: " + m.isThreadAlive(t1));
        System.out.println("Thread t2 is alive: " + m.isThreadAlive(t2));
        System.out.println("Thread t3 is alive: " + m.isThreadAlive(t3));
        System.out.println("Thread t4 is alive: " + m.isThreadAlive(t4));
        System.out.println("Thread t5 is alive: " + m.isThreadAlive(t5));

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }

        System.out.println("All threads have completed.");

        System.out.println("Thread t1 is alive: " + m.isThreadAlive(t1));
        System.out.println("Thread t2 is alive: " + m.isThreadAlive(t2));
        System.out.println("Thread t3 is alive: " + m.isThreadAlive(t3));
        System.out.println("Thread t4 is alive: " + m.isThreadAlive(t4));
        System.out.println("Thread t5 is alive: " + m.isThreadAlive(t5));
    }
}
