class Base {
    final private int x;
    final private int y;

    Base(int n, int p) {
        x = n;
        y = p;
        System.out.println("constructing base class");
    }

    public void showxy() {
        System.out.println(x + " " + y);
    }
}

class Derived extends Base {
    final private int i;
    final private int j;

    Derived(int n, int m, int p) {
        super(n, p);
        i = n;
        j = m;
        System.out.println("constructing derived class");
    }

    public void showij() {
        System.out.println(i + " " + j);
    }
}


public class inheritance_constructorDemo {
    public static void main(String[] args) {

        Derived ob = new Derived(10, 20, 30);

        ob.showxy();
        ob.showij();
    }
}
