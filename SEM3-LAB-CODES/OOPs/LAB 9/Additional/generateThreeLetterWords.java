import java.util.Scanner;

public class ThreeLetterWordsGenerator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a five-letter word: ");
        String inputWord = sc.nextLine();

        if (inputWord.length() != 5) {
            System.out.println("Please enter a valid five-letter word.");
        } else {
            generateThreeLetterWords(inputWord);
        }

        sc.close();
    }

    public static void generateThreeLetterWords(String word) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (i != j && i != k && j != k) {
                        System.out.println("" + word.charAt(i) + word.charAt(j) + word.charAt(k));
                    }
                }
            }
        }
    }
}
