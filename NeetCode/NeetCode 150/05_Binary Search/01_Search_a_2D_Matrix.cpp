//https://leetcode.com/problems/search-a-2d-matrix/description/


/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/


/*
Approach - Basically hime ek matrix mai binary search lagani hai
toh simply hume 2D to 3D conversion karna hai

suppose humara mid = x 
but hume is mid ko rows and cols ki terms mai change karna hoga to get the element at that index, so to do that
we know :
        row index = mid / total_cols 
        column index = mid % total_cols
    then toh you can easily access the mid element and compare if
    mid == target
    or mid > target , then end = mid -1 
    or mid < target , then start = mid + 1
*/