class Box {
    private double length;
    private double width;
    private double height;

    public Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    public Box(Box ob) {
        length = ob.length;
        width = ob.width;
        height = ob.height;
    }

    public double volume() {
        return length * width * height;
    }
}


public class constructor_Obj_cloneDemo {
    public static void main(String[] args) {
        Box myBox = new Box(5, 3, 2);
        Box myClone = new Box(myBox);

        System.out.println("Box volume: " + myBox.volume());
        System.out.println("Clone volume: " + myClone.volume());
    }
}
