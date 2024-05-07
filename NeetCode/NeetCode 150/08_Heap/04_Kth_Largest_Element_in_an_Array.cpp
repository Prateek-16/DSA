//https://leetcode.com/problems/kth-largest-element-in-an-array/description/


/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/


/*
Approach - we need to do this withpout sorting, 
2 ways : 1. using min heap OR 2. Using max heap
1. Using min heap :
    Enter all the elements in the heap
    pop elements from the heap until the heap size is equal to k
    then return thr top of the heap

2. Using max heap : 
    enter all the elements in the heap
    remove top k-1 elements from the heap
    return thr top of the heap
*/