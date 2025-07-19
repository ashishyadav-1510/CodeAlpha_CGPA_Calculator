#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

struct Course {
    string subjectCode;
    string subjectName;
    int marks;
    int credit;
    float gradePoint;
    string grade;
};

string getGrade(int marks) {
    if (marks >= 90) return "A+";
    else if (marks >= 80) return "A";
    else if (marks >= 70) return "B+";
    else if (marks >= 60) return "B";
    else if (marks >= 50) return "C";
    else if (marks >= 40) return "D";
    else return "F";
}

float getGradePoint(int marks, int credit) {
    return (marks * credit) / 10.0f;
}

void saveToFile(const string &filename, const string &content) {
    ofstream fout(filename);
    if (fout.is_open()) {
        fout << content;
        fout.close();
        cout << "Saved to '" << filename << "'\n";
    }
}

void appendToFinalReport(const string &content) {
    ofstream fout("final_report.txt", ios::app);
    fout << content;
    fout.close();
}

bool isValidName(const string& name) {
    return regex_match(name, regex("^[A-Z][a-z]*( [A-Z][a-z]*)*$"));
}

bool isValidID(const string& id) {
    return regex_match(id, regex("^[A-Za-z0-9]+$"));
}

bool isValidSubjectCode(const string& code) {
    return regex_match(code, regex("^[A-Z][A-Za-z0-9]*-[0-9]+$"));
}

bool isValidSubjectName(const string& name) {
    return regex_match(name, regex("^[A-Z][a-z]*$"));
}

string toTitleCase(const string& name) {
    stringstream ss(name);
    string word, result;
    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]);
            for (size_t i = 1; i < word.size(); ++i) {
                word[i] = tolower(word[i]);
            }
            result += word + " ";
        }
    }
    if (!result.empty()) result.pop_back(); // remove trailing space
    return result;
}

int main() {
    string studentName, studentID;
    int semesters;
    float totalCumulativePoints = 0;
    int totalCumulativeCredits = 0;

    ofstream clearFile("final_report.txt");
    clearFile << "========== FINAL CGPA REPORT ==========\n";
    clearFile.close();

    cout << "===== CGPA CALCULATOR =====\n";

    while (true) {
        cout << "Enter Student Name : ";
        getline(cin, studentName);
        studentName = toTitleCase(studentName);
        if (isValidName(studentName)) break;
        cout << "Invalid name or format!! Try again.\nFirst Letter Capital Rest are Small\n";
    }

    while (true) {
        cout << "Enter Student ID : ";
        getline(cin, studentID);
        if (isValidID(studentID)) break;
        cout << "Invalid ID!! Try again.\nOnly alphanumeric, no special chars";
    }

    while (true) {
    cout << "Enter number of semesters: ";
    cin >> semesters;

    if (cin.fail() || semesters < 1 || semesters > 20) {
        cout << "Invalid input. Please enter an integer between 1 and 20.\n";
        cin.clear();              // Clear error flags
        cin.ignore(1000, '\n');   // Ignore invalid input
    } else {
        break;
    }
}

    for (int sem = 1; sem <= semesters; ++sem) {
        int numCourses;
        vector<Course> courses;
        float totalGradePoints = 0;
        int totalCredits = 0;
        string report;

        cout << "\n*** Semester " << sem << " ***\n";
        while (true) {
            cout << "Enter number of subjects: ";
            cin >> numCourses;

            if (cin.fail() || numCourses < 1 || numCourses > 20) {
                cout << "Invalid input. Please enter an integer between 1 and 20.\n";
                cin.clear();              // Clear input error
                cin.ignore(1000, '\n');   // Discard bad input
            } else {
                break;
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            Course course;

            while (true) {
                cout << "Subject " << i + 1 << " Name : ";
                cin>>ws;
                getline(cin, course.subjectName);
                if (isValidSubjectName(course.subjectName)) break;
                cout << "Invalid name. Try again.\n First Letter Capital rest are small( e.g. :- Subject)";
            }

            while (true) {
                cout << "Subject Code " << i + 1 << " : ";
                getline(cin, course.subjectCode);
                if (isValidSubjectCode(course.subjectCode)) break;
                cout << "Invalid format. Try again.\n(e.g. :- Subject-101)";
            }

            while (true) {
                cout << "Enter Marks : ";
                cin >> course.marks;
                if (course.marks >= 0 && course.marks <= 100) break;
                cout << "Must be 0 to 100. Try again.\n";
            }

            while (true) {
                cout << "Credits (0-10): ";
                cin >> course.credit;
                if (course.credit >= 0 && course.credit <= 10) break;
                cout << "Must be 0 to 10. Try again.\n";
            }

            course.grade = getGrade(course.marks);
            course.gradePoint = getGradePoint(course.marks, course.credit);

            courses.push_back(course);
            totalCredits += course.credit;
            totalGradePoints += course.gradePoint;
        }

        float gpa = totalGradePoints / totalCredits;
        totalCumulativePoints += totalGradePoints;
        totalCumulativeCredits += totalCredits;
        float cgpa = totalCumulativePoints / totalCumulativeCredits;

        ostringstream oss;
        oss << fixed << setprecision(2); // set rounding to 2 decimal places
        // Report
        report += "========= Semester " + to_string(sem) + " Report =========\n";
        report += "Student Name : " + studentName + "\n";
        report += "Student ID   : " + studentID + "\n";
        report += "-------------------------------------------------------------\n";
        report += "Subject Code     Subject Name     Marks   Credits   Grade   Grade Points\n";

        for (const auto& course : courses) {
            oss.str(""); // clear previous contents
            oss << fixed << setprecision(2) << course.gradePoint;

            report += course.subjectCode + string(18 - course.subjectCode.length(), ' ');
            report += course.subjectName + string(18 - course.subjectName.length(), ' ');
            report += to_string(course.marks) + string(8 - to_string(course.marks).length(), ' ');
            report += to_string(course.credit) + string(9 - to_string(course.credit).length(), ' ');
            report += course.grade + string(8 - course.grade.length(), ' ');
            report += oss.str() + "\n";
        }

        oss.str(""); oss << fixed << setprecision(2) << gpa;
        report += "---------------------------------------------------------------------\n";
        report += "Semester GPA: " + oss.str() + "\n";

        oss.str(""); oss << fixed << setprecision(2) << cgpa;
        report += "Cumulative CGPA: " + oss.str() + "\n";
        report += "=====================================================================\n\n";

        cout << report;
        string semFile = "semester" + to_string(sem) + ".txt";
        saveToFile(semFile, report);
        appendToFinalReport(report);
    }

    cout << "\nAll semester reports saved.\n";
    cout << "Final combined report: final_report.txt\n";

    return 0;
}