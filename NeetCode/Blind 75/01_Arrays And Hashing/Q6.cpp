//https://leetcode.com/problems/product-of-array-except-self/description/

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

/*
Approach - Simple approach will be to to mentain a prev and next arrays and store the previous and next elements product in then
and then multiplying them to generate a new array answer.

but this approach will require space of 3 vectors of n size 

so rather than making 3 arrays we will store the previous elements in the answer array and then multiply them with the next element in the
answer array itself.

also remember that while multiplying or calculating the next product store the postfix in a variable beacuse you cant acess the postflix 
from answer[i+1] as we will be itrating backwards and answer[i+1] will be prefix * postfix : where prefix is already at that index and
posfix is a mentained variable.
*/