package p1;

public class Protection {
    int n = 1;
    private int nPrivate = 2;
    protected int nProtected = 3;
    public int nPublic = 4;
    static int call = 0;

    public Protection() {
        System.out.println("---Protection---");
        System.out.println(n);
        System.out.println(nPrivate);
        System.out.println(nProtected);
        System.out.println(nPublic);
        call++;
        System.out.println("I am call: " + call);
    }
}
