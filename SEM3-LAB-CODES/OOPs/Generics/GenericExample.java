class Gen<T>{//T is name of type parameter(placeholder for the actual type that will be passed)
    T ob;
    Gen(T o){
        ob=o;
    }
    T getob(){
        return ob;
    }
    void showType(){
        System.out.println("Type of T is "+ob.getClass().getName());
    }
}
class GenericExample{
    public static void main(String[] args) {
        Gen<Integer>iOb;
        iOb= new Gen<Integer>(88);
        iOb.showType();
        int v= iOb.getob();
        System.out.println("value: "+v);
        System.out.println();
        Gen<String> strOb= new Gen<String>("Generics Test");
        strOb.showType();
        String str=strOb.getob();
        System.out.println("Value: "+str);
    }
    }
