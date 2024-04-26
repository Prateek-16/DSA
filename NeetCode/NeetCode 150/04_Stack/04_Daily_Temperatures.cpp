//https://leetcode.com/problems/daily-temperatures/description/


/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
*/


/*
Approach - Simple use stack to find next greatest element
Flow : 
    1. Make a stack to store indexes
    2. Make a answer vector with size n and all values 0
    3. Now loop from n-1 to 0 in the given array
        1. while the value at stack top index is less that the current looping index value , pop it
        2. Now we know the stack top is greater than the current looping index or the stack is empty
        3. if stack is empty : push the current looping index into the stack
        4. if not then store the (stack top index - current index) in the ans array as the next greatest element 
        and also push the current index in the stck.
    4. thats it !


*/