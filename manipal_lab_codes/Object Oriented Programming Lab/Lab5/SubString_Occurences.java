import java.util.Scanner;
class SubString_Occurences{
     public static void main(String[] args) {
          String string = new String();
          String sub_string  = new String();
          Scanner scan = new Scanner(System.in);
          System.out.println("Enter the string and the sub string");
          string = scan.nextLine();
          sub_string  =scan.nextLine();
          int index,count=0;
          do{
               index = string.indexOf(sub_string,0);
               if(index!=-1){
                    count++;
                    string = string.substring(index+sub_string.length(),string.length());
               }
          }while(index!=-1 && string.length()>0);
          System.out.println("The number of occurences of substring are "+count);
     }
}
