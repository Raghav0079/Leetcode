/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int ** result = (int **) malloc(sizeof(int *) * (intervalsSize + 1));
    int * coLSize = (int *) malloc(sizeof(int) * (intervalsSize + 1));
    int i=0,j=0;
    int start =newInterval[0];
    int end = newInterval[1];
    int flag = 0;
    while(i<intervalsSize){
        if(intervals[i][1]<start){
            result[j] = (int *) malloc(sizeof(int) * 2);
            result[j][0] = intervals[i][0];
            result[j][1] = intervals[i][1];
            coLSize[j] = 2;
            j++;
        }else if(intervals[i][0]>end){
            if(flag==0){
                result[j] = (int *) malloc(sizeof(int) * 2);
                result[j][0] = start;
                result[j][1] = end;
                coLSize[j] = 2;
                j++;
                flag=1;
            }
            result[j] = (int *) malloc(sizeof(int) * 2);
            result[j][0] = intervals[i][0];
            result[j][1] = intervals[i][1];
            coLSize[j] = 2;
            j++;
        }else{
            if(intervals[i][0]<start){
                start = intervals[i][0];
            }
            if(intervals[i][1]>end){
                end = intervals[i][1];
            }
        }
        i++;
    }
    if(flag==0){
        result[j] = (int *) malloc(sizeof(int) * 2);
        result[j][0] = start;
        result[j][1] = end;
        coLSize[j] = 2;
        j++;
    }
    *returnSize = j;
    *returnColumnSizes = coLSize;
    return result;
}
