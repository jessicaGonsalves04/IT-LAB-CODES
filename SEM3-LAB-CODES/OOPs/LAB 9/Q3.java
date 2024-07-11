


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Arrays;
import java.util.Scanner;
public class Q3 {
    public static void main(String[] args) {
        String str,revstr="";
        System.out.println("Enter the sentence:");
        Scanner sc= new Scanner(System.in);
        str=sc.nextLine();
        int l=str.length();
        for(int i=l-1;i>=0;i--){
            revstr=revstr+str.charAt(i);
        }
        System.out.println("String is a palindrome:"+str.equals(revstr));
        char []ch = str.toCharArray();
        Arrays.sort(ch);
        String newstr=new String(ch);
        System.out.println("The word in alphabetical order is:"+newstr);
        System.out.println("Revered string is:"+revstr);
        System.out.println("Concatenated String is:"+str.concat(revstr));
    }
    
}
