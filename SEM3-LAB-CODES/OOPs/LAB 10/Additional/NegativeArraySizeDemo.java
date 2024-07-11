public class NegativeArraySizeDemo {
    public static void main(String[] args) {
        try {
            int size = -5;
            if (size < 0) {
                throw new NegativeArraySizeException("Array size cannot be negative.");
            }
            int[] arr = new int[size];
        } catch (NegativeArraySizeException e) {
            System.out.println(e.getMessage());
        }
    }
}
