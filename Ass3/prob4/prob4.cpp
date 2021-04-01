#include <string.h>

#include <iostream>
using namespace std;

struct node {
    char *person_name;
    node *next;
};

class CircularLL {
   private:
    node *ptr;

   public:
    CircularLL(int size) {
        ptr = NULL;
        node *org = ptr;
        for (int i = 0; i < size; i++) {
            cout << "Enter person's name: ";
            char s[20];
            cin >> s;
            int len = strlen(s);
            node *newNode = new node;
            newNode->person_name = new char[len];
            strcpy(newNode->person_name, s);
            newNode->next = NULL;
            if (org == NULL) {
                org = newNode;
                ptr = newNode;
            } else {
                org->next = newNode;
                org = newNode;
            }
        }
        org->next = ptr;
    }
    void iterateCircularLL();
    int isSingleElementLL();
    void deleteNextCircularLL(node *);
    node *findNElementCircularLL(int);
    node *findWinnerGame(int, int);
};

void CircularLL::iterateCircularLL() {
    node *itr = ptr;
    cout << itr->person_name << "\n";
    itr = itr->next;
    while (itr != ptr) {
        cout << itr->person_name << "\n";
        itr = itr->next;
    }
}

int CircularLL::isSingleElementLL() { return (ptr->next == ptr); }

void CircularLL::deleteNextCircularLL(node *addr) {
    if (isSingleElementLL()) {
        delete addr;
        addr = NULL;
        return;
    }

    node *temp = addr->next;
    addr->next = addr->next->next;
    cout << "   DELETED: " << temp->person_name << "\n";
    delete temp;
    temp = NULL;
}

node *CircularLL::findNElementCircularLL(int count) {
    int c = 1;
    node *itr = ptr;
    while (c < count) {
        itr = itr->next;
        c++;
    }
    return itr;
}

node *CircularLL::findWinnerGame(int skip, int num) {
    while (!isSingleElementLL()) {
        node *sNode = findNElementCircularLL(skip);
        ptr = sNode->next->next;
        deleteNextCircularLL(sNode);
    }
    return ptr;
}

int main() {
    int N, S;
    cout << "Enter number of persons: ";
    cin >> N;
    cout << "Enter skip count: ";
    cin >> S;
    CircularLL *personLL = new CircularLL(N);
    cout << "The names you entered are:\n";
    personLL->iterateCircularLL();
    cout << "----------------\n";
    cout << ": GAME STARTED :\n\n";
    node *winner = personLL->findWinnerGame(S, N);
    cout << "\n:   GAME ENDS  :\n";
    cout << "----------------\n";
    cout << "\n\nWINNER is: ";
    cout << winner->person_name << "\n";
    return 0;
}
