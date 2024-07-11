class TwoGen<T,V>{
    T ob1;
    V ob2;
    TwoGen(T o1,V o2){
        this.ob1=o1;
        this.ob2=o2;
    }
    void showTypes(){
        System.out.println("Type of T object is "+ob1.getClass().getName());
        System.out.println("Type of V object is "+ob2.getClass().getName());
    }
    T getOb1(){
        return ob1;
    }
    V getob2(){
        return ob2;
    }
}


class DemonstrateTwoGen{
    public static void main(String[] args) {
        TwoGen<Integer ,String> tgobj=new TwoGen<Integer,String>(88,"Generics");
        tgobj.showTypes();
        int v=tgobj.getOb1();
        System.out.println("value: "+v);
        String s=tgobj.getob2();
        System.out.println("Value :"+s);
    }
    }
