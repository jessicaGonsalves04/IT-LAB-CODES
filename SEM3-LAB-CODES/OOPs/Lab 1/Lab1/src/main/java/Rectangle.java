/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class Rectangle {
    public static void main(String args[]){
        int length, breadth, area, perimeter;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length:");
        length=sc.nextInt();
        System.out.println("Enter the breadth:");
        breadth=sc.nextInt();
        area=length*breadth;
        perimeter=2*(length+breadth);
         System.out.println("Area="+area+"\nPerimeter="+perimeter);
        
        
        
                
    }
    
}
