import java.lang.*;
class Q{
     int n;
     boolean Valueset = false;
     synchronized int get(){
          while(!Valueset){
               try{
                    wait();
                    Thread.sleep(1000);
               }
               catch(InterruptedException e){

               }
          }
          System.out.println("Got: "+n);
          Valueset = false;
          notify();
          return n;
     }
     synchronized void put(int n){
          while(Valueset){
               try{
                    wait();
                    Thread.sleep(1000);
               }
               catch(InterruptedException e){

               }
          }
          this.n=n;
          Valueset = true;
          System.out.println("Put: "+n);
          notify();
     }
}
class Producer implements Runnable{
     Q q;
     Thread t;
     Producer (Q q){
          this.q = q;
          t = new Thread(this,"Producer");
     }
     public void run(){
          int i=0;
          while(true){
               q.put(i++);
          }
     }
}
class Consumer implements Runnable{
     Q q;
     Thread t;
     Consumer (Q q){
          this.q = q;
          t = new Thread(this,"Consumer");
     }
     public void run(){
          while(true){
               q.get();
          }
     }
}
class Ex3{
     public static void main(String[] args) {
          Q q = new Q();
          Producer P = new Producer(q);
          Consumer C = new Consumer(q);
          P.t.start();
          C.t.start();
          System.out.println("Press Ctrl+C to stop the program");
     }
}
