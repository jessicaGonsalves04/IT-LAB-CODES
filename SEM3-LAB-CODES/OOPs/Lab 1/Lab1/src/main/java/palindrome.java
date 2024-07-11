


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class palindrome {
    public static void main(String args[]){
        int n, dig, rev=0,i;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number:");
        n=in.nextInt();
        i=n;
        while(n>0)
        {dig=n%10;
        rev=(rev*10)+dig;
        n=n/10;}
        if(i==rev)
            System.out.println("The number is a palindrome.");
        else
            System.out.println("The number is not a palindrome");
        
        
        
        
        
    }
    
}
