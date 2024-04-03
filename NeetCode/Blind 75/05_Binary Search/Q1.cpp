//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.


Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

/*
Approach - So we have to methods for this question 
1. Find the Pivot element of the array (the Greatest element of the array)
2. If the 1st element of the array is less than the last element of the array means the array is not rotated, so return nums[0]
3. Else the array is rotated, Hence return the next element of the pivot element.

Approach 2 ( without pivot element)
1. In this approach we dont need pivot but this approach only works in rotated array.
2. set up left and right pointers and mini = nums[0] (to store the minimum element of the array). 
    The reason we took nums[0] is because the array can be not rotated at all and in that case we need to return nums[0].
3. while (left <= right):
    1. check if this is a sorted array. nums[left] < nums[right]
        if true, then return min(mini,nums[left]); (approach does not work in sorted array)
    2. Now Calculate the Mid element of the array, and if mid is less than mini then store mid in mini.
    3. check if mid is greater than nums[left] 
        if true (that means we are on left part) - So to find the minimum we need to move to the right.
    4. if false (that means we are on the right part) - So to find the minimum we need to move to the left.
*/