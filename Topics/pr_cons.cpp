#include <iostream>
using namespace std;

class Stud {
    int roll;
    static int count;
    static Stud* objects;

    Stud() {
        roll = 10;
        count++;
        cout << "Number of objects created: " << count << "\n";
    }

   public:
    static Stud* createObj() {
        if (count < 3) {
            cout << "Object can be create\n";
            objects = new Stud();
            return objects;
        } else {
            cout << "Limit Reached!!\n";
            return nullptr;
        }
    }
    ~Stud();
};

int Stud::count = 0;
Stud* Stud::objects = nullptr;

Stud::~Stud() { count--; }

int main() {
    Stud* obj = obj->createObj();
    Stud* obj2 = obj2->createObj();
    Stud* obj3 = obj3->createObj();
    Stud* obj4 = obj4->createObj();
    return 0;
}

// https://www.oreilly.com/library/view/c-cookbook/0596007612/ch08s10.html
// https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
