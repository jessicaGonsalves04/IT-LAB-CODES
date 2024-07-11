/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class calc {
     public static void main(String args[]){
         double a;
         double b;
         char op,q;
         int flag=0;
         do
         {
         System.out.println("Enter the first number ,operator,second number");
         Scanner sc= new Scanner(System.in);
         a=sc.nextDouble();
         op=sc.next().charAt(0);
         b=sc.nextDouble();
         double add=a+b;
         double sub=a-b;
         double multi=a*b;
         double div=a/b;
         switch(op)
         {
             case '+':
             {
                 System.out.println("Answer = "+add);
                 break;
             }
             case '-':
             {
                 System.out.println("Answer = "+sub);
                 break;
             }
             case '*':
             {
                 System.out.println("Answer = "+multi);
                 break;
             }
             case '/':
             {
                 System.out.println("Answer = "+div);
                 break;
             }
             default:
                 System.out.println("inavlid");
                 
         }
         System.out.println("Do another (y/n)?");
         q=sc.next().charAt(0);
         if(q=='y')
             flag=1;
         else if(q=='n')
             flag=0;
         }while(flag ==1);
         
         
         
         
         
     }
    
    
}
