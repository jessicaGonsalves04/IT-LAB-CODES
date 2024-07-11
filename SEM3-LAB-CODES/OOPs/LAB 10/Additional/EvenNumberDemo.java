class EvenNumberException extends Exception {
    public EvenNumberException(String message) {
        super(message);
    }
}

public class EvenNumberDemo {
    public static void main(String[] args) {
        try {
            int number = 6;
            if (number % 2 == 0) {
                throw new EvenNumberException("Even numbers are not allowed.");
            }
            System.out.println("The number is odd.");
        } catch (EvenNumberException e) {
            System.out.println(e.getMessage());
        }
    }
}
