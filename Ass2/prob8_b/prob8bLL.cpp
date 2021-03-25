#include "prob8bLL.h"
using namespace std;

node *circularLLInit(int size) {
    node *ptr = NULL;
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
    return ptr;
}

void iterateCircularLL(node *ptr) {
    node *itr = ptr;
    cout << itr->person_name << "\n";
    itr = itr->next;
    while (itr != ptr) {
        cout << itr->person_name << "\n";
        itr = itr->next;
    }
}

static int isSingleElementLL(node *ptr) { return (ptr->next == ptr); }

void deleteNextCircularLL(node *ptr) {
    if (isSingleElementLL(ptr)) {
        delete ptr;
        ptr = NULL;
        return;
    }

    node *temp = ptr->next;
    ptr->next = ptr->next->next;
    cout << "   DELETED: " << temp->person_name << "\n";
    delete temp;
    temp = NULL;
}

node *findNElementCircularLL(node *ptr, int count) {
    int c = 1;
    node *itr = ptr;
    while (c < count) {
        itr = itr->next;
        c++;
    }
    return itr;
}

int calculateFunction(int x) { return (x * x * x + 8 * x * x - 2 * x + 1); }

node *findWinnerGame(node *ptr, int num) {
    while (!isSingleElementLL(ptr)) {
        int skipCount = calculateFunction(rand() % num) % num;
        node *sNode = findNElementCircularLL(ptr, skipCount);
        ptr = sNode->next->next;
        deleteNextCircularLL(sNode);
    }
    return ptr;
}
