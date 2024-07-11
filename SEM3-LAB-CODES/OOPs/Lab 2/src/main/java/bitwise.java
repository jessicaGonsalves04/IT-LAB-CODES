/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class bitwise {
    public static void main(String args[]){
        int number,l,r;
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number:");
        number=sc.nextInt();
        l=number<<1;
        r=number>>1;
       System.out.println(number+"*"+2+"="+l+"\n"+number+"/"+2+"="+r);
       
        
        
        
        
        
    }
}
