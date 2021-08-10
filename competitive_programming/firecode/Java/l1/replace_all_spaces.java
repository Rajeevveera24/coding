// Write a method to replace all spaces in a string with a given replacement string.
// replace("This is a test","/") --> "This/is/a/test"
// Note: Avoid using the in-built String.replaceAll() method.


// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public static String replace(String a, String b) {
    if(a == null){
        return null;
    }
    if (b == null){
        return a;
    }
    char[] a1 = a.toCharArray();
    char[] b1 = b.toCharArray();
    
    StringBuilder builder = new StringBuilder();
    
    for(char chr:a1){
        if(chr == ' '){
            for(char chr1:b1){
                builder.append(chr1);
            }
        }
        else{
            builder.append(chr);
        }
    }
    return builder.toString();
}