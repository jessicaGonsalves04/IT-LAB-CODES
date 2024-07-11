/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class factorial {
    public static void main(String args[]){
        int n,i,factorial=1;
        Scanner in= new Scanner(System.in);
        System.out.println("Enter the number whose factorial is to be found:");
        n=in.nextInt();
        for(i=n;i>1;i--)
            factorial=factorial*i;
        System.out.println("The factorial of "+n+" is"+factorial);
        
        
        
        
    }
    
}
