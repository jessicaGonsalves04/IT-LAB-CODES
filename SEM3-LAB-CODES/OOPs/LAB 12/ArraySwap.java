import java.util.Arrays;

public class ArraySwap {
    public static <T> void swap(T[] array, int index1, int index2) 
    {
        if (index1 < 0 || index1 >= array.length || index2 < 0 || index2 >= array.length) 
        {
            System.out.println("Invalid indices. Unable to swap elements.");
            return;
        }
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static void main(String[] args) 
    {
        Integer[] intArray = {1, 2, 3, 4, 5};
        System.out.println("Before swap: " + Arrays.toString(intArray));
        swap(intArray, 1, 3);  
        System.out.println("After swap: " + Arrays.toString(intArray));
    }
}