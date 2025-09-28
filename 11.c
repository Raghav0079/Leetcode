/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.*/

# include <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = min_height * width;
        if (area > max_area) {
            max_area = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
