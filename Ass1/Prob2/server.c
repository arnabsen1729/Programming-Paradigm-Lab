#include "server.h"

#define false 0
#define true 1

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

int largestNumber(int array[], int size, int index) {
    if (index == (size - 1))
        return array[index];
    else {
        int nextLargeNumber = largestNumber(array, size, index + 1);
        return (array[index] > nextLargeNumber ? array[index] : nextLargeNumber);
    }
}

int searchInteger(int arr[], int length, int index, int key) {
    if (index >= length)
        return false;
    else if (arr[index] == key)
        return true;
    else
        return searchInteger(arr, length, index + 1, key);
}

void printReverseOrder(int arr[], int length, int index) {
    if (index >= length)
        return;
    else {
        printReverseOrder(arr, length, index + 1);
        printf("%d ", arr[index]);
    }
}

int palindromeCheck(char string[], int endPos, int index) {
    if (index > endPos)
        return true;
    else if (string[index] == string[endPos]) {
        return palindromeCheck(string, endPos - 1, index + 1);
    } else {
        return false;
    }
}

void replaceOccurrences(char string[], int length, int index, char key, char target) {
    if (index >= length)
        return;
    else if (string[index] == key) {
        string[index] = target;
    }

    replaceOccurrences(string, length, index + 1, key, target);
}

void flushInput() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void sortedAsc(int array[], int length) {
    if (length == 0)
        return;
    int pos = length - 1;
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[pos]) {
            pos = i;
        }
    }
    int temp = array[length - 1];
    array[length - 1] = array[pos];
    array[pos] = temp;
    sortedAsc(array, length - 1);
}
