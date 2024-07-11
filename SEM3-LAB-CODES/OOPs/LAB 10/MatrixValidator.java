class MatrixEx extends Exception {
    public MatrixEx(String message) {
        super(message);
    }
}

public class MatrixValidator {
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9,5}
        };

        try {
            validate(matrix);
            System.out.println("Matrix is valid (square).");
        } catch (MatrixEx e) {
            System.out.println("Matrix is not valid: " + e.getMessage());
        }
    }

    public static void validate(int[][] matrix) throws MatrixEx {
        int rows = matrix.length;
        for (int i = 0; i < rows; i++) {
            if (matrix[i].length != rows) {
                throw new MatrixEx("Matrix is not square.");
            }
        }
    }
}
