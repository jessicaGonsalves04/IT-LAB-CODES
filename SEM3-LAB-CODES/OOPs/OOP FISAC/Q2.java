class VowelException extends Exception {
    public VowelException(String message) {
        super(message);
    }
}

class Q2 {
    public static void main(String[] args) {
        String sentence = "This was my house";
        
        Thread countThread = new Thread(() -> {
            int vowelWordCount = 0;
            String[] words = sentence.split(" ");
            for (String word : words) {
                if (word.matches("[aeiouAEIOU].*")) {
                    vowelWordCount++;
                }
            }
            
            if (vowelWordCount == 0) {
                try {
                    throw new VowelException("Word not found which starts with a vowel.");
                } catch (VowelException e) {
                    System.err.println(e.getMessage());
                }
            } else {
                System.out.println("Number of words starting with vowels: " + vowelWordCount);
            }
        });

        Thread lengthThread = new Thread(() -> {
            String[] words = sentence.split(" ");
            for (String word : words) {
                System.out.println("Word: " + word + ", Length: " + word.length());
            }
        });

        countThread.start();
        lengthThread.start();

        try {
            countThread.join();
            lengthThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
