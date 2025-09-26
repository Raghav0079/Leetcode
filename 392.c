/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool isSubsequence (char*s,char*t){
    int lens=strlen(s);
    int lent=strlen(t);
    int i=0,j=0;

    while (i<lens && j<lent){
        if (s[i]==t[j]){
            i++;
        }
        j++;
    }
    return i == lens;
}
