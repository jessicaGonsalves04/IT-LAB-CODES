/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
 class Time{
    int hour;
    int min;
    int sec;
 Time(){
        this.hour=0;
        this.min=0;
        this.sec=0;
    }
    Time(int h,int m,int s){
        hour=h;
        min=m;
        sec=s;
    }
    void Add(Time t1,Time t2){
        hour=t1.hour+t2.hour;
        min=t1.min+t2.min;
        sec=t1.sec+t2.sec;
        min= min+sec/60;
        sec=sec%60;
        hour=hour+min/60;
        min=min%60;
    }
    void display(){
        System.out.println(hour+":"+min+":"+sec);
    }
    
    }
public class timedata {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int h,m,s;
        Time time1=new Time();
        System.out.println("Time 1:");
        time1.display();
        System.out.println("Time 2");
        Time time2=new Time();
        time2.display();

        System.out.println("Time 1:Enter hour min sec");
        h=sc.nextInt();
        m=sc.nextInt();
        s=sc.nextInt();
        time1= new Time(h,m,s);

        System.out.println("Time 2:Enter hour min sec");
        h=sc.nextInt();
        m=sc.nextInt();
        s=sc.nextInt();
        time2= new Time(h,m,s);

        System.out.println("Time 1:");
        time1.display();
        System.out.println("Time 2:");
        time2.display();
        Time sum =new Time();
        sum.Add(time1,time2);
        System.out.println("Sum: ");
        sum.display();
        
    }
    
}
