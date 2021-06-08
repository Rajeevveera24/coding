class Priority implements Runnable{
     int count;
     Thread thrd;
     static boolean stop = false;
     static String currentName;
     Priority(String Name){
          thrd = new Thread(this,Name);
          count = 1;
          currentName = Name;
     }
     public void run(){
          System.out.println(thrd.getName()+" starting.");
          do{
               count++;
               if(currentName.compareTo(thrd.getName())!=0){
                    currentName = thrd.getName();
                    System.out.println("In "+ currentName);
               }
          }while(stop == false && count<10000);
          stop = true;
          System.out.println("\n"+thrd.getName()+" terminating.");
     }
}
class Ex4{
     public static void main(String[] args) {
          Priority mt1 = new Priority("High Priority");
          Priority mt2 = new Priority("Low Priority");
          mt1.thrd.setPriority(Thread.NORM_PRIORITY+2);
          mt2.thrd.setPriority(Thread.NORM_PRIORITY-2);
          mt1.thrd.start();
          mt2.thrd.start();
          try{
               mt1.thrd.join();
               mt2.thrd.join();
          }
          catch(InterruptedException e){
               System.out.println("Main thread interrupted");
          }
          System.out.println("\nHigh Priority thread count: "+mt1.count);
          System.out.println("\nLow Priority thread count: "+mt2.count);
     }
}
