public class Department {
    static Department[] departments = new Department[10];

    private int departmentId;
    private int numemployee;
    private Employee[] employees;

    public Department() {
        departmentId = 0;
        numemployee = 0;
        employees = new Employee[50];
    }

    public Department(int departmentId) {
        this.departmentId = departmentId;
        this.numemployee = 0;
        employees = new Employee[50];
    }

    public int getDeptid() {
        return departmentId;
    }

    public void departmentInfo() {
        System.out.println("Department id: " + departmentId);
        if(numemployee > 0) {
            for(int i = 0; i < numemployee; i++) {
                System.out.println(employees[i].getemployeeId() + " " + employees[i].getemployeeName() + " " + employees[i].getattendance());

            }
        }else {
            System.out.println("No employees registered");
        }
    }

    public boolean addemployee(Employee employee) {
        if(numemployee > 50) {
            System.out.println("beshi");
            return false;
        }

        employees[numemployee] = employee;
        numemployee++;
        return true;
    }

    public Employee findemployee(int id) {
        for(Employee employee : employees) {
            if(employee.getemployeeId() == id) {
                return employee;
            }
        }
        return null;
    }

    
}
