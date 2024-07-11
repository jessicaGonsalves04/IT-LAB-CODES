public class AutoboxingUnboxingExample {
    public static void main(String[] args) {
        // Autoboxing: converting a primitive data type to an object
        int i = 10;
        System.out.println("Before Autoboxing - i: " + i);
        Integer iObj = i; // Autoboxing
        System.out.println("After Autoboxing - iObj: " + iObj);
        
        // Unboxing: converting an object back to a primitive data type
        int j = iObj.intValue(); // Unboxing
        System.out.println("After Unboxing - j: " + j);
        
        // Autoboxing and unboxing of other primitive data types
        byte b = 10;
        System.out.println("Before Autoboxing - b: " + b);
        Byte bObj = b; // Autoboxing
        System.out.println("After Autoboxing - bObj: " + bObj);
        byte b1 = bObj.byteValue(); // Unboxing
        System.out.println("After Unboxing - b1: " + b1);
        
        short s = 10;
        System.out.println("Before Autoboxing - s: " + s);
        Short sObj = s; // Autoboxing
        System.out.println("After Autoboxing - sObj: " + sObj);
        short s1 = sObj.shortValue(); // Unboxing
        System.out.println("After Unboxing - s1: " + s1);
        
        long l = 10L;
        System.out.println("Before Autoboxing - l: " + l);
        Long lObj = l; // Autoboxing
        System.out.println("After Autoboxing - lObj: " + lObj);
        long l1 = lObj.longValue(); // Unboxing
        System.out.println("After Unboxing - l1: " + l1);
        
        float f = 10.5f;
        System.out.println("Before Autoboxing - f: " + f);
        Float fObj = f; // Autoboxing
        System.out.println("After Autoboxing - fObj: " + fObj);
        float f1 = fObj.floatValue(); // Unboxing
        System.out.println("After Unboxing - f1: " + f1);
        
        double d = 10.5;
        System.out.println("Before Autoboxing - d: " + d);
        Double dObj = d; // Autoboxing
        System.out.println("After Autoboxing - dObj: " + dObj);
        double d1 = dObj.doubleValue(); // Unboxing
        System.out.println("After Unboxing - d1: " + d1);
        
        char c = 'a';
        System.out.println("Before Autoboxing - c: " + c);
        Character cObj = c; // Autoboxing
        System.out.println("After Autoboxing - cObj: " + cObj);
        char c1 = cObj.charValue(); // Unboxing
        System.out.println("After Unboxing - c1: " + c1);
        
        boolean bool = true;
        System.out.println("Before Autoboxing - bool: " + bool);
        Boolean boolObj = bool; // Autoboxing
        System.out.println("After Autoboxing - boolObj: " + boolObj);
        boolean bool1 = boolObj.booleanValue(); // Unboxing
        System.out.println("After Unboxing - bool1: " + bool1);
    }
}
