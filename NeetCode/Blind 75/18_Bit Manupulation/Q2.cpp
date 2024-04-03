//https://leetcode.com/problems/counting-bits/description/


/*

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/


/*
Appraoch :
Brute Force :
    1. Loop from 0 to n and call funnctions findsetBits on each itration
    2. Find Set bit will return the number of set bits ( Q1 ) place that number at ith index
    
    This will call FindSetBit a lot of times

Optimized Approach :
    1. since we are storing a series of set bits so 
    2. For a Number n : number of set bits will be ( Number of set bits in n>>1 + n&1)
        n&1 will give us weather the last bit is set or not
        n>>1 will give us the number of set bits in n / 2 
    3. so we can use this observation to calculate the number of set bits.

Flow :
    1. for a number n : 
        initialize a vector result of size n + 1 with all values 0
    2. Loop from 1 to n + 1 
        1. for each number i : set result[i] = result[i>>1] + i&1 
            where i>>1 = i/2 and i&1 is the last bit.
*/