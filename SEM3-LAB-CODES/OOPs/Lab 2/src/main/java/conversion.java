/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class conversion {
    public static void main(String args[]){
        int num;
        double number;
        char a;
        int c,e;
        byte b,d;
        System.out.println("Enter an integer:");
        Scanner sc= new Scanner(System.in);
        num=sc.nextInt();
        b=(byte)num;
        System.out.println("Enter a double number:");
        number=sc.nextDouble();
        d=(byte)number;
        e=(int)number;
        System.out.println("Enter a character:");
        a=sc.next().charAt(0);
        c=(int)a;
        System.out.println("Int "+num+" to byte is ="+b);
        System.out.println("Char "+a+" to int is ="+c);
        System.out.println("Double "+number+" to byte is ="+d);
        System.out.println("Double "+number+" to int is ="+e);
        
        
        
        
        
        
        
         
        
        
        
    }
    
}
