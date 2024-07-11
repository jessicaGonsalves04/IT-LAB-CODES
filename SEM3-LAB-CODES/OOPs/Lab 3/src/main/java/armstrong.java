/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class armstrong {
    public static void main(String args[]){
        int num;
        int dig;
        int sum=0;
        int n;
        System.out.println("Enter the number to be checked:");
        Scanner sc= new Scanner(System.in);
        num=sc.nextInt();
        n=num;
        while(num>0)
        {
            dig=num%10;
            sum =sum +(int) Math.pow(dig,3);
            num=num/10;
            
        }
        if(sum==n)
            System.out.println("The number is armstrong.");
        else
            System.out.println("Not an armstrong number.");
        
    }
    
}

    

