/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class AOE {
    public static void main(String[] args) {
        int n;
        System.out.println("Enter number of elements:");
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int[]arr=new int[3];
        try{
            for(int i=0;i<n;i++){
                arr[i]=sc.nextInt();
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
           System.out.println("Array Overflow Exception");
            System.out.println(e);
        }
        finally{
            System.out.println("Inside Finally block");
        }
    }
    
}
