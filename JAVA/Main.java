import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if(args.length != 1) {
            System.out.println("not valid");
            return;
        }

        int numdepts = Integer.parseInt(args[0]);
        int cnt_dept = 0;

        if(numdepts > 10) {
            System.out.println("beshi");
            numdepts = 10;
        }

        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < numdepts; i++) {
            Department dept = new Department(i);
            int maxemployee = sc.nextInt();
            sc.nextLine();
            if(maxemployee > 50) {
                System.out.println("beshi");
                maxemployee = 50;
            }

            for(int j = 0; j < maxemployee; j++) {
                System.out.print("employee id: ");
                int employeeid = sc.nextInt();
                sc.nextLine();
                System.out.print("employee name: ");
                String employeename = sc.nextLine();
                System.out.print("attendance:");
                int attendance = sc.nextInt();
                sc.nextLine();

                dept.addemployee(new Employee(employeeid, employeename, attendance));

                Department.departments[cnt_dept] = dept;
                cnt_dept++;
            }   
        }

        int choice;

        do {
            choice = sc.nextInt();
            switch(choice) {
                case 1 -> {
                    System.out.println("Mark attendance: ");
                    int deptid = sc.nextInt();
                    int employeeid = sc.nextInt();
                    handleattendance(deptid, employeeid, cnt_dept);
                }
                case 4 -> {
                    System.out.println("exiting");
                }
            }
        }while(choice != 4);

        sc.close();
    }

    public static void handleattendance(int deptid, int employeeid, int cnt_dept) {
        for(int i = 0; i < cnt_dept; i++) {
            if(Department.departments[i].getDeptid() == deptid) {
                Employee temp = Department.departments[i].findemployee(employeeid);
                temp.setattendance(temp.getattendance()+1);
            }
        }
    }
}
