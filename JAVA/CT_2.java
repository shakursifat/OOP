abstract class AB {
    int a, b;
    AB() {
        System.out.println("ab constructing");
    }
    AB(int a , int b) {
        this.a = a;
        this.b = b;
    }

    AB(int x) {
        this.a = this.b = x;
    }

    abstract void f1();

    void f2() {
        System.out.println("In f2");
    }
}

class C extends AB {
    int c;
    C(){
        super(5, 10);
        System.out.println("c constructing");
    }
    C(int a, int b) {
        super(a, b);
    }
    @Override
    void f2() {
        System.out.println("In f2 of C");
    }

    @Override
    void f1(){

    }
}

public class CT_2{
    public static void main(String[] args) {
        C c1 = new C(10, 20);
        C c2 = new C();
        AB x = c1;
        //C c3 = x;
    }
}
