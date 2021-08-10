// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public static boolean isStringPalindrome(String str){
    if(str == null){
        return true;
    }
    char c1, c2;
    int len = str.length();
    for(int i=0; i<len/2; i++){
        c1 = str.charAt(i);
        c2 = str.charAt(len-i-1);
        if(c1 != c2){
            return false;
        }
    }
    return true;
}