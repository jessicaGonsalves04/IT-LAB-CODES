/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class rectangle {
    public static void main(String args[]){
        int l,b,a,p;
        System.out.println("Enter the length of the rectangle:");
        Scanner sc= new Scanner(System.in);
        l=sc.nextInt();
        System.out.println("Enter the breadth of the rectangle:");
        b=sc.nextInt();
        p=2*(l+b);
        a=l*b;
        System.out.println("The area of the rectangle is "+a+"\nThe perimeter is "+p);
        
        
        
    }
    
}
