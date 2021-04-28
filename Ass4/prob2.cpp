#include <string.h>

#include <iostream>
using namespace std;

/*
Heirarchial structure

          Person
        /        \
    Student     Staff
              /     \
            Prof   Clerk
*/

class Person {
   protected:
    char *name;
    int age;
    char gender;

   public:
    Person() {
        name = nullptr;
        age = 0;
        gender = '\0';
    }
    Person(char *name, int age, char gender) : age(age), gender(gender) {
        this->name = new char[strlen(name) + 1];
    }
    ~Person() {
        delete name;
        name = NULL;
    }
    void read();
    void display();
};

void Person::read() {
    char nameText[100];
    cout << "NAME: ";
    cin >> nameText;
    delete name;
    name = new char[strlen(nameText) + 1];
    strcpy(name, nameText);
    cout << "AGE: ";
    cin >> age;
    cout << "GENDER: ";
    cin >> gender;
}

void Person::display() {
    cout << "NAME: ";
    cout << name << "\n";
    cout << "AGE: ";
    cout << age << "\n";
    cout << "GENDER: ";
    cout << gender << "\n";
}

class Staff : protected Person {
    int salary;

   public:
    Staff() : salary(0) {}
    Staff(char *name, int age, char gender, int salary)
        : Person(name, age, gender), salary(salary) {}
    void read();
    void display();
};

void Staff::read() {
    Person::read();
    cout << "SALARY: ";
    cin >> salary;
}

void Staff::display() {
    Person::display();
    cout << "SALARY: " << salary << "\n";
}

class Student : private Person {
    char *dept;
    int year;

   public:
    Student() {
        dept = nullptr;
        year = 0;
    }
    Student(char *name, int age, char gender, char *dept, int year)
        : Person(name, age, gender), year(year) {
        this->dept = new char[strlen(dept) + 1];
    }
    ~Student() {
        delete dept;
        dept = NULL;
    }

    void read();
    void display();
};

void Student::read() {
    char deptText[100];
    cout << " [ Reading Student data ] \n";
    Person::read();
    cout << "DEPT: ";
    cin >> deptText;
    delete dept;
    dept = new char[strlen(deptText) + 1];
    strcpy(dept, deptText);
    cout << "YEAR: ";
    cin >> year;
}

void Student::display() {
    cout << " [ Displaying Student data ] \n";
    Person::display();
    cout << "DEPT: ";
    cout << dept << "\n";
    cout << "YEAR: ";
    cout << year << "\n";
}

class Professors : private Staff {
    int courseLoad;

   public:
    Professors() { courseLoad = 0; }

    Professors(char *name, int age, char gender, int courseLoad, int salary)
        : Staff(name, age, gender, salary), courseLoad(courseLoad) {}

    void read();
    void display();
};

void Professors::read() {
    cout << " [ Reading Professor data ] \n";
    Staff::read();
    cout << "COURSE LOAD: ";
    cin >> courseLoad;
}

void Professors::display() {
    cout << " [ Displaying Professor data ] \n";
    Staff::display();
    cout << "COURSE LOAD: ";
    cout << courseLoad << "\n";
}

class Clerk : private Staff {
    int workLoad;

   public:
    Clerk() { workLoad = 0; }
    Clerk(char *name, int age, char gender, int workLoad, int salary)
        : Staff(name, age, gender, salary), workLoad(workLoad) {}

    void read();
    void display();
};

void Clerk::read() {
    cout << " [ Reading Clerk data ] \n";
    Staff::read();
    cout << "WORK LOAD: ";
    cin >> workLoad;
}

void Clerk::display() {
    cout << " [ Displaying Clerk data ] \n";
    Staff::display();
    cout << "WORK LOAD: ";
    cout << workLoad;
}

int main() {
    // READING STUDENT DATA
    Student std1;
    std1.read();
    std1.display();

    Professors prof1;
    prof1.read();
    prof1.display();

    Clerk clk1;
    clk1.read();
    clk1.display();
    return 0;
}
