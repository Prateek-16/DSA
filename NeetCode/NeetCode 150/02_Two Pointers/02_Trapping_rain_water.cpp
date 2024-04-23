//https://leetcode.com/problems/trapping-rain-water/description/


/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/


/*
Approach - go to every height in the array 
Now how can we decide how much water will fill in this block,
simple : get the left maximum and right maximum
the water stored in the current block should be minimum of ( left_maxi,right_maxi ) - Height of building in current block
*/