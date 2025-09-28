/*Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.*/

#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left =0 ,right =0 ;
    int sum =0 ;
    int minLen=numsSize +1;
    while (right < numsSize){
        sum += nums[right];
        while (sum >= target){
            minLen = (right - left + 1 < minLen) ? right - left + 1 : minLen;
            sum -= nums[left];
            left ++;

        }
        right ++;
    }
    return (minLen == numsSize + 1) ? 0 : minLen;
}
