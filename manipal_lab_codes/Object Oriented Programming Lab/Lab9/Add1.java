class Add1{
        static <V> void print( V[] y) {
                for(V  x: y){//int i=0; i < y.length; i++){
                        System.out.println(x);
                }
        }
        public static void main(String args[]) {
                Integer nums[] = { 1, 2, 3, 4, 5 };
                String strs[] = { "one", "two", "three", "four", "five" };
                print(nums);
                print(strs);
        }
}
