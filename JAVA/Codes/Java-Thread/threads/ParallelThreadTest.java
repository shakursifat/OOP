class ThreadTest {
    public void f0() {
        for (int i = 1; i < 500; i++)
            System.out.println(Thread.currentThread().getName() + " " + i);
    }

    public synchronized void f1() {
        for (int i = 1; i < 1000; i++)
            System.out.println(Thread.currentThread().getName() + " " + i);
    }

    public synchronized void f2() {
        for (int i = 1; i < 1500; i++)
            System.out.println(Thread.currentThread().getName() + " " + i);
    }

    public synchronized static void fs1() {
        for (int i = 1; i < 2000; i++)
            System.out.println(Thread.currentThread().getName() + " " + i);
    }

    public synchronized static void fs2() {
        for (int i = 1; i < 2500; i++)
            System.out.println(Thread.currentThread().getName() + " " + i);
    }
}


public class ParallelThreadTest {
    public static void main(String[] args) {
        ThreadTest obj = new ThreadTest();
        Thread T1 = new Thread(()->obj.f1(), "T1");
        Thread T2 = new Thread(obj::f2, "T2");
        Thread T3 = new Thread(obj::f0, "T3");
        Thread T4 = new Thread(ThreadTest::fs1, "T4");
        Thread T5 = new Thread(ThreadTest::fs2, "T5");

        T1.start();
        T2.start();
        T3.start();
        T4.start();
        T5.start();
    }
}
