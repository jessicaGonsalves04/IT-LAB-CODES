
import java.util.ArrayList;
import java.util.Scanner;


 
public class Q2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter String");
        String str = s.nextLine();
        System.out.println("Enter String To Be Replaced");
        String str2 = s.nextLine();
        char[] c = str.toCharArray();
        ArrayList<Character> arr = new ArrayList<Character>();
         for(int i = 0 ; i<str.length(); i++){
            //Boolean repeats = false;
             for(int j = i+1 ; j<str.length(); j++){
             if(c[i] == c[j]){
                 if(!arr.contains(c[i])){
                     arr.add(c[i]);
                 }
             }
                 
                 
             }
             
             }
         for(char a: arr){
             str = str.replaceAll(""+a, str2);
         }
         System.out.println(str);
         //System.out.println("Repeating" + arr.toString());
    }
   
}