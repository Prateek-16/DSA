//https://leetcode.com/problems/find-the-duplicate-number/description/


/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
*/


/*
Appraoch - so we will be using the Slow and Fast Pointer approach here
since we cant make any chances to the input

1. Initially both slow and fast pointer will be at nums[0].
2. Now slow will move one step and fast will move 2 steps.
3. we need to move then once manually because our loop condition will be slow != Fast , and initally they are equal
    so slow = nums[slow] & fast = nums[nums[fast]]
4. while ( slow != fast ) :
    move slow once and fast twice 
    slow = nums[slow]
    fast = nums[nums[fast]]
5. When both are equal set fast at nums[0] again
6. agian loop until both are equal and this will be the Node with is repeated

Why this works? well there will be a cycle formed when we map this in alinked list
    Make the indexes as the Nodes and the values on that index as the next node they are pointing to...

for eg : nums = [1,3,4,2,2]
so linked list will be like : 0 -> 1 -> 3 -> 2 -> <- 4
2 and 4 are in a loop, and 2 will be the starting node, hence the answer
*/