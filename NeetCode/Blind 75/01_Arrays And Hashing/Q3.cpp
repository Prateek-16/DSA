//https://leetcode.com/problems/two-sum/description/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

/*
Approach - 1 way will be to use 2 for loops and the check if nums[i] + nums[j] = target 
this will be of O(n^2)

better approach will be to use a hashmap :
we need to find target - nums[i] for each itration,
then search if target - nums[i] exist in the map : 
if not then insert i into the map at nums[i].
*/