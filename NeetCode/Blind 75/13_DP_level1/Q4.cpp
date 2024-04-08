//https://leetcode.com/problems/longest-palindromic-substring/description/


/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/


/*
Approach - So to find the palindromic substring,instead of moving from outside to inside we will move from inside to outside
    Step 1: Loop on the string s :
        for each character in s call a solve function
        also mentain 2 variables 
        1. for max size
        2. for the starting of max palindrome ( so that we can use substring function)

    Step 2 : Solve Function 
        parameters : s, i , j (will explain) , maxsize, staringpoint
        there are 2 ways a palindrome can be fromed outwards :
         1. Odd Length palindrome : i and j are same (i and j beignt he middle point)
         2. Even Length palindrome : i and j are adjacent but not same j = i + 1 (No Middle point) 
        
    Step 3 : Logic of function : 

        1. parameters : s, i , j (will explain) , maxsize, staringpoint

        2. While i and j are in range send the outwards as much as possible if the are equal charactersm

        3. now if (i - j + 1 > maxsize)
            means we have new maxi 
            so update maxi and the varible of starting point = i + 1;

    Thats It

*/
