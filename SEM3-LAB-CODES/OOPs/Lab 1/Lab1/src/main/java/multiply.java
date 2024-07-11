/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class multiply {
    public static void main(String args[]){
        int n,i,j,prod;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number whose table is required:");
        n=in.nextInt();
        System.out.println("The number till which u want the table");
        j=in.nextInt();
        for(i=1;i<=j;i++)
        {    prod=n*i;
            System.out.println(n+"*"+i+"="+prod);
        }
        
        
        
        
    }
    
    
}
