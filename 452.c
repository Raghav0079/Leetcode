/*There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void * a, const void * b) {
    int valA = (*(int **)a)[1];
    int valB = (*(int **)b)[1];
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if(pointsSize==0) return 0;
    qsort(points, pointsSize, sizeof(points[0]), cmp);
    int count = 1;
    int end = points[0][1];
    for(int i=1; i<pointsSize; i++){
        if(points[i][0] > end){
            count++;
            end = points[i][1];
        }
    }
    return count;
}
