#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string studentID;
    string studentName;
    string major;

public:
    Student(string id, string name, string studentMajor)
        : studentID(id), studentName(name), major(studentMajor) {}

    void updateStudentInfo(string name, string studentMajor) {
        studentName = name;
        major = studentMajor;
    }

    void viewStudentDetails() {
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Major: " << major << endl;
    }

    string getStudentID() {
        return studentID;
    }

    string getStudentMajor() {
        return major;
    }
};

class Course {
private:
    string courseID;
    string courseTitle;
    string instructor;

public:
    Course(string id, string title, string courseInstructor)
        : courseID(id), courseTitle(title), instructor(courseInstructor) {}

    void viewCourseDetails() {
        cout << "Course ID: " << courseID << endl;
        cout << "Course Title: " << courseTitle << endl;
        cout << "Instructor: " << instructor << endl;
    }

    string getCourseID() {
        return courseID;
    }
};

class Enrollment {
private:
    string enrollmentID;
    string studentID;
    string courseID;
    string semester;

public:
    Enrollment(string id, string studentId, string courseId, string sem)
        : enrollmentID(id), studentID(studentId), courseID(courseId), semester(sem) {}

    void viewEnrollmentDetails() {
        cout << "Enrollment ID: " << enrollmentID << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Course ID: " << courseID << endl;
        cout << "Semester: " << semester << endl;
    }

    string getStudentID() {
        return studentID;
    }

    string getCourseID() {
        return courseID;
    }
};

int main() {
    vector<Student> students;
    vector<Course> courses;
    vector<Enrollment> enrollments;

    // Create some students, courses, and enrollments
    students.push_back(Student("412907", "Muhammad Ishaq", "Computer Science"));
    students.push_back(Student("404818", "Muhammad ashar", "Engineering"));

    courses.push_back(Course("234", "Computer Programming", "ali"));
    courses.push_back(Course("3256", "Mathematics", "reyan"));

    enrollments.push_back(Enrollment("E001", "S001", "C001", "Fall 2023"));
    enrollments.push_back(Enrollment("32402", "412908", "4301", "Fall 2023"));
    enrollments.push_back(Enrollment("E00d3", "S32002", "UAdf02", "Fall 2023"));

    // Admin can update student information
    students[0].updateStudentInfo("Karamat", "Computer Engineering");

    // Admin can view student details
    cout << "Student Details:\n";
    for (Student& student : students) {
        student.viewStudentDetails();
        cout << "-----------------------\n";
    }

    // Admin can view course details
    cout << "Course Details:\n";
    for (Course& course : courses) {
        course.viewCourseDetails();
        cout << "-----------------------\n";
    }

    // Admin can view enrollment details based on student or course ID
    string searchID = "412908";  // Example student ID to search for
    cout << "Enrollments for Student ID " << searchID << ":\n";
    for (Enrollment& enrollment : enrollments) {
        if (enrollment.getStudentID() == searchID) {
            enrollment.viewEnrollmentDetails();
            cout << "-----------------------\n";
        }
    }

    return 0;
}
