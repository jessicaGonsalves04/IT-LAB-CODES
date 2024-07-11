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
}

public class Q2 {
    public static void main(String[] a) {
        M m = new M(4, 4);
        Thread t1 = new Thread(m::d);
        Thread t2 = new Thread(m::t);
        Thread t3 = new Thread(m::ma);
        Thread t4 = new Thread(m::pd);
        Thread t5 = new Thread(m::nd);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}
