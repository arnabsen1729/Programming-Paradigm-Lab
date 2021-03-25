#include <strings.h>

#include <iostream>
using namespace std;

enum style { ITALICS = 1, BOLD = 2, UNDERLINE = 4 };

int main() {
    string s;
    cout << "Enter a text: ";
    cin >> s;
    string options[] = {"Italics", "Bold", "Underline"};
    int design = 0;
    for (int i = 0; i < 3; i++) {
        cout << options[i] << ": ";
        int val;
        cin >> val;
        design += val << i;
    }
    if (design & ITALICS) {
        cout << "Italics added\n";
    }
    if (design & BOLD) {
        cout << "Bold added\n";
    }
    if (design & UNDERLINE) {
        cout << "Underline added\n";
    }
    // cout << design;
    return 0;
}
