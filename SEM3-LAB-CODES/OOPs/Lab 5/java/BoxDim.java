/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;
class Box{
    double width;
    double height;
    double depth;
    Box(double w,double h,double d){
        width=w;
        height=h;
        depth=d;
    }
    double Volume(){
        return width*depth*height;
    }
}
public class BoxDim {
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        double width;
        double height;
        double depth;
        System.out.println("Width:");
        width=sc.nextDouble();
        System.out.println("Height:");
        height=sc.nextDouble();
        System.out.println("Depth:");
        depth=sc.nextDouble();
        Box mybox=new Box(width,height,depth);
        System.out.println("Volume is: "+mybox.Volume());
    }
    
}
