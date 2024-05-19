//https://leetcode.com/problems/plus-one/description/


/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/


/*
Appraoch - I found it Myself So its not the Best, Neetcode has a nicer way of doing it... But the Time complexity is the same ie O(n).
So we need to increacement the number by 1.

So there are 2 Possible cases :
    1. all the digits are 9 : in this case we need to change the first digit to a 1 all other to 0, and add another 0 at end
    2. all are not 9 : In this we need to start from the end and mentain a carry(intially 1) and start replacing the digits by adding carry to them.
                    once the carry is 0 we break the loop

So to handle the cases, i used a Flag which tells if all digits are 9 or not
    case 1 is easy to handle
    case 2:
        1. Intialize a carry as 1
        2. loop will start from end to 0th index :
            calculate curr digit ie digits[i] + carry
            digits[i] = curr digit % 10
            carry = digit / 10
            once carry is 0 we break the loop

Neetcode has a much simpler way to code this same approach 

*/