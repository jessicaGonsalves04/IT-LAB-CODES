/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class check {
    public static void main(String args[]){
        int n;
        System.out.println("Enter the operation you want to perform:");
        Scanner sc= new Scanner(System.in);
        n=sc.nextInt();
        switch(n){
            case 1:
            {
                int x=10;
                double y=x;
                System.out.println(y);
                break;
            }
            case 2:
            {
                double x=10.5;
                int y = x;
                System.out.println(y);
                break;
                        
            }
            case 3:
            {
                double x=10.5;
                int y=(int)x;
                System.out.println(y);
                break;
                
            }
            default:
            {
                System.out.println("Invalid");
                break;
            }
                
                
        }
    }
    
    
}
