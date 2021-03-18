#include <iostream>

using namespace std;

template <typename T>
void mySwap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

struct Node {
    int x;
    char y;
};

void intSwap() {
    cout << "\n";
    cout << "Swapping int:\n";
    cout << "-------------\n";
    int a;
    int b;

    cout << "Before Swap:\n";
    cout << "Value of a: \n";
    cin >> a;
    cout << "Value of b: \n";
    cin >> b;
    mySwap(a, b);
    cout << "After Swap:\n";
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
}

void shortSwap() {
    cout << "\n";
    cout << "Swapping short:\n";
    cout << "-------------\n";
    short int a;
    short int b;
    cout << "Before Swap:\n";
    cout << "Value of a: \n";
    cin >> a;
    cout << "Value of b: \n";
    cin >> b;
    mySwap(a, b);
    cout << "After Swap:\n";
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
}

void floatSwap() {
    cout << "\n";
    cout << "Swapping float:\n";
    cout << "-------------\n";
    float a;
    float b;
    cout << "Before Swap:\n";
    cout << "Value of a: \n";
    cin >> a;
    cout << "Value of b: \n";
    cin >> b;
    mySwap(a, b);
    cout << "After Swap:\n";
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
}

void doubleSwap() {
    cout << "\n";
    cout << "Swapping double:\n";
    cout << "-------------\n";
    double a;
    double b;
    cout << "Before Swap:\n";
    cout << "Value of a: \n";
    cin >> a;
    cout << "Value of b: \n";
    cin >> b;
    mySwap(a, b);
    cout << "After Swap:\n";
    cout << "Value of a: " << a << "\n";
    cout << "Value of b: " << b << "\n";
}

void structSwap() {
    cout << "Swapping struct:\n";
    cout << "Enter values (int, char): \n";
    Node a;
    Node b;
    cout << "Before Swap:\n";
    cin >> a.x >> a.y;
    cout << "Value of a: " << a.x << " " << a.y << "\n";
    cin >> b.x >> b.y;
    cout << "Value of b: " << b.x << " " << b.y << "\n";
    mySwap(a, b);
    cout << "After Swap:\n";
    cout << "Value of a: " << a.x << " " << a.y << "\n";
    cout << "Value of b: " << b.x << " " << b.y << "\n";
}

int main() {
    intSwap();
    cout << "\n";
    shortSwap();
    cout << "\n";
    doubleSwap();
    cout << "\n";
    floatSwap();
    cout << "\n";
    structSwap();

    return 0;
}
