import java.util.Scanner;

 class Q1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string:");
        String input = sc.nextLine();

        int charCount = input.length();
        int spaceCount = countSpaces(input);
        int wordCount = countWords(input);
        String[] lines = input.split("\n");
        int lineCount = lines.length;
        int vowelCount = countVowels(input);

        System.out.println("Char count: " + charCount);
        //System.out.println("Space count: " + spaceCount);
        System.out.println("Word count: " + wordCount);
        System.out.println("Line count: " + lineCount);
        System.out.println("Vowel count: " + vowelCount);

        sc.close();
    }

    public static int countSpaces(String str) {
        int spaceCount = 0;
        for (char c : str.toCharArray()) {
            if (Character.isWhitespace(c)) {
                spaceCount++;
            }
        }
        return spaceCount;
    }

    public static int countWords(String str) {
        int wordCount = 0;
        boolean inWord = false;

        for (char c : str.toCharArray()) {
            if (Character.isWhitespace(c)) {
                inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                }
                inWord = true;
            }
        }

        return wordCount;
    }

    public static int countVowels(String str) {
        str = str.toLowerCase();
        int vowelCount = 0;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (isVowel(c)) {
                vowelCount++;
            }
        }
        return vowelCount;
    }

    public static boolean isVowel(char c) {
        c = Character.toLowerCase(c); // Convert to lowercase to handle both uppercase and lowercase vowels
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
}
