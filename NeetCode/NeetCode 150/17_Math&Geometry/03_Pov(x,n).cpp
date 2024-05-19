//https://leetcode.com/problems/powx-n/description/


/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/


/*
Approach - so we have a O(log n) solution for this :
    suppose we have 2^5 :
        we can write this as -> (2^4)*2 -> ((2*2)^2) * 2
    or lets say we have 2^8 :
        we can write this as -> ((2*2)^4) -> ((2*2*2)^2)

    so what this show us is :
        we to find x^n , we can do (x*x)^n/2

    Steps :
    1. let double num = 1
    2. if "n" is negative, reverse x
    3. loop unitl n != 0 :
        1. we know 2 must to steps are :
        let x = x * x and n = n / 2 also its important to store x and n back to the same variable
        2. but another step will be for odd powers, actually this will be the first step in the loop
        ie 2^5 -> ((2*2)^2) * 2 an extra 2 is needed
        so whenever (n&1) is true, ie n is odd,
        we will do num *= x

    4. Return nums , we return nums beacuse even we know for sure that wheather the case is even or odd for once the value of n will be 1
    and in that case we will get the value inside our nums.
*/