/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class AddMultiply {
    public static void main(String args[]){
        int m,n,p,q;
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter the no of rows in Matrix 1");
        m= sc.nextInt();
        System.out.println("Enter the no of columns in Matrix 1");
        n= sc.nextInt();
        System.out.println("Enter the no of rows in Matrix 2");
        p= sc.nextInt();
        System.out.println("Enter the no of columns in Matrix 2");
        q= sc.nextInt();
        int A[][]= new int[m][n];
        int B[][]= new int[p][q];
        System.out.println("Enter the matrix elements of Matrix 1:");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                A[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the matrix elements of Matrix 2:");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                B[i][j]=sc.nextInt();
            }
        }
        //to add the matrices
        if(m==p && n==q){
            int C[][]= new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    C[i][j]=A[i][j]+B[i][j];
                }
            }
         
            System.out.println("The sum of the two matrices are:");
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    System.out.print(C[i][j]+"\t");
                }
                System.out.println();
            }
            
        }
        else
            System.out.println("Cannot add");
        // to multiply the matrices
        if(n!=p){
            System.out.println("Cannot multiply.");
            return;
        }
        int C[][]=new int[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                C[i][j]=0;
                for(int k=0;k<n;k++){
                    C[i][j]=C[i][j]+A[i][k]*B[k][j];
                }
                }
        }
        System.out.println("The product of two matrices are:");
        for(int i=0;i<m;i++){
                for(int j=0;j<q;j++){
                    System.out.print(C[i][j]+"\t");
                }
                System.out.println();
            }
        
    }
}
