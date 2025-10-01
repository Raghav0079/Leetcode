/*You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(numsSize * sizeof(char*));
    int count = 0;

    int start = nums[0];
    int end = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == end + 1) {
            end = nums[i];
        } else {
            if (start == end) {
                result[count] = (char*)malloc(12 * sizeof(char));
                sprintf(result[count], "%d", start);
            } else {
                result[count] = (char*)malloc(25 * sizeof(char));
                sprintf(result[count], "%d->%d", start, end);
            }
            count++;
            start = nums[i];
            end = nums[i];
        }
    }

    if (start == end) {
        result[count] = (char*)malloc(12 * sizeof(char));
        sprintf(result[count], "%d", start);
    } else {
        result[count] = (char*)malloc(25 * sizeof(char));
        sprintf(result[count], "%d->%d", start, end);
    }
    count++;

    *returnSize = count;
    return result;
}