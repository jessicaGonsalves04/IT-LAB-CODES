/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class leapyear {
    public static void main(String args[]){
        int year;
        System.out.println("Enter the year:");
        Scanner in = new Scanner(System.in);
        year= in.nextInt();
        if(year%4==0)
        {
            if(year%100==0)
            {
            if(year%400==0)
                {
                    System.out.println(year+" is a leap year.");
                }
           else
                {
                System.out.println(year+" is not a leap year");
                }
            }
                else
                System.out.println(year+" is a leap year");
        }
        else
            System.out.println(year+" is not a leap year");
            
                
            
        }
         
        
        
    }
    
}
