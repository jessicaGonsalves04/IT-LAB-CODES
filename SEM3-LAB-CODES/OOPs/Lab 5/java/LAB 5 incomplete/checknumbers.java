/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
class Number{
    private double num;
    Number(double n){
        num=n;
    }
    boolean isZero()
    {
        if(num==0)
            return true;
        else
            return false;
    }
    boolean isNegative(){
        if(num<0)
            return true;
        else
            return false;
    }
    boolean isEven(){
        if(num%2==0){
            return true;
        }
        else
            return false;
    }
    boolean isOdd(){
        if(num%2!=0){
            return true;
        }
        else
            return false;
    }
    boolean isPrime(){
        int flag=0;
        int i;
        if(num<=1){
            return false;
        }
        for( i=2;i<num;i++){
            if(num%i==0)
                flag++;
        }
        if(flag==0)
            return true;
        else
            return false;

    }
    boolean isArmstrong(){
        int dig,sum = 0,number;
        number= (int)num;
        while(number!=0){
            dig=number%10;
            sum=sum +(int) Math.pow(dig,3);
            number=number/10;
        }
        if(sum!=(int)num)
            return false;
        else 
        return true;
    }
}
public class checknumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        double n= sc.nextDouble();
        Number n1= new Number(n);
        System.out.println("The number is zero:"+ n1.isZero());
        System.out.println("The number is Negative:"+n1.isNegative());
        System.out.println("The number is Odd:"+n1.isOdd());
        System.out.println("The number is even:"+n1.isEven());
        System.out.println("The number is Prime:"+n1.isPrime());
        System.out.println("The number is Armstrong:"+n1.isArmstrong());
    }
}
