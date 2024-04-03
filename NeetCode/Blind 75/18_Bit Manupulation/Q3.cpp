//https://leetcode.com/problems/reverse-bits/description/


/*

Reverse bits of a given 32 bits unsigned integer.

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
so return 3221225471 which its binary representation is 10111111111111111111111111111111.

*/


/*
Approach - 
Steps to reverse : 
1. create a new variable to store the results
2. Loop form 0 to 31 :
    1. left shift result ( to store the new bit ).
    2. get last bit from given n : by doing n&1.
    3. store this bit into result by doing | (or) operation.
    4. right shift the number n.

*/