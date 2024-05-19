// https://leetcode.com/problems/happy-number/description/


/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
*/


/*
Approach - So the Key Point to know is that since we are squaring the digit and adding them infinitely, at some point the number will repeat
and once it does it will form a closed cycle,
for example even if we get "1" its squared and adding will give "1" again and will keep on going there will be a cycle of repeation

So the Main and simple approach is to store all the previously visited numbers and check if we are revisiting any of them
once we do revisit a previous visited number we know there is a cycle of same numbers now 
so just check if the current number which is repeated 1st is a "1" or any other number

Flow : 
    1. make a function "solve" to calculate the sum of squares of the given number
    2. Now in main function suppose we have int "n" :
        1. Make a unordered set
        2. loop until n is already in the set :
            1. enter current "n" in the set
            2. calculate new "n" using solve function
        3. Once out of loop :
            check if "n" is equal to 1, if it is then return true
            else return false
*/