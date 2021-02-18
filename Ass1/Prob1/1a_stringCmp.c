/*
Problem 1 (A)
String comparison:Compare strings s1 and s2 - print 0 if both are same, print -1 if
alphabetically s1 comes before s2 and print 1 if alphabetically s1 comes after s2.
*/

#include <stdio.h>
#include <stdlib.h>

// Recursive function to get the final compare value
int strCmp(char string1[], char string2[], int n1, int n2, int index) {
    if (index < n1 && index < n2) {
        if (string1[index] == string2[index]) {
            return strCmp(string1, string2, n1, n2, index + 1);
        } else if (string1[index] < string2[index]) {
            return -1;
        } else {
            return 1;
        }
    } else if (index < n1) {
        return 1;
    } else if (index < n2) {
        return -1;
    } else {
        return 0;
    }
}

// Recursive function to get the string length
int strLen(char s[], int index) {
    if (s[index] == '\0')
        return index;
    else
        return strLen(s, index + 1);
}

int main() {
    int SIZE = 100;
    char string1[SIZE], string2[SIZE];
    printf("Enter string 1: ");
    scanf("%[^\n]%*c", string1);

    fflush(stdin);  // flushing the buffer

    printf("Enter string 2: ");
    scanf("%[^\n]%*c", string2);

    int n1 = strLen(string1, 0);
    int n2 = strLen(string2, 0);
    int comparedValue = strCmp(string1, string2, n1, n2, 0);
    printf("The compared value: %d\n", comparedValue);
    return 0;
}
