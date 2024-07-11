
import java.util.Scanner;
public class patternforeach {
    public static void main(String args[]) {
        int n;
        int[][] a;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows:");
        n = sc.nextInt();
        a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                a[i][j] = i + 1;
            }
        }
        for (int[] row : a) {
            for (int num : row) {
                if (num != 0)
                    System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
