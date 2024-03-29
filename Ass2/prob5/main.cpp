#include "linkedList.h"

using namespace std;

int main() {
    srand(time(0));
    int N, S;
    cout << "Enter number of persons: ";
    cin >> N;
    cout << "Enter skip count: ";
    cin >> S;
    node *personLL = circularLLInit(N);
    cout << "The names you entered are:\n";
    iterateCircularLL(personLL);
    cout << "----------------\n";
    cout << ": GAME STARTED :\n\n";
    node *winner = findWinnerGame(personLL, S, N);
    cout << "\n:   GAME ENDS  :\n";
    cout << "----------------\n";
    cout << "\n\nWINNER is: ";
    cout << winner->person_name << "\n";
    return 0;
}
