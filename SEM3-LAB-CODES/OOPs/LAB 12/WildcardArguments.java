class Box<T> 
{
    private final T item;
    public Box(T item) 
    {
        this.item = item;
    }
    public T getItem() 
    {
        return item;
    }
}
class BoxDemo {
    public static void displayBox(Box<?> box) 
    {
        System.out.println("Box contains: " + box.getItem());
    }
}
class WildcardArguments {
    public static void main(String[] args) 
    {
        Box<Integer> intBox = new Box<>(10);
        Box<String> strBox = new Box<>("Hello");
        Box<Double> doubleBox = new Box<>(5.5);

        BoxDemo.displayBox(intBox);
        BoxDemo.displayBox(strBox);
        BoxDemo.displayBox(doubleBox);
    }
}