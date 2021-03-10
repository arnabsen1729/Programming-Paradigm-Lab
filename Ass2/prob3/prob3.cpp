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
    cout << "Swapping int:\n";
    cout << "Enter values:\n";
    int a;
    int b;
    cin >> a >> b;

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
    cout << "Swapping short:\n";
    cout << "Enter values:\n";
    short int a;
    short int b;
    cin >> a >> b;
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
    cout << "Swapping float:\n";
    cout << "Enter values:\n";
    float a;
    float b;
    cin >> a >> b;
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
    cout << "Swapping double:\n";
    cout << "Enter values:\n";
    double a;
    double b;
    cin >> a >> b;
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
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cout << "Before Swap:\n";
    cout << "Value of a: " << a.x << " " << a.y << "\n";
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
