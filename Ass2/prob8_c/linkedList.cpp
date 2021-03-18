#include "linkedList.h"
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

int polynomialFn(int opt, int x) {
    switch (opt) {
        case 1:
            return (x * x * x + 8 * x * x + 9 * x + 10);
        case 2:
            return (x * x * x + 6 * x * x + 4 * x + 14);
        case 3:
            return (2 * x * x * x + 8 * x * x + 8 * x + 1);
        case 4:
            return (3 * x * x * x + 17 * x * x + 22 * x + 10);
        default:
            return 0;
    }
}

int sanitize(int x, int n) {
    if (x >= 0) {
        return x % n;
    } else {
        return n - (x % n + n);
    }
}

node *findWinnerGame(node *ptr, int num) {
    while (!isSingleElementLL(ptr)) {
        int skipCount = polynomialFn(rand() % 4 + 1, rand() % num) % num;
        node *sNode = findNElementCircularLL(ptr, skipCount);
        ptr = sNode->next->next;
        deleteNextCircularLL(sNode);
    }
    return ptr;
}
