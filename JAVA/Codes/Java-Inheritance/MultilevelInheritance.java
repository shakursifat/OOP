class X {
    int a;

    X() {
        System.out.println("Inside X's constructor");
    }

    void show() {
        System.out.println("in x :" + a);
    }
}

class Y extends X {
    int a;

    Y() {
        System.out.println("Inside Y's constructor");
    }

    void show() {
        super.show();
        System.out.println("in y :" + a);
    }
}

class Z extends Y {
    int a;

    Z() {
        System.out.println("Inside Z's constructor");
    }

    void show() {
        super.show();
        System.out.println("in z :" + a);
    }
}

public class MultilevelInheritance {
    public static void main(String[] args) {
        Z z = new Z();
        z.a = 10;
        ((Y)z).a = 20;
        ((X)z).a = 30;

        z.show();
    }
}
