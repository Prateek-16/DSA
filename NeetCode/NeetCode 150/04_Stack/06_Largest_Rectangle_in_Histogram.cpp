//https://leetcode.com/problems/largest-rectangle-in-histogram/description/


/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/


/*
Approach - So we need to calculate the area of the largest rectangle so we have a dependency on the smaller rectangle
So we will find the next smaller rectangle and the previous smaller rectangle of the given set
for index 0 -> prev smaller = -1
    index n-1 -> next smaller = n

So once we have the next and the previous smaller rectangle indexes
    we can iterate over the rectangles and calculate the area of the rectangle
        area = height * width
        width will be next[i] - prev[i] - 1 (formula but hit and try)
        so we can store the max of all the areas in a variable
and finally return the variable


*/