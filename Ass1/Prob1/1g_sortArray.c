/*
Problem 1 (G)
Sorting an array A of n integers in ascending order.
*/

#include <stdio.h>

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

int main() {
    int arr[100];
    printf("Enter number of integers: ");
    int length;
    scanf("%d", &length);

    printf("Enter the numbers:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }
    sortedAsc(arr, length);
    printf("Sorted Array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
