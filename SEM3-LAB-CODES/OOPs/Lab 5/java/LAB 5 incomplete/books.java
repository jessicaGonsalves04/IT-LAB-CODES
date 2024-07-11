/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

class Book {
    String title;
    String author;
    int edition;

    Book(String title, String author, int edition) {
        this.title = title;
        this.author = author;
        this.edition = edition;
    }

    void display() {
        System.out.println(title + " " + author + " " + edition);
    }
}

public class books {
    public static void main(String[] args) {
        Book[] books = {
            new Book("Thermo", "Jake", 1),
            new Book("Thermo for all", "Jake", 2),
            new Book("ABC", "Sam", 3),
            new Book("XYZ", "Sam", 6),
            new Book("Math", "RD", 8),
            new Book("Math magic", "RD", 5)
        };

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Author's name:");
        String name = sc.nextLine();
        boolean found = false;

        for (Book book : books) {
            if (book.author.equalsIgnoreCase(name)) {
                book.display();
                found = true;
            }
        }

        if (!found) {
            System.out.println("Books by " + name + " not found.");
        }
    }
}
