/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int * result =(int *)malloc (2*sizeof(int));
    int left =0;
    int right =numbersSize-1;
    while (left < right){
        int sum = numbers[left]+ numbers [right];
            if (sum == target){
                result [0]=left +1;
                result [1]=right +1;
                * returnSize =2;
                return result ;
            }
            else if (sum < target){
                left++;
            }
            else {
                right--;
            }
    }
    *returnSize = 0;
    return NULL;
}
