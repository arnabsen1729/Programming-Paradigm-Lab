/*
Problem 1 (F)
Replace all occurrences of the character c1 in the string S by the character c2.
*/
#include <stdio.h>

void replaceOccurrences(char string[], int length, int index, char key, char target) {
    if (index >= length)
        return;
    else if (string[index] == key) {
        string[index] = target;
    }

    replaceOccurrences(string, length, index + 1, key, target);
}

// Recursive function to get the string length
int strLen(char s[], int index) {
    if (s[index] == '\0')
        return index;
    else
        return strLen(s, index + 1);
}

// for some reason fflush(stdin) wasn't working
void flushInput() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main() {
    int SIZE = 100;
    char string[SIZE];
    printf("Enter string: ");
    scanf("%s", string);

    flushInput();
    printf("The char to be replaced: ");
    char toReplace;
    scanf("%c", &toReplace);

    flushInput();
    printf("The char to be replaced with: ");
    char replaceWith;
    scanf("%c", &replaceWith);
    int length = strLen(string, 0);
    replaceOccurrences(string, length, 0, toReplace, replaceWith);
    printf("Final string: %s\n", string);
    return 0;
}
