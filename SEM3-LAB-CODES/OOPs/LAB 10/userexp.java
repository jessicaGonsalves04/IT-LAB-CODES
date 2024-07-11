class CustomEx extends Exception {
    public CustomEx(String message) {
        super(message); 
    }
}

public class userexp {
    public static void main(String[] args) {
        try {
            int age = -5;
            if (age < 0) {
                throw new CustomEx("Age cannot be negative");
            }
            System.out.println("Age: " + age);
        } catch (CustomEx e) {
            System.out.println("Custom Exception: " + e.getMessage());
        }
    }
}
