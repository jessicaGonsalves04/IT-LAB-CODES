/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class number {
    public static void main(String args[]){
        int num,pcnt=0,ncnt=0,zcnt=0,i,n;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the number of elements:\n");
        num=in.nextInt();
        for(i=0;i<num;i++)
        {
            System.out.println("Enter the number:");
            n=in.nextInt();
            if(n>0)
            {
                pcnt++;
            }
            else if(n<0)
            
            {
                ncnt++;
            
            }
            else if(n==0)
                    {
                        zcnt++;
                    }
            
        }
        System.out.println("Positive="+pcnt+"\nNegative="+ncnt+"\nZeros="+zcnt);
        
        
    }
    
}
