public class Employee {
    private int employeeId;
    private String employeeName;
    private int attendance;

    public Employee() {
        employeeId = 0;
        employeeName = "";
        attendance = 0;
    }

    public Employee(int employeeId, String employeeName, int attendance) {
        this.employeeId = employeeId;
        this.employeeName = employeeName;
        this.attendance = attendance;
    }

    public int getemployeeId() {
        return employeeId;
    }

    public String getemployeeName() {
        return employeeName;
    }

    public int getattendance() {
        return attendance;
    }

    public void setattendance(int att) {
        attendance = att;
    }
}
