/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */

public class NFE {
    public static void main(String[] args) {
        String str="Hello";
        try{
        int n=Integer.parseInt(str);
        }
        catch(NumberFormatException e){
            System.out.println("Error");
            System.out.println(e);
        }
        finally{
            System.out.println("inside finally");
        }
       
    
}
}
