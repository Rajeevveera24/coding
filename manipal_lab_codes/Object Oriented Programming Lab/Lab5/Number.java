import java.util.Scanner;
class Number{
     public static void main(String[] args) {
          Scanner scan = new Scanner(System.in);
          String number,sub_num1,sub_num2 = new String();
          System.out.println("Enter the number");
          //scan.nextLine();
          number = scan.nextLine();
          sub_num2 =  number.substring(number.length()-3,number.length());
          number = number.substring(0,number.length()-3);
          while(number.length()>=3){
               sub_num1 = number.substring(number.length()-3,number.length());
               sub_num2 = sub_num1+","+sub_num2;
               number = number.substring(0,number.length()-3);
          }
          if(number.length()>0){
               sub_num1 = number.substring(0,number.length());
               sub_num2 = sub_num1+","+sub_num2;
          }
          number = sub_num2;
          System.out.println(number);
     }
}
