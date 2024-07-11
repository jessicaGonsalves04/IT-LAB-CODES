

class Matrix {
    private int[][] data;

    public Matrix(int[][] data) {
        this.data = data;
    }

    public void displayMatrix() {
        System.out.println("Matrix Form:");
        for (int[] row : data) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }

    public void displayTranspose() {
        System.out.println("Transpose of the Matrix:");
        int rows = data.length;
        int cols = data[0].length;
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void displayMaxValue() {
        int maxValue = Integer.MIN_VALUE;
        for (int[] row : data) {
            for (int element : row) {
                if (element > maxValue) {
                    maxValue = element;
                }
            }
        }
        System.out.println("Maximum value in the Matrix: " + maxValue);
    }

    public void displayPrincipalDiagonal() {
        System.out.println("Principal Diagonal Elements:");
        int rows = data.length;
        int cols = data[0].length;
        for (int i = 0; i < rows && i < cols; i++) {
            System.out.print(data[i][i] + " ");
        }
        System.out.println();
    }

    public void displayNonDiagonalElements() {
        System.out.println("Non-Diagonal Elements:");
        int rows = data.length;
        int cols = data[0].length;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i != j) {
                    System.out.print(data[i][j] + " ");
                }
            }
        }
        System.out.println();
    }
}

class Display extends Thread {
    private Matrix matrix;

    public Display(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        matrix.displayMatrix();
    }
}

class Transpose extends Thread {
    private Matrix matrix;

    public Transpose(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        matrix.displayTranspose();
    }
}

class MaxValue extends Thread {
    private Matrix matrix;

    public MaxValue(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        matrix.displayMaxValue();
    }
}

class PDiagonal extends Thread {
    private Matrix matrix;

    public PDiagonal(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        matrix.displayPrincipalDiagonal();
    }
}

class NonDiagnoal extends Thread {
    private Matrix matrix;

    public NonDiagnoal(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        matrix.displayNonDiagonalElements();
    }
}

public class MatrixThread {
    public static void main(String[] args) {
        int[][] m = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
while(true){
    
        Matrix matrix = new Matrix(m);
        Display t1 = new Display(matrix);
        Transpose t2 = new Transpose(matrix);
        MaxValue t3 = new MaxValue(matrix);
        PDiagonal t4 = new PDiagonal(matrix);
        NonDiagnoal t5 = new NonDiagnoal(matrix);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    break;
    }

}

}