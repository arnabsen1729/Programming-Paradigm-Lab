#include "server.h"

int main() {
    // string compare
    char string1[] = "hello", string2[] = "world";
    int n1 = strLen(string1, 0);
    int n2 = strLen(string2, 0);
    int comparedValue = strCmp(string1, string2, n1, n2, 0);
    printf("The compared value: %d\n", comparedValue);

    // largest among n integers
    int arr[] = {1,
                 2,
                 3,
                 4};
    int length = 4;
    int largestValue = largestNumber(arr, length, 0);
    printf("Largest among n integers: %d\n", largestValue);

    // searching
    int key = 3;
    int isPresent = searchInteger(arr, length, 0, key);
    printf("Element %d exists in the array : %s\n", key, (isPresent ? "true" : "false"));

    // reverse order
    printf("The numbers in reverse order: ");
    printReverseOrder(arr, length, 0);
    printf("\n");

    // palindrome check
    int endPos = strLen(string1, 0) - 1;
    int isPalindrome = palindromeCheck(string1, endPos, 0);
    printf("%s is palindrome: %s\n", string1, (isPalindrome ? "true" : "false"));

    // replace occurrences
    char toReplace = 'e', replaceWith = 'w';
    length = strLen(string1, 0);
    replaceOccurrences(string1, length, 0, toReplace, replaceWith);
    printf("Final string after replacing: %s\n", string1);

    // sorting array
    length = 4;
    sortedAsc(arr, length);
    printf("Sorted Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
