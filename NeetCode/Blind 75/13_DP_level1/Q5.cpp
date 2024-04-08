//https://leetcode.com/problems/palindromic-substrings/description/


/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/


/*
Approach - We know the previous code which expands outside for each character and finds a palindrome,
    so we can mentain a count variable each time i == j and return the count variable

    Steps 1: Loop from 0 to n characters :
        for each character find its odd and even number of palindrome ie i == j and j = i + 1 : 
        add all the values for each character.
        return this are final answer after the loop ends.
    
    Step 2 : Solve Function ( to count number of palindromic strings ):
        1. initialize a count variable
        2. until i == j move outwards and do count++;
        3. outside loop return count.
    
*/