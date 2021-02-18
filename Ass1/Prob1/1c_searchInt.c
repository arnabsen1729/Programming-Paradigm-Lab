/*
Problem 1 (C)
Search for a given integer num in a given list L of n integers (returns true if num
occurs in L, otherwise returns false).
*/
#include <stdio.h>
#define false 0
#define true 1

int searchInteger(int arr[], int length, int index, int key) {
    if (index >= length)
        return false;
    else if (arr[index] == key)
        return true;
    else
        return searchInteger(arr, length, index + 1, key);
}

int main() {
    int arr[100];
    printf("Enter number of integers: ");
    int length;
    scanf("%d", &length);

    printf("Enter the numbers:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search:\n");
    int key;
    scanf("%d", &key);
    int isPresent = searchInteger(arr, length, 0, key);
    printf("Element %d exists in the array : %s\n", key, (isPresent ? "true" : "false"));
    return 0;
}
