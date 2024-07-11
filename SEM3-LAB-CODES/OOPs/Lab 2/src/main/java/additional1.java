/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class additional1 {
     public static void main(String args[]){
         int a;
        int b;
         int n;
         int flag=0;
         char q;
         Scanner sc= new Scanner(System.in);
         do{
            System.out.println("enter a: ");
            a= sc.nextInt();
            System.out.println("enter b: ");
            b= sc.nextInt();
         System.out.println("Enter the operation you want to perform:");
        n=sc.nextInt();
        switch(n){
            case 1:
            {
                int result=(a<<2)+(b>>2);
                System.out.println(result);
                break;
            }
            case 2:
            {
                System.out.println(b>0);
                 break;
          }
            case 3:
            {
                System.out.println((a+b*100)/10);
                break;
                
            }
            case 4:
            {
                System.out.println(a&b);
                break;
                
            }
            
            default:
            {
                System.out.println("Invalid");
                break;
            }
     }
     System.out.println("Continue(y/n)?");
     
         q=sc.next().charAt(0);
         if(q=='y')
             flag=1;
         else if(q=='n')
             flag=0;
         } while(flag==1);

    
}

 }

