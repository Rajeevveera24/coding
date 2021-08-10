// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public static String reverseString(String str){
    String inputString = str;
    String outputString = null;
    
    if(inputString == null){
        return outputString;
    }
    
    StringBuilder sb = new StringBuilder();
    
    int l = inputString.length();
    
    for(int i = l-1; i >= 0; i--){
        sb.append(inputString.charAt(i));
    }
    outputString = sb.toString();
    return outputString;
}