//https://leetcode.com/problems/sum-of-two-integers/description/


/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
*/


/*
Approach - So we need to add without using and operations 

XOR + AND of 2 Numbers is equals to the addition of 2 numbers

suppose we have a = 9  ie 1 0 0 1
                b = 11 ie 1 0 1 1

        so a ^ b  =    ie 0 0 1 0
        so a & b  =    ie 1 0 0 1

        so we Know 1 and 1 will be 0 but there will be a carry of 1 to the left
        so A & B will give us the carry
        we need to add this carry into the a^b answer but first left shift the carry

        so a ^ b  =         0 0 1 0
        so (a & b) <<1  = 1 0 0 1

        Now we need to add these 2 , and we again know that to add 2 numbers we need to Find XOR and AND of the 2
        we will keep on doing this until our carry is 0 
        then return the XOR answer.

FLow :  1. given A and B
        2. Loop until B is 0 (carry)
        3. do A & B and store in some variable Temp
        4. do A = A^B 
        5. do B = Temp
        doing so will change A to the XOR value and B to the Carry value and will keep on adding them until carry is 0.  
*/