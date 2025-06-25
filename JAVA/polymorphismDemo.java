import java.time.LocalDate;

class MyDate{
    private int day;
    private int month;
    private int year;

    MyDate(String str) {
        LocalDate date = LocalDate.parse(str);
        day = date.getDayOfMonth();
        month = date.getMonthValue();
        year = date.getYear();
    }

    MyDate(int newDay, int newMonth, int newYear) {
        day = newDay;
        month = newMonth;
        year = newYear;
    }

    public void showMyDate() {
        System.out.println(day+"/"+month+"/"+year);
    }
}



public class polymorphismDemo {
    public static void main(String[] args) {
        MyDate sDate = new MyDate("2024-05-12");
        MyDate iDate = new MyDate(23, 7, 2025);

        sDate.showMyDate();
        iDate.showMyDate();
    }
}
