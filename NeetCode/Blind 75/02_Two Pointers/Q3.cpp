//https://leetcode.com/problems/container-with-most-water/description/

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

/*
Approach - So one will be the brut force solution which will be to find all possible heights and then caluclation the max,
and this will be a o(n2) solution.

so another approach is to use 2 pointers.
one at start and another at end: then compare the water they can store.
( min height of start or end )*( e - s ). This will be the area of rectangle and the amout of water the container can store.

mentain a variable for maximum amount of water and that will be the answer.
*/