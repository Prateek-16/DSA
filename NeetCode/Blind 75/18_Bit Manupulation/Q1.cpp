//https://leetcode.com/problems/number-of-1-bits/description/


/*
Write a function that takes the binary representation of a positive integer and returns the number of 
set bits it has (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
*/

/*
Approach : 
Brute Force :
    1. find the last bit of the given number (n&1).
    2. Whenever lst bit is 1 then do count++
    3. loop until number n is 0.
    4. right Shift n at each iteration

Optimization : 
    1. Formula to clear the last set bit of any number will be n&(n-1) 
    2. use this formula in a loop until the numbe is 0.
    3. Mentain count++ at each iteraion 
*/