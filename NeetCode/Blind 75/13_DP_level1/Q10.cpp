//https://leetcode.com/problems/longest-increasing-subsequence/description/


/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/


/*
Approach 1 - With Recursion and DP

Simple Include Exclude Approach : 

Mentain a previous variable to store the index of previous number in the subsequence (intially = -1)

Step 1 : Make a function solve with inputs : nums , prev , curr

step 2 : BASE CASE : if curr > nums size , return 0 

Step 3: MAIN PROCESSING :
    
    we need to compare the current number with the previous index number 
    if ( prev = -1 || nums[curr] > nums[prev] ),
        then include current in subsequence : means current index becomes the new previous and curr + 1
        include = 1 + solve ( nums , curr , curr + 1)
    
    Exclude current from subsequence : means previous index remains same and index + 1, 
        exclude = 0 + solve ( nums , prev , curr + 1)
        we will run the case regardless of the if condition

    
Step 4: return the maximum of include or exclude 

WE WILL NEED TO OPTIMIZE THIS WITH THE HELP OF DP 
THE DP INCLUDES INDEX SHIFTING CONCEPT


Approach 2 - With Binary Search 
    THe approach is simple since we need need the size only 
    we will mentain a vector answer to store the subsequence 
    
    THen we will itrate on the array nums i = 0 to size 
        if ( ans is empty || nums[i] > ans.back())
            simply push the number in the ans 
        else {
            use binary search to find the number just greater than the current nums[i] and replace them
            use lowerbound function to Find the number just greater than current nums[i]..
        } 
*/