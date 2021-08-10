// java.util.* and java.util.streams.* have been imported for this problem.
// You don't need any other imports.

public static int fib(int n) {
    if(n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
