/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
public class Timeinfo {
     public static void main(String args[]){
        T time1=new T(10,26,56);
        T time2=new T(11,23,44);
        time1.Add(time1,time2);
        time1.display();
        
}
    
}
class T{
    int hour;
    int min;
    int sec;
    T(){
        hour=0;
        min=0;
        sec=0;
    }
   T(int h,int m,int s){
        hour=h;
        min=m;
        sec=s;
    }
    void Add(T t1,T t2){
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

