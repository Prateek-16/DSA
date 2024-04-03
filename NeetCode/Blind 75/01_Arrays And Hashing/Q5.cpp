//https://leetcode.com/problems/top-k-frequent-elements/description/

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/


/*
Approach - There can be multiple approaches to solve this question in nlogn time 
but we will do in linear time using bucket sort

Step 1: Map all the elements with there frequency. 
Step 2: Make a bucket such that we treat each index as frequency number and store the vector of integers with that freq 
        with the help of the Map.
Step 4: Make an answer vector of integers.
Step 4: Now since we want to top k Most frequent elements, itrate the bucket from the end and whenever vector is present for the frequency
        add the vector elements to the ans vector.
*/