//https://leetcode.com/problems/jump-game/description/


/*

You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/


/*
Approach - Brute Approach :
    1. mentain a variable reachable , which tells you the indexes you can reach
    2. Loop for i = 0 to nums.size()
    3. If at any point i is greater than reachable , return false
    4. Now get the current value at nums[i] these are the indexes you can jump to
    5. Loop on these indexes and find the maximum value and its index
    6. update reachable with max of previous reachable or maxi value's index + maxi value

    This is O(n2) approach and we can solve this in O(n) Time also

Optimized approach :
    1. mentain a variable reachable = nums[0], which tells you the indexes you can reach
    2. Loop for i = 0 to nums.size()
    3. If at any point i is greater than reachable , return false
    4. Now instead of Looping and finding the max value just update the reachable value with [current values + i]
    5. int possible_reachble = nums[i] + i 
    6. Reachable = max(reachable, possible_reachble)
    7. If reachable is greater or equal to nums.size() , return true

So in Brute Approach we where Looping 2 Times to find the maximum reachable index 

But 
In Optimised approach since we are already looping on all values of nums, we will just find the maximum reachable
    from the current value, if its greater than previous reachbale then we will update the reachable,
    and if at any point we reach out of reachable then we return false 
*/