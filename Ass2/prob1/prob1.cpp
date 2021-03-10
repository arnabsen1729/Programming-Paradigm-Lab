#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    string department;
    int year;
};

// By default the input stream is std::cin
// but we can replace it with any filestram
Student ReadStudentData(istream& stream = cin) {
    Student stdPtr;
    stream >> stdPtr.name;
    stream >> stdPtr.age;
    stream >> stdPtr.department;
    stream >> stdPtr.year;
    return stdPtr;
}

// By default the output stream is std::cout
void PrintStudentData(Student data, ostream& stream = cout) {
    stream << "Name: " << data.name << "\n";
    stream << "Age: " << data.age << "\n";
    stream << "Dept: " << data.department << "\n";
    stream << "Year: " << data.year << "\n";
    stream << endl;
}

int main() {
    // using console

    cout << "USING STD I/O\n\n";

    cout << "Enter number of Students:";
    int students_count;
    cin >> students_count;

    Student* students_array = new Student[students_count];

    for (int index = 0; index < students_count; index++) {
        cout << "Enter name, age, department, year of " << index + 1;
        cout << " student : \n";
        students_array[index] = ReadStudentData(cin);
        cout << "\n";
    }

    for (int index = 0; index < students_count; index++) {
        cout << "Details of " << index + 1 << " student: \n";
        PrintStudentData(students_array[index]);
        cout << "-------------------------------------\n";
    }

    cout << "\n\nUSING FILE I/O\n\n";

    // using file

    int students_file_count = 2;

    // creating a instream file object
    ifstream fileIn;
    fileIn.open("inFile.txt");
    Student* students_array2 = new Student[students_file_count];
    for (int index = 0; index < students_file_count; index++) {
        students_array2[index] = ReadStudentData(fileIn);
    }

    // creating a outstream file object
    ofstream fileOut;
    fileOut.open("outFile.txt");

    for (int index = 0; index < students_file_count; index++) {
        PrintStudentData(students_array2[index], fileOut);
    }

    return 0;
}
