//https://leetcode.com/problems/reverse-integer/description/


/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/


/*
Approach - 2 Ways 
    1. My way ( i ignore the last line of the question )
        1. simply use a long long variable ans
        2. loop until x == 0 :
            1. ans = ans*10
            2. ans += x % 10
            3. x = x / 10
        
        3. After loop check if x is out of INT_MAX to INT_MIN range 
            if true, return 0
            if false, return ans

    2. Correct Way:
        Its given we cant use a long long variable so we need to solve this without using a long long variable
        1. So in this Approach we will reverse the digit one by one as done previously but instead we will check at each step if the reverse can get out of the range of integers
            integer range is -2,147,483,648 to 2,147,483,647

        2. so intialise integer variable result
        3. loop until x == 0 :
            1. let temp = x % 10
            2. x = x / 10
            3. Now we need to check if our result varibale can handle this temp added to it and still be within the range of integers
            4. Check for INT_MAX :
                if (result > INT_MAX / 10 || result == INT_MAX / 10 && temp > 7)
                    if true : then return 0
            5. Check for INT_MIN :
                if (result < INT_MIN / 10 || result == INT_MIN / 10 && temp < -8)
                    if true : then return 0
            6. result = result * 10 + temp
        4. return result
                

*/