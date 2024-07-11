import java.util.Scanner;
class Box{
    static int count=0;
    int width,height,depth;
    Box(int w, int h,int d){
        width=w;
        height=h;
        depth=d;
        count=count+1;
    }
}
class Q3{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int w,h,d,i=0;
        char ch;
        Box b[]=new Box[10];
        do{
            System.out.println("Enter width:");
            w=sc.nextInt();
            System.out.println("Enter depth:");
            d=sc.nextInt();
            System.out.println("Enter height");
            h=sc.nextInt();
            b[i]=new Box(w,d,h);
            i++;
            System.out.println("Create Another box?");
            ch=sc.next().charAt(0);
        }while(ch=='y');
        System.out.println("Number of boxes:"+b[0].count);


        }

    }
