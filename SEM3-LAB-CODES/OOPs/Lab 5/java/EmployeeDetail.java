/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
class Employee{
    String employeeName;
    String city;
    double salary;
    double DA;
    double HRA;
    double total;
    void getdata(int i){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Detail of Employee"+(i+1));
        System.out.println("Employee Name: ");
        employeeName=sc.nextLine();
        System.out.println("City: ");
        city=sc.nextLine();
        System.out.println("Salary: ");
        salary=sc.nextDouble();
        System.out.println("Dearness allowance(%):");
        DA=sc.nextDouble();
        System.out.println("House rent(%):");
        HRA=sc.nextDouble();
    }
    double calc(){
        total=salary+salary*DA/100+salary*HRA/100;
        return total;
        
    }
    void display(int k){
        System.out.println("Total of Employee "+(k+1)+"is = "+calc());
    }
        
    
    }
 public class EmployeeDetail {
    public static void main(String args[]){
    Employee [] emp= new Employee[10];
    for(int i=0;i<2;i++){
    emp[i]=new Employee();
    emp[i].getdata(i);
   }
   for(int j=0;j<2;j++){
    emp[j].display(j);
   }
}
}
