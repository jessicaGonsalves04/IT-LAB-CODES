/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
public class array {
        public static void main(String[] args) {
            int[] a = {1, 2, 3, 1, 2, 1, 5, 6, 7};
            
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the value to be searched: ");
            int searchValue = sc.nextInt();
            
            boolean found = false;
            System.out.print("The value is found at locations: ");
            int index = 0;
            for (int element : a) {
                if (element == searchValue) {
                    if (found) {
                        System.out.print(", ");
                    }
                    System.out.print("a[" + index + "]");
                    found = true;
                }
                index++;
            }
            
            if (!found) {
                System.out.println("NONE");
             }
        }
    }
    

