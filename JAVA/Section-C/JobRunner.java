import java.util.LinkedList;
import java.util.Queue;

//
// Maintains a queue of workitems. Executes the workitems
// one by one in single thread. Such pattern is useful when
// the target of the work can only handle single threaded actions
// For example, most ot the UI platforms expect notifications to
// come through the UI thread.
//
// Follow the TODO comments and write your code.
// Do not remove existing codes.
//

public class JobRunner extends Thread {
    // Queue of work items.
    private Queue<WorkItem> queue = new LinkedList<>();
    
    // Whether termination of the JobRunner has been signalled
    private boolean fQuit = false;

    JobRunner() {
        super("JobRunner");
    }

    public void enqueue(WorkItem work) {
        //
        // TODO: Use queue.add method to enqueue the work item
        // The underlying queue is not threadsafe. So we need to
        // take appropriate measure(s).
        //
        synchronized (queue) {
            queue.add(work);
        }
    }

    public void signalShutDown() {
        //
        // TODO: Record that shutdown has been signalled. We need to
        // take appropriate measure(s) to make it threadsafe.       
        // 
        synchronized (this) {
            fQuit = true;
        }
    }

    public void run() {
        //
        // Execution of the Job Queue thread begins
        //
        while (true) {
            boolean fQuit = false;
            synchronized(this) {
               fQuit = this.fQuit;
            }

            // TODO: If there is work to do, we perform it 
            // Otherwise, we go to sleep for a second and try again. However, 
             // if shutdown has been signalled, then we break the infinite loop

            // To extract a workitem from queue, use queue.poll(). If there is
		    // nothing in the queue, it will return null. Else, it will return the
		    // reference to a work item to be executed.

			//
			// If the work was successfully performed, we write a log statement.
			//

            WorkItem workitem = null;
            synchronized (queue) {
                workitem = queue.poll();
            }

            if (workitem != null) {
                boolean success = workitem.work();
                if (success) {
                    System.out.println(Thread.currentThread().getName() + " >> Finished work item: " + workitem.getId());
                }
            } else {
                if (fQuit) {
                    break;
                }
                try {
                    Thread.sleep(1000); // Wait for more work
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
			//System.out.println("" + Thread.currentThread().getName() + ">> Finished work item: " + workitem.getId());		
        }    
    }
}
