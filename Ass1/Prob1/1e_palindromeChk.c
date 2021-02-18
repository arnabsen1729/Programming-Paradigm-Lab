/*
Problem 1 (E)
Find out whether the given string S of length n is a palindrome or not (returns true
if S is a palindrome, returns false otherwise). [A palindrome is a string if it reads
same from both the ends. Eg. ABCDCBA]
*/
#include <stdio.h>
#define true 1
#define false 0

int palindromeCheck(char string[], int endPos, int index) {
    if (index > endPos)
        return true;
    else if (string[index] == string[endPos]) {
        return palindromeCheck(string, endPos - 1, index + 1);
    } else {
        return false;
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
    char string[SIZE];
    printf("Enter string: ");
    scanf("%[^\n]%*c", string);

    int endPos = strLen(string, 0) - 1;
    int isPalindrome = palindromeCheck(string, endPos, 0);
    printf("%s is palindrome: %s\n", string, (isPalindrome ? "true" : "false"));
    return 0;
}
