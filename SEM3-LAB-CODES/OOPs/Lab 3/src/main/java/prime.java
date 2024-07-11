/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class prime {
    public static void main(String args[]){
        int m,n,flag;
        System.out.println("Enter the limits m and n:");
        Scanner sc =new Scanner(System.in);
        m=sc.nextInt();
        n=sc.nextInt();
        int i,j;
        for(i=m+1;i<n;i++)
        {
            flag=0;
            for(j=2;j<i;j++)
            {
                if(i%j==0)
                    flag++;
            }
            if(flag==0)
                System.out.println(i);
        }
        
        
        
    }
    
}
