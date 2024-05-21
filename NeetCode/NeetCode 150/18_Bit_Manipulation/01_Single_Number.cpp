//https://leetcode.com/problems/single-number/description/


/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 
*/


/*
Approach - XOR of two numbers is :
    0 ^ 0 || 1 ^ 1 = 0
    1 ^ 0 || 0 ^ 1 = 1

    1. XOR all the numbers in the array
    2. The same numbers will cancel out and be 0 
    3. In the end only the single time occuring will be in result
*/