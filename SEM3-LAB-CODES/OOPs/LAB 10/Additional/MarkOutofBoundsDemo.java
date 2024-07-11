class MarkOutofBoundsException extends Exception {
    public MarkOutofBoundsException(String message) {
        super(message);
    }
}

class Student {
    private int mark;

    public Student(int mark) throws MarkOutofBoundsException {
        if (mark < 0 || mark > 100) {
            throw new MarkOutofBoundsException("Mark is out of bounds (0-100).");
        }
        this.mark = mark;
    }

    public int getMark() {
        return mark;
    }
}

public class MarkOutofBoundsDemo {
    public static void main(String[] args) {
        try {
            int mark = 110;
            Student student = new Student(mark);
            System.out.println("Mark: " + student.getMark());
        } catch (MarkOutofBoundsException e) {
            System.out.println(e.getMessage());
        }
    }
}
