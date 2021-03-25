#include <iostream>

using namespace std;

int x = 10;
int main() {
    int count = 1;
    while (count) {
        count--;
        int x = 20;
        cout << "Value of local x: " << x << "\n";
        cout << "Value of global x: " << ::x << "\n";
    }
}
