class Figure {
    public double dim1, dim2;
    Figure(double dim1, double dim2) {
        this.dim1 = dim1;
        this.dim2 = dim2;
    }
    double area() {
        System.out.println("dont have area");
        return 0;
    }

    void show () {
        System.out.println("abstract");
        System.out.println("figure dim: " + dim1 + " " + dim2);
    }
}

class Rectangle extends Figure {
    Rectangle(double a, double b) {
        super(a, b);
    }
    double area() {
        return dim1*dim2;
    }
    void show() {
        System.out.println("Rectangle area: " + area());
        System.out.println("rectangle dim: " + dim1 + " " + dim2);
    }
}

class Triangle extends Figure {
    Triangle (double a, double b) {
        super(a, b);
    }

    double area() {
        return 0.5*dim1*dim2;
    }

    void show() {
        System.out.println("Triangle Area: " + area());
        System.out.println("triangle dim: " + dim1 + " " + dim2);
    }
}


public class method_overridingDemo {
    public static void main(String[] args) {
        Figure fig = new Figure(3, 2);
        Figure r = new Rectangle(4, 5);
        Figure t = new Triangle(4, 3);
        Figure figref;

        figref = r;
        figref.show();
        System.out.println(figref.dim1 + " " + figref.dim2);
        figref = t;
        figref.show();
        figref = fig;
        figref.show();
        System.out.println(figref.dim1 + " " + figref.dim2);
    }
}
