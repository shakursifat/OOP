public class ArrayDemo {
    public static void main(String[] args) {
        boolean a[] = new boolean[10];
        a[3] = true;
        /*for (int i = 0; i < a.length; i++) {
            a[i] = i;
        }*/
        for (int i = -1; i < a.length+1; i++) {
            try {
                System.out.println(a[i]);
            }catch(Exception e) {
                System.out.println(e);
            }
            //System.out.println(a[i]);
        }
    }
}