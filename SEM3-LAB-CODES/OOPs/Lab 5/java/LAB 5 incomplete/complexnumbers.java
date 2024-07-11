import java.util.Scanner;
class complex{
    int real;
    int imaginary;
    //default constructor
    complex(){
        real=0;
        imaginary=0;
    }
    complex(int real,int img){
        this.real=real;
        imaginary=img;
    }
    complex add(int n,complex c){
        complex res1= new complex();
        res1.real=c.real+n;
        res1.imaginary=c.imaginary;
        return res1;
    }
    
    complex add(complex no1,complex no2){
        complex res2= new complex();
        res2.real=no1.real+no2.real;
        res2.imaginary=no1.imaginary+no2.imaginary;
        return res2;
    }
    void display(){
        System.out.println(this.real+"+"+this.imaginary+"i");
    }
}
public class complexnumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter real and imaginary part of complex number 1");
        int re1= sc.nextInt();
        int im1=sc.nextInt();
        complex c1 = new complex(re1,im1);
        System.out.println("Enter real and imaginary part of complex number 2");
        int re2= sc.nextInt();
        int im2=sc.nextInt();
        complex c2= new complex(re2,im2);
        System.out.println("Enter the integer to add to complex 1");
        int n= sc.nextInt();
        complex result1= new complex();
        complex result2=new complex();
        result1 = c1.add(n,c1);
        result2 = c1.add(c1,c2);
        System.out.println("Result 1:");
        result1.display();
        System.out.println("Result 2:");
        result2.display();
    }
}