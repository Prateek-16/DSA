//https://leetcode.com/problems/jump-game-ii/description/


/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/


/*
Approach - We need to return the minimum number of jumps to reach last index
So simple approach will be a brute force approach or a greedy approach

What it means is :
    ek reachable variable mentain kar lo, woh batega kitna index tak pahuch sakte hai, then itrate karo pure rechable indexes par and new reachable find karo
    this new reachble should be maximum possible.
    in this way we can reach the last index in minimum jumps

so my approch will be using double looping
    we will have a reachable variable initially equal to nums[0].
    then we will have a itrator i at index 0 and will loop until i is less than (n-1)
    inside this we will take the integer at the current index i ie nums[i].
    this nums[i] + i will be our possible reachable.
    if reachable is more than or equal to the last index we will return the count + 1 ( we are mentaining a count variable ).
    otherwise we will loop from i+1th index to i+nums[i]th index ie reachable index
        inside this loop we will find the maximum number and its index ( we are find maximum jump we can take, for minimum count )
        and if we find the maximum number we will update the reachable (we can either update here or above )
    this maximum index will be the new index of i means i will jump to this index
    and count will be increased by 1.
*/