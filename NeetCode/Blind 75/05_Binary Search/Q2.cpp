//https://leetcode.com/problems/search-in-rotated-sorted-array/description/


/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

/*
Approach By Love Babbar - So in Love's approach we need to find the pivot index, so to find the pivot index
step 1 - calculate mid element normally, and compare if mid greater than the next element while being in range of the array, 
if mid is greater, then that means mid is the pivot or if mid-1 is greater than mid then that means that mid -1 is the pivot.

step 2 - Now compare mid with starting index element :
    if greater then do start = mid + 1
    if not then do end = mid -1

By doing these steps repeatedly we can find the pivot index first

once we found the pivot index we will compare if the target is more or less that the pivot element and the starting element.
and apply Normal binary search on either left or right subarray .

Approach 2 : NeetCode's Approach - so needcode's approach doesnt require us to calculate the pivot element
step 1 - calcualte mid element using normal binary search approach with start and end pointers
step 2 - Now find if your just calculated mid is in the left subarray or the right, do this by comparing with the 1st element
    if in Left Subarray (mid > start):
        Now compare mid and target :
            if target is more than mid || target is less than then start then move right by start = mid + 1
            if target is less than mid 
                if target is less than mid but greater than start then move to left
                if target is less than mid and less than start then move to right
    if in right subarray(mid < start):
        Now compare mid and the target:
            if target is less than mid || target is more than mid and start
                move left;
            if target is more than mid
                move right;



*/