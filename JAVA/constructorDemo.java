class Myclass {
    private int a = 0;
    Myclass() {
        System.out.println("No argument constructor");
    }
    Myclass(int newA) {
        a = newA;
        System.out.println("constructor with argument");
    }

    public void show() {
        System.out.println(a);
    }
}


public class constructorDemo {
    public static void main(String[] args) {
        Myclass ob1 = new Myclass();
        Myclass ob2 = new Myclass(10);

        ob1.show();
        ob2.show();
    }
}
