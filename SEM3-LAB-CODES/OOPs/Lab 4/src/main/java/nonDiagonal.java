/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class nonDiagonal {
    public static void main(String[] args) {
        int rows,cols;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows:");
        rows=sc.nextInt();
        System.out.println("Enter the number of columns:");
        cols= sc.nextInt();
        int matrix[][]=new int[rows][cols];
        System.out.println("Enter the matrix elements:");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        if(rows==cols)
        {int sum=0;
        System.out.println("Non-diagonal elements");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i!=j && i+j!=rows-1){
                    System.out.println(matrix[i][j]);
                    sum+=matrix[i][j];
                }
        }
    }
    System.out.println("\n Sum of non diagonal elements is:"+sum);
}    
else
System.out.println("Not a square matrix."); 
}
}

    

