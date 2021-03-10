#include <iostream>

using namespace std;

template <typename T>
void mySwap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void mySort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                mySwap(arr[j + 1], arr[j]);
            }
        }
    }
}

void intSort() {
    cout << "---INT---\n";
    int a[] = {4, 3, 1, 2, 6};
    int n = sizeof(a) / sizeof(int);
    cout << "Before Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    mySort(a, n);
    cout << "\nAfter sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << "\n\n";
}

void shortSort() {
    cout << "---SHORT---\n";
    short a[] = {4, 3, 1, 2, 6};
    int n = sizeof(a) / sizeof(short);
    cout << "Before Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    mySort(a, n);
    cout << "\nAfter sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << "\n\n";
}

void floatSort() {
    cout << "---FLOAT---\n";
    float a[] = {2.4, 3.5, 1.1, 2.8, 6.9};
    int n = sizeof(a) / sizeof(float);
    cout << "Before Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    mySort(a, n);
    cout << "\nAfter sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << "\n\n";
}

void doubleSort() {
    cout << "---DOUBLE---\n";
    double a[] = {2.4, 3.5, 1.1, 2.8, 6.9};
    int n = sizeof(a) / sizeof(double);
    cout << "Before Sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    mySort(a, n);
    cout << "\nAfter sort:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }
    cout << "\n\n";
}

int main() {
    intSort();
    shortSort();
    floatSort();
    doubleSort();
    return 0;
}
