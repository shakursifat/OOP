//
// An implementation of WorkItem interface.
// Students have no action item in this class.
//

import java.util.Random;

public class STAWorkItem implements WorkItem {
    private int id;
    static Random rng = new Random(0);
    static String execThread = "JobRunner";

    STAWorkItem(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }
    public boolean work() {
        if (Thread.currentThread().getName().compareTo(execThread) != 0) {
            System.out.println("Error!!! work attempted from " + Thread.currentThread().getName());
            return false;
        }

        try {
            Thread.sleep(rng.nextInt(50)+1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return true;
    }
}
