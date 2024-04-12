//https://leetcode.com/problems/longest-common-subsequence/description/


/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/


/*
Approach - Step 1. Simple hai 2 strings di hai hai usme longest common subsequence batana hai, 
Step 2. 2 pointers le lenge i1 and i2 for both strings
Step 3. BASE CASE : agar koi bhi index out of length gaya toh, return 0.
Step 4. MAIN CASE : 
    check i and j , if both are same:
        ans = 1 + solve ( i + 1, j + 1)
    else {
        ans = 0 + max(solve ( i + 1, j ),solve ( i, j + 1 ))
    }
    return ans..

*/