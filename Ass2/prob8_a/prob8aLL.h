#include <math.h>
#include <string.h>
#include <time.h>

#include <iostream>

struct node {
    char *person_name;
    node *next;
};

node *circularLLInit(int);
void iterateCircularLL(node *);
static int isSingleElementLL(node *);
void deleteNextCircularLL(node *);
node *findNElementCircularLL(node *, int);
node *findWinnerGame(node *, int);
