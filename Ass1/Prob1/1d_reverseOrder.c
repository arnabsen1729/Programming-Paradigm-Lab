/*
Problem 1 (D)
Print a given list L of n items in reverse order
*/
#include <stdio.h>

void printReverseOrder(int arr[], int length, int index) {
    if (index >= length)
        return;
    else {
        printReverseOrder(arr, length, index + 1);
        printf("%d ", arr[index]);
    }
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

    printf("The numbers in reverse order:\n");
    printReverseOrder(arr, length, 0);
    return 0;
}
