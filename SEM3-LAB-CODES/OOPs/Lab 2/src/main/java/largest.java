/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class largest {
    public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int a,b,c;
    int largest,smallest;
    System.out.println("Enter a:");
    a=sc.nextInt();
    System.out.println("Enter b:");
    b=sc.nextInt();
    System.out.println("Enter c:");
    c=sc.nextInt();
    largest=(a>b)?(a>c?a:c):(b>c?b:c);
    smallest=(a<b)?(a<c?a:c):(b<c?b:c);
    System.out.println("Largest= "+largest+" Smallest= "+smallest);
    }
    
}
