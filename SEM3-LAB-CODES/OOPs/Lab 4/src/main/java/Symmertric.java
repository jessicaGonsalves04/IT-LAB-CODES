/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class Symmertric {
    public static void main(String[] args) {
        int rows,cols,flag=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows:");
        rows=sc.nextInt();
        System.out.println("Enter the number of columns:");
        cols= sc.nextInt();
        int matrix[][]=new int[rows][cols];
        if(rows!=cols){
            System.out.println("Not symmetric");
            return;
        }
        System.out.println("Enter the matrix elements:");
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        
        
         for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if( matrix[i][j]!= matrix[j][i]){
                 flag=1;
                 break;
                 }
    
            }
        }
         if(flag==1)
             System.out.println("Not symmetric");
         else
             System.out.println("Symmetric");
        
    
}
}
