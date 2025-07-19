#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class Course{
    string name;
    float creditHour;
public:
    Course() {
        name = "";
        creditHour = 0;
    }

    Course(string name, float creditHour) {
        this->name = name;
        this->creditHour = creditHour;
    }

    ~Course() {

    }

    string getName() {
        return name;
    }

    float getCreditHour() {
        return creditHour;
    }

    void setName(string name) {
        this->name = name;
    }

    void setCreditHour(float creditHour) {
        this->creditHour = creditHour;
    }

    void display() {
        cout << "Course Name: " << name << ", Credit Hour: " << creditHour;
    }
};


class Student {
    string name;
    int id;
    Course* courses;
    int totalCourses;
    int maxCourses;
    float* gradePoints;

public:

    Student() {
        name = "";
        id = 0;
        courses = new Course[0];
        totalCourses = 0;
        maxCourses = 0;
        gradePoints = new float[0];
    }

    Student(string name, int id, int maxCourses) {
        this->name = name;
        this->id = id;
        courses = new Course[maxCourses];
        totalCourses = 0;
        this->maxCourses = maxCourses;
        gradePoints = new float[maxCourses];
    }

    Student(const Student& obj) {
        this->name = obj.name;
        this->id = obj.id;
        this->courses = new Course[obj.maxCourses];
        this->gradePoints = new float[obj.maxCourses];
        this->totalCourses = obj.totalCourses;
        this->maxCourses = obj.maxCourses;

        for(int i = 0; i < obj.totalCourses; i++) {
            this->courses[i] = obj.courses[i];
            this->gradePoints[i] = obj.gradePoints[i];
        }
    }

    ~Student() {
        delete[] courses;
        delete[] gradePoints;
    }

    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setInfo(string name, int id) {
        this->name = name;
        this->id = id;
    }

    void addCourse(Course c) {
        if(totalCourses < maxCourses) {
            courses[totalCourses] = c;
            gradePoints[totalCourses] = 0;
            totalCourses++;
        }else {
            cout << "Cannot add more courses to " << name << endl;
            cout << "==================================" << endl;
        }
    }

    void addCourse(Course course, float gradePoint) {
        if(totalCourses < maxCourses) {
            courses[totalCourses] = course;
            gradePoints[totalCourses] = gradePoint;
            totalCourses++;
        }else {
            cout << "Cannot add more courses to " << name << endl;
            cout << "==================================" << endl;            
        }
    }

    void setGradePoint(Course c, float gradePoint) {
        if(gradePoint < 0 || gradePoint > 4) {
            cout << "invalid gradepoint" << endl;
        }else{
            for(int i = 0; i < totalCourses; i++) {
                if(courses[i].getName() == c.getName()) {
                    gradePoints[i] = gradePoint;
                }
            }  
        }
    }
    
    void setGradePoint(float* gradePoints, int n) {
        if(n <= totalCourses && n > 0) {
            for(int i = 0; i < n; i++) {
                this->gradePoints[i] = gradePoints[i];
            }
        }else {
            cout << "the number n is invalid" << endl;
        }
    }

    string getName() {
        return name;
    }

    float getCGPA() {
        float cgpa = 0;
        float totalcredits = 0;

        for(int i = 0; i < totalCourses; i++) {
            cgpa += (courses[i].getCreditHour() * gradePoints[i]);
            totalcredits += courses[i].getCreditHour();
        }

        if(totalcredits != 0) cgpa = cgpa / totalcredits;
        return cgpa;
    }

    float getGradePoint(Course c) {
        for(int i = 0; i < totalCourses; i++) {
            if(courses[i].getName() == c.getName()) {
                return gradePoints[i];
            }
        }
        return 0;
    }

    int getTotalCourses() {
        return totalCourses;
    }

    float getTotalCreditHours() {
        float totalcredithours = 0;
        for(int i = 0; i < totalCourses; i++) {
            if(gradePoints[i] >= 2) {
                totalcredithours += courses[i].getCreditHour();
            }
        }
        return totalcredithours;
    }

    Course getMostFavoriteCourse() {
        float highest_grade = 0;
        int indx = -1;
        for(int i = 0; i < totalCourses; i++) {
            if(gradePoints[i] > highest_grade) {
                highest_grade = gradePoints[i];
                indx = i;
            }
        }
        if(indx != -1) {
            return courses[indx];
        }else {
            return Course();
        }
    }

