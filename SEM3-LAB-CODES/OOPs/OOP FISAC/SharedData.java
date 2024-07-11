class SharedData {
    private String sentence;
    private boolean printComplete = false;

    public String getSentence() {
        return sentence;
    }

    public void setSentence(String sentence) {
        this.sentence = sentence;
    }

    public boolean isPrintComplete() {
        return printComplete;
    }

    public void setPrintComplete(boolean printComplete) {
        this.printComplete = printComplete;
    }
}

class SentenceProcessor implements Runnable {
    private SharedData sharedData;

    public SentenceProcessor(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    @Override
    public void run() {
        synchronized (sharedData) {
            try {
                // Perform sentence reading
                System.out.println("Thread 1: Enter a sentence:");
                sharedData.setSentence("The quick brown fox jumps over the lazy dog");  // replace with user input

                // Notify other threads that reading is complete
                sharedData.notifyAll();

                // Wait for Thread 2 to complete
                while (!sharedData.isPrintComplete()) {
                    sharedData.wait();
                }

                // Perform sentence modification
                String modifiedSentence = removeRepeatedWords(sharedData.getSentence());
                System.out.println("Thread 3: Sentence without repeated words: " + modifiedSentence);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private String removeRepeatedWords(String sentence) {
        // Implementation to remove repeated words (without using HashSet)
        // Replace this with your logic
        StringBuilder result = new StringBuilder();
        String[] words = sentence.split("\\s+");
        for (String word : words) {
            if (!result.toString().contains(word)) {
                result.append(word).append(" ");
            }
        }
        return result.toString().trim();
    }
}

class RepeatedWordsPrinter implements Runnable {
    private SharedData sharedData;

    public RepeatedWordsPrinter(SharedData sharedData) {
        this.sharedData = sharedData;
    }

    @Override
    public void run() {
        synchronized (sharedData) {
            try {
                // Wait for Thread 1 to complete reading
                while (sharedData.getSentence() == null) {
                    sharedData.wait();
                }

                // Perform printing of repeated words
                String repeatedWords = findRepeatedWords(sharedData.getSentence());
                System.out.println("Thread 2: Repeated words in the sentence: " + repeatedWords);
                sharedData.setPrintComplete(true);

                // Notify Thread 1 that printing is complete
                sharedData.notifyAll();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private String findRepeatedWords(String sentence) {
        // Implementation to find and print repeated words
        // Replace this with your logic
        StringBuilder result = new StringBuilder();
        String[] words = sentence.split("\\s+");
        for (String word : words) {
            if (sentence.indexOf(word) != sentence.lastIndexOf(word)) {
                result.append(word).append(" ");
            }
        }
        return result.toString().trim();
    }
}
 class Q5 {
    public static void main(String[] args) {
        SharedData sharedData = new SharedData();

        Thread thread1 = new Thread(new SentenceProcessor(sharedData));
        Thread thread2 = new Thread(new RepeatedWordsPrinter(sharedData));
        Thread thread3 = new Thread(new SentenceProcessor(sharedData));

        thread1.start();
        thread2.start();

        try {
            thread2.join(); // Ensure thread2 completes before starting thread3
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        thread3.start();
    }
}
