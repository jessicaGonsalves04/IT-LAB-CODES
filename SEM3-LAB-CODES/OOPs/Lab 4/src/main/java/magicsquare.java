
import java.util.Scanner;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
public class magicsquare {
    public static void main(String[] args) {
        int rows,cols;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows:");
        rows=sc.nextInt();
        System.out.println("Enter the number of columns:");
        cols= sc.nextInt();
        int matrix[][]=new int[rows][cols];
        if(rows!=cols){
            System.out.println("Not a magic square"); 
            return;
        }
        System.out.println("Enter the matrix elements:");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        int pdsum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==j){
                    pdsum+=matrix[i][j];
                }
            }
        }
        int sdsum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i+j== rows-1){
                    sdsum+=matrix[i][j];
                }
            }
        }
        if(pdsum!=sdsum){
            System.out.println("Not a magic square.");
            return;
        }
        for(int i=0;i<rows;i++){
            int rowsum=0;
            for(int j=0;j<cols;j++){
                rowsum+=matrix[i][j];
                }
            if(rowsum!=pdsum){
                System.out.println("Not a magic square");
                return;
            }
        }
        for(int i=0;i<cols;i++){
            int colsum=0;
            for(int j=0;j<rows;j++){
                colsum+=matrix[j][i];
                }
            if(colsum!=pdsum){
                System.out.println("Not a magic square");
                return;
            }
        }
        System.out.println("Magic Square");
     }
    }
