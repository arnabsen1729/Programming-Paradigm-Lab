#include <iostream>
using namespace std;

class Student {
   private:
    char name[40];
    int age;
    char department[40];
    int year;

   public:
    Student() {
        name[0] = '\0';
        department[0] = '\0';
        age = 0;
        year = 0;
    }
    void ReadStudentData();
    void PrintStudentData();
    ~Student() {}
};

void Student::ReadStudentData() {
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(name, 40);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter department: ";
    cin.ignore();
    cin.getline(department, 40);
    cout << "Enter year: ";
    cin >> year;
}

void Student::PrintStudentData() {
    cout << "Name: " << name << "\n";
    cout << "Age : " << age << "\n";
    cout << "Dept: " << department << "\n";
    cout << "Year: " << year << "\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student stud_array[n];
    cout << "\nEnter details of each students: \n";
    for (int i = 0; i < n; i++) {
        cout << "-: DETAILS OF STUDENT " << i + 1 << ":-\n";
        stud_array[i].ReadStudentData();
        cout << "\n";
    }

    cout << "\n\nDetails of each students entered: \n";
    for (int i = 0; i < n; i++) {
        cout << "-: DETAILS OF STUDENT " << i + 1 << ":-\n";
        stud_array[i].PrintStudentData();
        cout << "\n\n";
    }
    return 0;
}
