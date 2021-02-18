/*
Problem 1 (B)
Find largest among n integers
*/

#include <stdio.h>

int largestNumber(int array[], int size, int index) {
    if (index == (size - 1))
        return array[index];
    else {
        int nextLargeNumber = largestNumber(array, size, index + 1);
        return (array[index] > nextLargeNumber ? array[index] : nextLargeNumber);
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

    int largestValue = largestNumber(arr, length, 0);
    printf("Largest among n integers: %d\n", largestValue);

    return 0;
}