    Course getLeastFavoriteCourse() {
        float lowest_grade = 4;
        int indx = -1;
        for(int i = 0; i < totalCourses; i++) {
            if(gradePoints[i] < lowest_grade) {
                lowest_grade = gradePoints[i];
                indx = i;
            }
        }
        if(indx != -1) {
            return courses[indx];
        }else {
            return Course();
        }
    }

    Course* getFailedCourses(int &count) {
        Course* failedcourses = new Course[totalCourses];
        count = 0;
        for(int i = 0; i < totalCourses; i++) {
            if(gradePoints[i] < 2) {
                failedcourses[count] = courses[i];
                count++;
            }
        }
        return failedcourses;
    }

    void display() {
        cout << "Student Name: " << name << ", ID: " << id << endl;
        for(int i = 0; i < totalCourses; i++) {
            courses[i].display();
            cout << ", gradePoint: " << gradePoints[i] << endl;
        }
        cout << "CGPA: " << getCGPA() << endl;
        cout << "Total Credit Hours Earned: " << getTotalCreditHours() << endl;
        cout << "Most Favorite Course: " << getMostFavoriteCourse().getName() << endl;
        cout << "Least Favorite Course: " << getLeastFavoriteCourse().getName() << endl;

        cout << "==================================" << endl;
        cout << "==================================" << endl;
    }

};

Student* students[20];
int totalStudents = 0;

Student getTopper() {
    float highest_cg = 0;
    int indx = -1;
    for(int i = 0; i < totalStudents; i++) {
        if(students[i]->getCGPA() > highest_cg) {
            highest_cg = students[i]->getCGPA();
            indx = i;
        }
    }
    if(indx != -1) {
        return *students[indx];
    }else {
        return Student();
    }
}

Student getTopper(Course c) {
    float highest_cg = 0;
    int indx = -1;
    for(int i = 0; i < totalStudents; i++) {
        if(students[i]->getGradePoint(c) > highest_cg) {
            highest_cg = students[i]->getGradePoint(c);
            indx = i;
        }
    }
    if(indx != -1){
        return *students[indx];
    }else {
        return Student();
    }
}

int main()
{   //generate courses
    const int COURSE_COUNT = 6;
    Course courses[COURSE_COUNT] = {
        Course("CSE107", 3),
        Course("CSE105", 3),
        Course("CSE108", 1.5),
        Course("CSE106", 1.5),
        Course("EEE164", 0.75),
        Course("ME174", 0.75),
    };
    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25};
    //generate students
    Student s1 = Student("Sheldon", 1, 5);
    students[totalStudents++] = &s1;
    // add courses to s1
    s1.addCourse(courses[0]);
    s1.addCourse(courses[1]);
    s1.addCourse(courses[2]);
    s1.addCourse(courses[3]);
    s1.addCourse(courses[4]);
    s1.addCourse(courses[5]);
    s1.setGradePoint(gradePoints, s1.getTotalCourses());
    s1.display();
    Student s2 = Student("Penny", 2, 5);
    students[totalStudents++] = &s2;
    s2.addCourse(courses[0]);
    s2.addCourse(courses[2]);
    s2.addCourse(courses[5]);
    s2.setGradePoint(gradePoints, s2.getTotalCourses());
    s2.setGradePoint(courses[0], 3.25);
    s2.display();
    Student s3 = s2;
    students[totalStudents++] = &s3;
    s3.setName("Leonard");
    s3.setId(3);
    s3.setGradePoint(gradePoints, s3.getTotalCourses());
    s3.addCourse(courses[1], 3.75);
    s3.display();
    Student s4 = s3;
    students[totalStudents++] = &s4;
    s4.setInfo("Howard", 4);
    s4.setGradePoint(gradePoints, s4.getTotalCourses());
    s4.addCourse(courses[3], 3.75);
    s4.display();
    Student s5 = s4;
    students[totalStudents++] = &s5;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(gradePoints, s5.getTotalCourses());
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();
    int failedCount;
    Course *failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i)
    {
        failedCourses[i].display();
        cout << endl;
    }
    delete[] failedCourses;
    cout << "==================================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < COURSE_COUNT; ++i)
    {
        Course c = courses[i];
        Student topperInCourse = getTopper(c);
        cout << "Topper in " << c.getName() << ": " << topperInCourse.getName() << endl;
        cout << "Topper in " << c.getName() << " gradePoint: " << topperInCourse.getGradePoint(c) << endl;
        cout << "==================================" << endl;
    }
    return 0;
}