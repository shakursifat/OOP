//package threads;

class NewThread3 implements Runnable {
    static int x = 1;
    String num;
    NewThread3() {
        num = Integer.toString(x);
        x++;
    }
    @Override
    public void run() {
        try {
            for (int i = 100; i > 0; i--) {
                System.out.println("Child Thread: " + num + " " + i);
                Thread.sleep(10);
            }
        } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread." + num);
    }
}

public class ImplementsThread2 {
    public static void main(String[] args) {
        /*Runnable r = new NewThread3();
        Thread t = new Thread(r);
        t.start();*/

        for(int i = 0; i < 10; i++) {
            Runnable r = new NewThread3();
            Thread t = new Thread(r);
            t.start();
        }
    }
}