//https://leetcode.com/problems/multiply-strings/description/


/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/


/*
Approach - 1. get sizes of num1 and num2 ie m and n
2. reverse num1 and num2 for easy multiplication
3. initialize result string with size (m + n) //max possible length of 2 multiples
4. loop i from 0 to m
    loop j from 0 to n
        1. multiply num1[i] * num2[j] let it be "digit"    //dont forget to convert char -> int

        2. Digit need to go at result[i + j]   //that's How multiplication works
            but result[i + j] can have some carry value from previous multiplication also so we will separately add them first

        3. let sum = result[i + j] + digit  //dont forget to convert result[i + j] from char to int
            now this sum need to be at position result[i + j] but we can only store a single digit result becomes a carry for next digit

        4. result[i + j] = sum % 10     //dont forget to convert sum from int to char

        5. result[i + j + 1] = (result[i + j + 1] + sum / 10)     //dont forget to convert result[i + j + 1] from char to int & then store the sum from int to char
            result[i + j + 1] might have some previous values therefore we will add sum / 10 to it.
        
        6. Make sure to make suitable convertions from int to char and char to int 
            int to char = + '0'
            char to int = - '0'

5. After both for loops result will be ready but 2 issue will be there :
    1. we need to reverse the result ( beacuse we initially reversed the inputs )
    2. we might not consume the full size of result which will cause LEADING ZEROS
    for example : 100 * 100 = 010000

6. Solving both issues :
    1. simply reverse the result string
    2. for loop beginning to end 
        and if u get a non zero value value in string, return the substring of result from that index.

7. if you reach here means all digits are zero so return 0.



 
*/