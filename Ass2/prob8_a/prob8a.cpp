#include "prob8aLL.h"

using namespace std;

int main() {
    int N, S;
    cout << "Enter number of persons: ";
    cin >> N;
    node *personLL = circularLLInit(N);
    cout << "The names you entered are:\n";
    iterateCircularLL(personLL);
    cout << "----------------\n";
    cout << ": GAME STARTED :\n\n";
    node *winner = findWinnerGame(personLL, N);
    cout << "\n:   GAME ENDS  :\n";
    cout << "----------------\n";
    cout << "\n\nWINNER is: ";
    cout << winner->person_name << "\n";
    return 0;
}
