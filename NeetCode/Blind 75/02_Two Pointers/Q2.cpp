//https://leetcode.com/problems/3sum/description/

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

/*
Approach - So the main thing here is to get unique triplets and to not repeat the same triplets
so to do that we will canculate all possible solutions for one value and then if it is repeated we will skip it

to easily know if the value is reapeated we can simply sort and then compare i-1 with i

so this was the basics for this problem 

now main intution is : we will fix one variable from (0 to n-1) and check if nums[i] != nums[i-1] beacuse if it is equal to the previous value,
then we will get the same set of triplets so we can skip that itration.

then we will place j on i+1 and k on n-1.

and until j<k : we will check if the sum of the 3 is 0 if true the we need to add this tripet to solution
and then we need to take j to a index such that nums[j] != nums[j-1] and also k to a index such that nums[k] != nums[k+1].

if the sum > 0 we will do k--;
if sum < 0 we will do j++;

so basically when we fix one varible from (0 to n-1) this simply becomes a 2 sum problem where we are using 2 pointers from left and right on a aorted array,
to find the target using the 2 variables.
*/