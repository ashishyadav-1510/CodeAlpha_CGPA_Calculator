# CGPA Calculator (C++)

This is a terminal-based CGPA (Cumulative Grade Point Average) calculator developed in C++. It allows users to input student details, subject-wise marks, and credits across multiple semesters, calculates GPA and CGPA, and generates formatted reports for each semester and a final report.

## Features

- Input validation for:
  - Student name (Title Case)
  - Alphanumeric Student ID
  - Subject names and codes
  - Marks (0–100)
  - Credits (0–10)
- Calculates:
  - Grade (A+, A, B+, ..., F)
  - Grade Points per subject
  - GPA per semester
  - Cumulative CGPA
- Saves each semester's report to a separate text file (e.g., `semester1.txt`)
- Generates a final combined report in `final_report.txt`

## Input Format

### Student Name

- Must be in Title Case (e.g., `John Doe`)

### Student ID

- Alphanumeric only (e.g., `CS2023B01`)

### Subject Name

- Single word with first letter capital (e.g., `Math`)

### Subject Code

- Format: `SUBJECT-101` (starts with letters, then a dash and number)

## Grade Scheme

| Marks Range | Grade | Grade Point Calculation |
| ----------- | ----- | ----------------------- |
| 90–100     | A+    | (marks * credit) / 10.0 |
| 80–89      | A     |                         |
| 70–79      | B+    |                         |
| 60–69      | B     |                         |
| 50–59      | C     |                         |
| 40–49      | D     |                         |
| 0–39       | F     |                         |

## How to Run

### Requirements

- C++ compiler (e.g., g++)

### Compilation

```bash
g++ -o cgpa_calculator cgpa_calculator.cpp
```
## Output
For each semester, a detailed report is saved to:
semester1.txt, semester2.txt, ..., etc.

A cumulative report for all semesters is saved to:
final_report.txt

### Example
===== CGPA CALCULATOR =====
Enter Student Name : John Doe
Enter Student ID   : CS2023B01
Enter number of semesters: 2

***Semester 1***
Enter number of subjects: 3
========= Semester 1 Report =========
Student Name : John Doe
Student ID   : CS2023B01
Subject Code     Subject Name     Marks   Credits   Grade   Grade Points
CS-101           Math             85      4         A       34.00
...
Semester GPA: 8.50
Cumulative CGPA: 8.50

## Screenshot
### Code:
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091016.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091047.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091116.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091138.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091152.png?raw=true)

### Output:
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091348.png?raw=true)
#### Text Files 
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091359.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091411.png?raw=true)
![image](https://github.com/ashishyadav-1510/CodeAlpha_CGPA_Calculator/blob/main/Screenshot/Screenshot%202025-07-19%20091421.png?raw=true)

## Video

[Video on YouTube](https://youtu.be/AseFuejdxcg)

## Explaination:

🔹 Header Inclusions
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <regex>
These are standard C++ libraries:
iostream: For input/output (e.g., cin, cout)
vector: For using dynamic arrays (to store courses)
iomanip: For formatting output (e.g., setting decimal precision)
fstream: For file operations (read/write files)
sstream: For string stream manipulations (like building a report)
regex: For input validation using regular expressions

🔹 Structure Definition
struct Course {
    string subjectCode;
    string subjectName;
    int marks;
    int credit;
    float gradePoint;
    string grade;
};
Defines a Course structure to hold information for each subject:
Code, name, marks, credit hours
Grade (e.g., A+, B) and grade point (numeric)

🔹 Grade & Grade Point Logic
string getGrade(int marks) {
    ...
}
Maps marks to a letter grade based on defined ranges.

float getGradePoint(int marks, int credit) {
    return (marks * credit) / 10.0f;
}
Calculates grade points by a simplified formula.

🔹 File Operations
void saveToFile(const string &filename, const string &content) { ... }
Writes a string content to a file with name filename.
void appendToFinalReport(const string &content) { ... }
Appends semester data to the final cumulative report (final_report.txt).

🔹 Input Validations (with Regex)
bool isValidName(const string& name) { ... }
bool isValidID(const string& id) { ... }
bool isValidSubjectCode(const string& code) { ... }
bool isValidSubjectName(const string& name) { ... }
Use regular expressions to ensure:
Names are in Title Case
ID is alphanumeric
Subject code follows ABC-123 format
Subject name is a single capitalized word

🔹 Helper Function
string toTitleCase(const string& name) {
    ...
}
Converts input like john doe to John Doe. Ensures each word starts with a capital letter.

🔹 Main Function Starts
int main() {
    ...
}
This is where the main logic runs.

Step 1: Declare Variables
string studentName, studentID;
int semesters;
float totalCumulativePoints = 0;
int totalCumulativeCredits = 0;
Track student details and cumulative CGPA.

Step 2: Initialize Final Report File
ofstream clearFile("final_report.txt");
clearFile << "========== FINAL CGPA REPORT ==========\n";
Creates/clears final_report.txt and adds a heading.

Step 3: Input Student Name
while (true) {
    ...
}
Asks for the name until it matches the required format (Title Case).

Step 4: Input Student ID
Similar logic to check for alphanumeric ID.

Step 5: Number of Semesters
while (true) {
    ...
}
Ensure the entered number of semesters is a valid integer between 1–20.

Step 6: Loop Over Each Semester
for (int sem = 1; sem <= semesters; ++sem) {
    ...
}
Run one loop per semester.

Step 6.1: Enter Number of Subjects
Again, ensure it's between 1 and 20.

Step 6.2: Course Entry Loop
for (int i = 0; i < numCourses; ++i) {
    ...
}
Collects all the info for each course:
Subject name
Subject code
Marks (0–100)
Credit (0–10)

Then:
Grade is calculated (getGrade)
Grade point is calculated (getGradePoint)
Totals for credits and points are updated

Step 7: GPA and CGPA Calculations
float gpa = totalGradePoints / totalCredits;
float cgpa = totalCumulativePoints / totalCumulativeCredits;
GPA = total grade points for the semester / total credits
CGPA = cumulative total of all semesters

Step 8: Build Report Using String Stream
ostringstream oss;
oss << fixed << setprecision(2);
Used to format numbers (like GPA, CGPA, Grade Points) to 2 decimal places.
Then the program creates a detailed report line-by-line:
Subject Code, Name, Marks, Credits, Grade, Grade Points
Semester GPA
Cumulative CGPA

Step 9: Output and Save
cout << report;
saveToFile(...);
appendToFinalReport(...);
Display the report on screen
Save to a file named semesterX.txt
Append to final cumulative report

End of Program
cout << "\nAll semester reports saved.\n";
return 0;
