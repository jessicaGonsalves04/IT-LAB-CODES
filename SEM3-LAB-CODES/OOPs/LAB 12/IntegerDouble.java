class Node<T> 
{
    T data;
    Node<T> next;
    public Node(T data) 
    {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList<T> 
{
    private Node<T> head;
    private int size;
    public SinglyLinkedList() 
    {
        head = null;
        size = 0;
    }

    public void add(T data) 
    {
        Node<T> newNode = new Node<>(data);
        if (head == null) 
        {
            head = newNode;
        } 
        else 
        {
            Node<T> current = head;
            while (current.next != null) 
            {
                current = current.next;
            }
            current.next = newNode;
        }
        size++;
    }

    public void display() 
    {
        Node<T> current = head;
        while (current != null) 
        {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public int getSize() 
    {
        return size;
    }
}
public class IntegerDouble {
    public static void main(String[] args) 
    {
        SinglyLinkedList<Integer> intList = new SinglyLinkedList<>();
        SinglyLinkedList<Double> doubleList = new SinglyLinkedList<>();

        intList.add(5);
        intList.add(10);
        intList.add(15);

        doubleList.add(2.5);
        doubleList.add(3.7);
        doubleList.add(6.1);

        System.out.print("Integer List: ");
        intList.display();

        System.out.print("Double List: ");
        doubleList.display();
    }
}