interface MyInterface {
    void print(String msg);
}

class MyClass1 implements MyInterface {
    public void print(String msg) {
        System.out.println(msg + ":" + msg.length());
    }
    public void print(int x) {
        System.out.println("this is myclass 1 : " + x);
    }
}

class MyClass2 implements MyInterface {
    public void print(String msg) {
        System.out.println(msg.length() + ":" + msg);
    }

    public void print(int x) {
        System.out.println("this is myclass 2 : " + x);
    }
}

public class InterfaceApplyTest {
    public static void main(String[] args) {
        MyClass1 mc1 = new MyClass1();
        MyClass2 mc2 = new MyClass2();
        MyInterface mi; // create an interface reference variable
        mi = mc1;
        mi.print("Hello World");
        mc1.print(3);
        mi = mc2;
        mi.print("Hello World");
        mc2.print(3);
    }
}
